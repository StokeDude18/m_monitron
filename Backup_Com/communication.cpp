#include "communication.h"

#include <pthread.h> //pour thread
#include <stdio.h>
#include <unistd.h> //UART
#include <fcntl.h> //UART
#include <termios.h> //UART
#include <iostream> //COUT
#include <string>

using namespace std;



Communication::Communication()
{
    read_Flag = false;
}

void Communication::Start_Rx()
{

    //Configuration de la communication série
    serial = open("/dev/serial0", O_RDWR | O_NOCTTY );//| O_NDELAY);
    if(serial == -1)
    {
        printf("ERROR");
    }
    struct termios options;
    tcgetattr(serial, &options);
    options.c_cflag = B115200 | CS8 | CLOCAL | CREAD; //configuration du baud rate
    options.c_iflag = IGNPAR; //ignorer erreur de parité
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(serial, TCIFLUSH);
    tcsetattr(serial, TCSANOW, &options);

    pthread_create(&thread_Receive, NULL, Communication::do_Receive, (void*)NULL);
    pthread_create(&thread_Analyse, NULL, Communication::do_Analyse, (void*)NULL);
    //std::thread objReceive(do_Receive);
}



void Communication::Request(int Function)
{
    switch(Function)
    {
    case 0:
        position = trame_rx[2];
        ID.b[0] = trame_rx[3];
        ID.b[1]= trame_rx[4];
        ID.b[2]= trame_rx[5];
        ID.b[3]= trame_rx[6];
        type = trame_rx[7];
        cout << "position : " << position << endl;
        cout << "ID: " << ID.i << endl;
        cout << "Type: " << module[type] << endl;
        break;
    case 1:
        break;
    case 2:
        //print_RX();
        lecture.b[0] = trame_rx[9];
        lecture.b[1] = trame_rx[10];
        lecture.b[2] = trame_rx[11];
        lecture.b[3] = trame_rx[12];
        setpoint.b[0] = trame_rx[13];
        setpoint.b[1] = trame_rx[14];
        setpoint.b[2] = trame_rx[15];
        setpoint.b[3] = trame_rx[16];
        alarme = trame_rx[17];
        cout << "Lecture : " << lecture.f << endl;
        cout << "Setpoint: " << setpoint.f << endl;
        cout << "Alarme: " << (int)alarme << endl;
        break;
    }
}

static void* Communication::do_Receive(void *args)
{
    //char receive[NB_TRAME] = {'\0'};
    while(1)
    {
        usleep(2000000);//(2000000);
        if(serial!=-1)
        {
            int rx_length = read(serial, (void*)trame_rx, NB_TRAME);
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
                //printf("%i bytes read \n", rx_length);
                //print_RX();
                if(trame_rx[0] == 123)
                {
                    read_Flag = true;
                }
            }
        }
    } //while(1)
}


static void* Communication::do_Analyse(void *args)
{
    while(1)
    {
        if(read_Flag)
        {
            read_Flag = false; //remise à zéro du flag
            switch(message[0])
            {
                case '0':
                position = trame_rx[2];
                ID.b[0] = trame_rx[3];
                ID.b[1]= trame_rx[4];
                ID.b[2]= trame_rx[5];
                ID.b[3]= trame_rx[6];
                type = trame_rx[7];
                cout << "position : " << position << endl;
                cout << "ID: " << ID.i << endl;
                cout << "Type: " << module[type] << endl;
                break;
                case '1':

                break;
                case '2':
                //print_RX();
                lecture.b[0] = trame_rx[9];
                lecture.b[1] = trame_rx[10];
                lecture.b[2] = trame_rx[11];
                lecture.b[3] = trame_rx[12];
                setpoint.b[0] = trame_rx[13];
                setpoint.b[1] = trame_rx[14];
                setpoint.b[2] = trame_rx[15];
                setpoint.b[3] = trame_rx[16];
                alarme = trame_rx[17];
                cout << "Lecture : " << lecture.f << endl;
                cout << "Setpoint: " << setpoint.f << endl;
                cout << "Alarme: " << (int)alarme << endl;
                break;
            }
        }
    }
}

void Communication::send_Fonction(char nb, char position, char fonction)
{
    char buffer[7] = {SOH, nb, position, fonction, (nb+position+fonction), EOH1, EOH2};
    copy(buffer, buffer+7, trame_tx);
    //print_TX();
    if(serial !=-1)
    {
        int count =  write(serial, &trame_tx[0], NB_TRAME);
        if(count < 0)
            printf("FAILED WRITE");
    }
}

void Communication::clear_TX()
{
    for(int i=0; i<NB_TRAME; i++)
    {
        trame_tx[i] = '\0';
    }
}

char Communication::calcul_Checksum(char trame[], char t)
{
    char checksum = 0;
    for(int i=0; i<t-1;i++)
        checksum += trame[i];
    return checksum;
}

bool Communication::verifTrame(char trame[], int index)
{
    return true;
}

void Communication::print_TX()
{
    printf("Envoie: ");
    for(int i=0; i<NB_TRAME; i++)
    {
        printf("%d ", trame_tx[i]);
    }
    printf("\n");
}

void Communication::print_RX()
{
    printf("Recu: ");
    for(int i=0; i<NB_TRAME; i++)
    {
        printf("%d ", trame_rx[i]);
    }
    printf("\n");
}

