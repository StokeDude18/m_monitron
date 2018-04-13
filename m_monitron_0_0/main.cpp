#include "m_monitron_0_0.h"
#include <QApplication>
#include "communication.h"
#include "DBAccess.h"
#include "module.h"
#include <vector>
#include <QTimer>

//#define DEBUG 			//Pour affichage dans terminal

/* VARIABLES GLOBALES */
//communication série
int serial = -1;
struct termios options;

uint8_t trame_tx[NB_TRAME] = {0};	//buffer trame de transmission
uint8_t trame_rx[NB_TRAME] = {0}; 	//buffer trame de reception
uint8_t buffer_traitement[NB_TRAME] = {0}; //buffer dans lequel les données reçus sont transférées pour analyse
string modules_Name[NB_MODULE];			//Noms des modules
int8_t nb_Module = -1;

bool end_fonct0 = false;
uint8_t t= 0; //temps écoulé
uint8_t previousFunct = 0;
uint8_t receivedFunction = 0;
int previousPos = -1;

bool read_Flag = false;					

//Chaînes d'entrée de données pour la BD
string dataloginElements = "(ID BIGINT(20) AUTO_INCREMENT, Date_Heure TIMESTAMP DEFAULT CURRENT_TIMESTAMP, Lecture FLOAT, Consigne FLOAT, PRIMARY KEY (ID));";
string eventloginElements = "(ID BIGINT(20) AUTO_INCREMENT, Date_Heure TIMESTAMP DEFAULT CURRENT_TIMESTAMP, Alarmes TINYINT UNSIGNED, PRIMARY KEY (ID));";

//Noms de fichiers SQL utilisés dans la BD
string dataLogin = "data_login";
string eventLogin = "event_login";

module m; //objet de type module

//Liste de modules/ID sur le réseau CAN
vector<module> v_mod;


int noReceiveCount = 0;

m_monitron_0_0 *wpointer; //Pointeur d'objet m_monitron_0_0
//QTimer *timer = new QTimer(this);


DBAccess db; //Objet pour l'accès à la base de données

//Point d'entrée du programme
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    m_monitron_0_0 w;	//Objet m_monitron_0_0 pour fenêtre principale

    //m = new module();
    w.show();//Affiche le cadre de la fenêtre principale

    //m = new module();
    //cout << "Init" << endl; //Ligne de debug

    pthread_t thread_Receive, thread_Main; //Objets pour la création des deux threads générés par le main
    //Configuration de la communication série   
    serial = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY); //Ouverture du port série
    if(serial == -1)//Si erreur dans l'ouverture
    {
        printf("ERROR");
        while(serial == -1)
        {
            usleep(1000000);
            serial = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY); //Ouverture du port série
        }
    }
    tcgetattr(serial, &options);
    options.c_cflag = B115200 | CS8 | CLOCAL | CREAD; //configuration du baud rate
    options.c_iflag = IGNPAR; //ignorer erreur de parité
    options.c_oflag = 0; //raw output
    options.c_lflag = 0; //echo off, non-canonical
    //options.c_cc[VMIN] = 0;//Read non blocant
    //options.c_cc[VTIME] = 2;//200 ms read timout

    //flush pour activer les settings du port
    tcflush(serial, TCIFLUSH);
    tcsetattr(serial, TCSANOW, &options);



    wpointer = &w; //Pointeur vers la fenêtre principale
    pthread_create(&thread_Receive, NULL, do_Receive, (void*)NULL);	//thread de reception des trames
    send_Fonction(0,0); //Envoi de la fonction d'acquisition des modules sur le bus can
    pthread_create(&thread_Main,NULL, mainTask, (void*)NULL); //Création du thread de logique principal


    return a.exec(); //Exécution de la boucle principale faisant la gestion de la fenêtre
}


