#include "m_monitron_0_0.h"
#include <QApplication>
#include "communication.h"
#include "DBAccess.h"
#include "module.h"
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
int8_t t= 0; //temps écoulé
bool read_Flag = false;					

//Chaînes d'entrée de données pour la BD
string dataloginElements = "(ID BIGINT(20) AUTO_INCREMENT, Date_Heure TIMESTAMP DEFAULT CURRENT_TIMESTAMP, Lecture FLOAT, Consigne FLOAT, PRIMARY KEY (ID));";
string eventloginElements = "(ID BIGINT(20) AUTO_INCREMENT, Date_Heure TIMESTAMP DEFAULT CURRENT_TIMESTAMP, Alarmes TINYINT UNSIGNED, PRIMARY KEY (ID));";

//Noms de fichiers SQL utilisés dans la BD
string dataLogin = "data_login";
string eventLogin = "event_login";

module m; //objet de type module
m_monitron_0_0 *wpointer; //Pointeur d'objet m_monitron_0_0

DBAccess db; //Objet pour l'accès à la base de données

//Point d'entrée du programme
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    m_monitron_0_0 w;	//Objet m_monitron_0_0 pour fenêtre principale

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

    //flush pour activer les settings du port
    tcflush(serial, TCIFLUSH);
    tcsetattr(serial, TCSANOW, &options);

    pthread_create(&thread_Receive, NULL, do_Receive, (void*)NULL);	//thread de reception des trames
    send_Fonction(0,1); //Envoi de la fonction d'acquisition des modules sur le bus can
    pthread_create(&thread_Main,NULL, mainTask, (void*)NULL); //Création du thread de logique principal

    wpointer = &w; //Pointeur vers la fenêtre principale
    return a.exec(); //Exécution de la boucle principale faisant la gestion de la fenêtre
}


void *mainTask(void *args)
{
    while(1)
    {
        while(!read_Flag);
        read_Flag = false;

        usleep(10000);
        m.fillObjectParams(buffer_traitement, buffer_traitement[r_fonction]); //Parsing des données reçues et modification des paramètres de l'objet module.

        usleep(100000); // Délai d'exécution
        wpointer->printParams(&m, buffer_traitement[r_fonction]); //Affichage des nouveaux paramètres dans le fenêtre principale

        clear_TX();
        tcflush(serial, TCIOFLUSH);
        usleep(3500000);  //Délai d'exécution
        send_Fonction(0, wpointer->getNextFunction()); //Demande à la fenêtre principale la prochaine requete à faire
        usleep(1000000); //1s
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
       usleep(1000000);//1sec
       if(serial!=-1) //Si port série ouvert correctement
       {
           int rx_length = read(serial, (void*)trame_rx, NB_TRAME -1); //Lecture sur le port série 
           trame_rx[rx_length] = 0;
           
           if(rx_length > 0)
           {
               if(!read_Flag) //aucune analyse en cours
               {
                   if(trame_rx[r_soh] == 123) //bon SOH
                   {
                       //read_Flag = true;
                       if(trame_rx[rx_length-2] == calcul_Checksum(trame_rx, rx_length)) //Si checksum valide
                       {
                           error_count = 0;
                           for(int i = 0; i < NB_TRAME; i++)
                               buffer_traitement[i] = trame_rx[i];
                           #ifdef DEBUG //Pour affichage dans terminal
                           print_RX();
                           #endif

                           read_Flag = true; //analyser la trame reçue
                           t = 0; //remise du temps à zéro
                       }
                       else
                           read_Flag = true; //analyser la trame reçue
                   }
                   else
                   {
                       clear_RX(); //Si checksum invalide, vide le buffer de réception
                       error_count++;
                       read_Flag = true; //analyser la trame reçue
                   }
               }
           }
       }
   } //while(1)
}

/* Brief:	Fonction d'envoi de requetes/informations au module
 * Params:	pos: 	Position du module dans l'ordre de découverte du PI
 *			fonct:  Fonction que l'on désire envoyer
*/
void send_Fonction(int8_t pos, int8_t fonct)
{
    if(fonct == f3)
    {
        trame_tx[t_soh] = T_SOH;
        trame_tx[t_size] = 36;
        trame_tx[t_pos] = pos;
        trame_tx[t_fonction] = fonct;
        wpointer->buildF3Frame(trame_tx);
        trame_tx[t3_Checksum] = calcul_Checksum(trame_tx, trame_tx[t_size]);
        trame_tx[t3_Eoh1] = T_EOH1;
        trame_tx[t3_Eoh2] = T_EOH2;
    }
    else
    {
        trame_tx[t_soh] = T_SOH;
        trame_tx[t_size] = 7;
        trame_tx[t_pos] = pos;
        trame_tx[t_fonction] = fonct;
        trame_tx[t_checksum] = calcul_Checksum(trame_tx, trame_tx[t_size]);
        trame_tx[t_eoh1] = T_EOH1;
        trame_tx[t_eoh2] = T_EOH2;
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
uint8_t calcul_Checksum(uint8_t* trame, char t)
{
   uint8_t checksum = 0;
   for(int i=1; i<t-2;i++)
       checksum += trame[i];

   #ifdef DEBUG
   printf("checksum calcul: %d\n\r", checksum);
   #endif
   return checksum;
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
   for(int i=0; i<NB_TRAME; i++)
   {
       cout << hex << trame_rx[i] << " ";
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


