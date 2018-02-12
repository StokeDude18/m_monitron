#include "m_monitron.h"
#include "DBAccess.h"

/* VARIABLES GLOBALES */
//communication série
int serial = -1;
struct termios options;

char trame_tx[NB_TRAME] = {'\0'}; //buffer trame de transmission
char trame_rx[NB_TRAME] = {'\0'}; //buffer trame de reception
string modules_Name[NB_MODULE];
int8_t nb_Module = -1;
 
bool end_fonct0 = false;
int8_t t= 0; //temps écoulé
bool read_Flag = false;

string dataloginElements = "(ID BIGINT(20) AUTO_INCREMENT, Date_Heure TIMESTAMP DEFAULT CURRENT_TIMESTAMP, Lecture FLOAT, Consigne FLOAT, PRIMARY KEY (ID));";
string eventloginElements = "(ID BIGINT(20) AUTO_INCREMENT, Date_Heure TIMESTAMP DEFAULT CURRENT_TIMESTAMP, Alarmes TINYINT UNSIGNED, PRIMARY KEY (ID));";

string dataLogin = "data_login";
string eventLogin = "event_login";

DBAccess db;

int main (int argc, char *argv[])
{
	pthread_t thread_Receive;
	//Configuration de la communication série
	serial = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NDELAY); //read non bloquant
	if(serial == -1)
	{
		printf("ERROR");
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
	
	send_Fonction(0,0); //fonction 0
	
	while(1)
	{
		usleep(100000); //100ms
		t++;
		while(!end_fonct0)
		{
			if(t <= BROADCAST_TIME)
				end_fonct0 = true;
		}
	}
}

 /**
 * @brief Méthode principale du thread de reception des trames sur le port série
 * @param pointeur d'objet recu lors de la création du thread (non utiliser dans notre cas)
 **/
void *do_Receive(void *args)
{
        while(1)
	{
		usleep(1000000);//1sec
		if(serial!=-1)
		{
			int rx_length = read(serial, (void*)trame_rx, NB_TRAME -1);
			trame_rx[rx_length] = 0;
			if(rx_length < 0)
			{
				//error, (there are no bytes)	
			} 
			else if(rx_length == 0)
			{
				//il n'y a pas de data en attente
			}
			else
			{
				if(!read_Flag) //aucune analyse en cours
				{
					if(trame_rx[0] == 123) //bon SOH
					{
						//read_Flag = true;
						if(trame_rx[rx_length-2] == calcul_Checksum(trame_rx, rx_length)) //bon checksum
						{
							#ifdef DEBUG
							print_RX();
							#endif
							read_Flag = true; //analyser la trame recu
							t = 0; //remise du temps à zéro
						}
						
					}
					else
						clear_RX();
				}
				
			}
			//tcflush(serial, TCIFLUSH);
		} 
	} //while(1)
}

 /**
 * @brief Méthode principale du thread d'analyse de la trame recu, met à jour les valeurs enregistrées du module d'acquisition
 * @param pointeur d'objet recu lors de la création du thread (non utiliser dans notre cas)
 **/
void *do_Analyse(void* args)
{
	while(1)
	{
		if(read_Flag)//trame à analyser
		{
			switch(trame_rx[r_fonction])
			{
				case BROADCAST:
                                /*if()
                                        t = 0;*/
				break;				
			};
		}
	}
}

void send_Fonction(int8_t pos, int8_t fonct)
{
	trame_tx[t_soh] = T_SOH;
	trame_tx[t_size] = 7;
   trame_tx[t_pos] = pos;
   trame_tx[t_fonction] = fonct;
   trame_tx[t_checksum] = calcul_Checksum(trame_tx, trame_tx[t_size]);
   trame_tx[t_eoh1] = T_EOH1;
   trame_tx[t_eoh2] = T_EOH2;
   
   #ifdef DEBUG
   print_TX();
   #endif
   
	if (serial !=-1)
	{
		int count = write(serial, &trame_tx[0], NB_TRAME);
		if(count < 0)
			printf("FAILED WRITE");
	}
}

 /**
 * @brief Méthode pour effacer le buffer de reception des trames
 **/
void clear_RX()
{
	for(int i=0; i<NB_TRAME; i++)
	{
		trame_rx[i] = -1;//'\0';
	}
}

 /**
 * @brief Méthode pour calculer le checksum de la trame recu
 * @param trame[] = la trame à vérifier, t = nombre de char à calculer pour le checksum
 * @return le checksum calculé
 **/
char calcul_Checksum(char trame[], char t)
{
	char checksum = 0;
	for(int i=1; i<t-2;i++)
		checksum += trame[i];
	
	#ifdef DEBUG
	printf("checksum calcul: %d\n\r", checksum);
	#endif
	return checksum;
}

void print_TX()
{
	printf("Envoie: ");
	for(int i=0; i<NB_TRAME; i++)
	{
		printf("%d ", trame_tx[i]);
	}
	printf("\n");
}

void print_RX()
{
	printf("Recu: ");
	for(int i=0; i<NB_TRAME; i++)
	{
		printf("%d ", trame_rx[i]);
	}
	printf("\n");
}

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
		//cout << tables[i] << endl;
}