//Thread de traitement des données reçues
void *mainTask(void *args)
{
    module tempMod;
    int mod_Detect = 0;
    //m.moduleCounter = 0;
    while(1)
    {
        while(!read_Flag);//Attend une réception complète d'une trame
        read_Flag = false;//Remet le flag à 0 pour prochaine analyse

        switch(buffer_traitement[r_fonction])
        {
        case 0:

            mod_Detect = 0;

            m.fillObjectParams(buffer_traitement, buffer_traitement[r_fonction]); //Parsing des données reçues et modification des paramètres de l'objet module.
            usleep(100000); // Délai d'exécution
            for(auto &it_mod : v_mod)//Pour chaque module connu
            {
                if(buffer_traitement[r_pos] == it_mod.Position && v_mod.size() > 0)//Vérifie si la réponse provenait d'un module connu
                    mod_Detect = 1;
            }
            if(mod_Detect == 0 && m.ID != 0)//Si module inconnu, l'ajoute à sa liste
            {
                v_mod.push_back(module(buffer_traitement));//Ajoute un objet module au vecteur
                wpointer->addModuleToMenu(m.ID);//Ajoute l'ID du nouveau module au combo box de la fenêtre principale
            }

            usleep(100000); // Délai d'exécution
            if(v_mod.size() > 0)
                wpointer->printParams(&v_mod[0], buffer_traitement[r_fonction]); //Affichage des nouveaux paramètres dans le fenêtre principale
            previousFunct = 0;

            break;
        case 1:
        case 2:

            m.fillObjectParams(buffer_traitement, buffer_traitement[r_fonction]); //Parsing des données reçues et modification des paramètres de l'objet module.

            usleep(100000); // Délai d'exécution (Opérations dans l'objet module)
            wpointer->printParams(&m, buffer_traitement[r_fonction]); //Affichage des nouveaux paramètres dans le fenêtre principale
            break;
        case 3:
            wpointer->setNextFunction(1);//À l'édition des paramètres, redemande au module sa configuration complète
            break;
        }

        tcflush(serial, TCIOFLUSH);//Vide les buffers d'envoi/réception
        usleep(1000000);  //Délai d'exécution (1s entre les envois)

        if(wpointer->getNextFunction() != 0)
            send_Fonction(v_mod[wpointer->getNextActiveModule()].Position, wpointer->getNextFunction()); //Demande à la fenêtre principale la prochaine requete à faire

        if(previousFunct == 3)//Délai supplémentaire lors de l'édition des paramètres pour permettre au MBED de faire l'écriture dans la carte SD
            usleep(1000000);
    }
}

/**
* @brief Thread de reception des trames sur le port série
* @param pointeur d'objet recu lors de la création du thread (inutilisé dans notre cas)
**/
void *do_Receive(void *args)
{
    int error_count = 0;

    while(1)
    {
       usleep(100000);//100msec
       if(serial!=-1) //Si port série ouvert correctement
       {
           int rx_length = read(serial, (void*)trame_rx, NB_TRAME -1); //Lecture sur le port série 
           trame_rx[rx_length] = 0;
           usleep(trame_rx[rx_length] * 100);//100000);


           if(rx_length > 0)
           {
               noReceiveCount = 0;
               if(!read_Flag) //aucune analyse en cours
               {
                   if(trame_rx[r_soh] == 123) //bon SOH
                   {

                       //read_Flag = true;
                       usleep(/*trame_rx[rx_length * 100]*/100000);

                       if(trame_rx[trame_rx[r_size]-2] == calcul_Checksum(trame_rx, trame_rx[r_size])) //Si checksum valide
                       {
                           error_count = 0;

                           for(int i = 0; i < trame_rx[r_size]; i++)//Copie du contenu reçu dans un buffer de traitement
                               buffer_traitement[i] = trame_rx[i];

                           #ifdef DEBUG //Pour affichage dans terminal
                           print_RX();
                           #endif

                           clear_RX();//Clear le contenu du buffer de réception


                           read_Flag = true; //analyser la trame reçue
                           //parseData(buffer_traitement);
                           t = 0; //remise du temps à zéro
                       }
                       /*else
                           read_Flag = true; //analyser la trame reçue*/
                   }
                   else//Checksum invalide
                   {
                       clear_RX(); //Si checksum invalide, vide le buffer de réception
                       error_count++;
                       usleep(1000000);//Délai avant de renvoyer une requête au MBED
                       read_Flag = true; //analyser la trame reçue
                   }
               }
           }
           else
           {
               if(previousFunct == 0)
                noReceiveCount++;
               if(noReceiveCount >= 50)//Quand le timeout de découverte est écoulé, commence la boucle principale d'acquisition
               {
                 wpointer->setNextFunction(2);
                 noReceiveCount = 0;
                 usleep(10000);
                 clear_RX(); //Si checksum invalide, vide le buffer de réception
                 send_Fonction(v_mod[wpointer->getNextActiveModule()].Position, wpointer->getNextFunction()); //Demande à la fenêtre principale la prochaine requete à faire
               }
           }
       }
   } //while(1)
}

//Fonction d'essai pour remplacer le thread mainTask
//Non fonctionnel pour l'instant
void parseData(uint8_t* data)
{
    int mod_Detect = 0xFF;
    read_Flag = false;
    switch(data[r_fonction])
    {
    case 0:

        for(auto &it_mod : v_mod)
        {
            if(data[r_pos] == it_mod.Position)
                mod_Detect = 0;
        }
        if(!mod_Detect)
        {
            v_mod.push_back(module(data));

        }
        usleep(10000);
        m.fillObjectParams(data, data[r_fonction]); //Parsing des données reçues et modification des paramètres de l'objet module.

        cout<< dec << data[r_fonction] << endl;
        usleep(100000); // Délai d'exécution
        previousFunct = 0;

        break;
    case 1:
    case 2:
        usleep(10000);
        m.fillObjectParams(data, data[r_fonction]); //Parsing des données reçues et modification des paramètres de l'objet module.
       // wpointer->addModuleToMenu(m.ID);
        cout<< dec << data[r_fonction] << endl;
        usleep(100000); // Délai d'exécution
        wpointer->printParams(&m, data[r_fonction]); //Affichage des nouveaux paramètres dans le fenêtre principale
        break;
    case 3:
        wpointer->setNextFunction(1);
        break;
    }

    tcflush(serial, TCIOFLUSH);
    usleep(1000000);  //Délai d'exécution

    if(previousFunct != 0)
        send_Fonction(0, wpointer->getNextFunction()); //Demande à la fenêtre principale la prochaine requete à faire

    usleep(100000); //100ms

    if(previousFunct == 3)
        usleep(1000000);
}

