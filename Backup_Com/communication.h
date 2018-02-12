#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <pthread.h> //pour thread
#include <stdio.h>
#include <unistd.h> //UART
#include <fcntl.h> //UART
#include <termios.h> //UART
#include <iostream> //COUT
#include <string>

#define SOH 1
#define EOH1 254
#define EOH2 255
#define NB_TRAME 70

using namespace std;

class Communication
{

public:
    Communication();
    void Start_Rx();
    void Request(int Function);

private:

   /*const int SOH = 1;
    const int EOH1 = 254;
    const int EOH2 = 255;
    const int NB_TRAME = 70;*/

    union float2bytes
    {
       float f;
       char b[sizeof(float)];
    };

    union int2bytes
    {
       int i;
       char b[sizeof(int)];
    };


    static void* do_Receive(void *args);
    static void* do_Analyse(void *args);
    void send_Fonction(char nb, char position, char fonction);
    void clear_TX();
    char calcul_Checksum(char trame[], char t);
    bool verifTrame(char trame[], int index);
    void print_TX();
    void print_RX();

    bool read_Flag;
    char trame_tx[NB_TRAME] = {'\0'}; //buffer trame de transmission
    char trame_rx[NB_TRAME] = {'\0'}; //buffer trame de reception
    int serial;
    string module[6] = {"Temperature", "Oxygene", "Salinite_Conductivite", "PH", "Debit", "Niveau"}; //noms des modules possibles
    string message;
    int type = -1;
    int position = -1;
    string name;
    float2bytes lecture, setpoint;
    int2bytes ID;
    char alarme;
    pthread_t thread_Receive, thread_Analyse;

};

#endif // COMMUNICATION_H