/* Brief:	Fonction d'envoi de requetes/informations au module
 * Params:	pos: 	Position du module dans l'ordre de découverte du PI
 *			fonct:  Fonction que l'on désire envoyer
*/
void send_Fonction(uint8_t pos, uint8_t fonct)
{

    clear_TX();
    if(fonct == 3)//Construction de trame d'envoi pour édition de paramètres du MBED
    {
        trame_tx[t_soh] = T_SOH;
        trame_tx[t_size] = 37;//Longueur de trame
        trame_tx[t_pos] = pos;
        trame_tx[t_fonction] = fonct;
        wpointer->buildF3Frame(trame_tx);
        trame_tx[t3_Checksum] = calcul_Checksum(trame_tx, trame_tx[t_size]);
        trame_tx[t3_Eoh1] = T_EOH1;
        trame_tx[t3_Eoh2] = T_EOH2;

        wpointer->setNextFunction(1);
    }
    else//Construction de trame d'envoi pour une requête au MBED
    {
        trame_tx[t_soh] = T_SOH;
        trame_tx[t_size] = 7;//Longueur de trame
        trame_tx[t_pos] = pos;
        //Si on vient de changer le module courant dans l'interface, redemande au module toutes ses informations (fonction 1)
        trame_tx[t_fonction] = (pos != previousPos && fonct != 0) ? 1 : fonct;
        trame_tx[t_checksum] = calcul_Checksum(trame_tx, trame_tx[t_size]);
        trame_tx[t_eoh1] = T_EOH1;
        trame_tx[t_eoh2] = T_EOH2;

        if(fonct == 1 && previousFunct == 3)
            wpointer->setNextFunction(2);        
    }


  #ifdef DEBUG
  print_TX(); 	//Pour affichage dans le terminal
  #endif

   if (serial != -1)//Si terminal ouvert correctement
   {
       int count = write(serial, &trame_tx[0], trame_tx[t_size]); //Envoi sur Port série
       
	   if(count < 0)	//Si problème lors de l'écriture
           printf("Write Failed.\n");
   }   
   previousFunct = fonct;
   previousPos = pos;
}

/**
* @brief Méthode pour effacer le buffer de reception des trames
**/
void clear_RX()
{
   for(int i=0; i<NB_TRAME; i++)
   {
       trame_rx[i] = 0;//'\0';
   }
}

/**
* @brief Méthode pour effacer le buffer d'envoi des trames
**/
void clear_TX()
{
   for(int i=0; i<NB_TRAME; i++)
   {
       trame_tx[i] = 0;//'\0';
   }
}

/**
* @brief Méthode pour calculer le checksum de la trame reçue
* @param trame[] = la trame à vérifier, t = nombre de char à calculer pour le checksum
* @return le checksum calculé
**/
uint8_t calcul_Checksum(uint8_t* trame, uint8_t t)
{
   uint8_t checksum = 0;
   for(int i=1; i<t-2;i++)
       checksum += trame[i];
   /*printf("checksum reçu: %d\n\r", trame[trame_rx[r_size]-2]);
   printf("checksum calcul: %d\n\r", checksum);*/
   #ifdef DEBUG
   printf("checksum calcul: %d\n\r", checksum);
   #endif
   return checksum & 0xFF;
}


//Affiche le contenu envoyé sur le port série dans le terminal
void print_TX()
{
    cout << "Envoie: ";
    for(int i=0; i<NB_TRAME; i++)
    {
        cout << hex << trame_tx[i] << " ";
    }
    cout << endl;
}

//Affiche le contenu reçu sur le port série dans le terminal
void print_RX()
{
   cout << "Recu: ";
   for(int i=0; i<trame_rx[r_size]; i++)
   {
       cout << dec << trame_rx[i] << " ";
   }
   cout << endl;
}

//Fonction de vérification d'existence d'un nom de table associé à un module 
bool tableVerify(string name)
{
   string* tables = new string[NB_MODULE];
   tables=db.showTable();
   for(int i=0;i<sizeof(tables);i++)
   {
       if(name.compare(tables[i]) == 0) //nom de table existant
           return true;
   }
   return false;    
}


