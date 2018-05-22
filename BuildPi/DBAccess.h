/*	File:	DBAcess.h
 *	Author:	Alfred M.-Quintin
 *	Date:	Feb. 2018
 *
 *	Brief:	Fichier contenant les prototypes des fonctions définies dans
 *			le fichier DBAccess.cpp ainsi que les variables membres de la
 *          classe DBAccess
 *
 */
#ifndef DBACCESS_H
#define DBACCESS_H


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream> //COUT

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
//#include "mysql_driver.h"

using namespace std;


#define NB_MODULE 6

class DBAccess
{
   public:		   	
      DBAccess();
		//bool connexionDB(string m_sDB);	
		int createTable(string dataBase, string table, string elements);
		/*void setConsigne(float consigne);*/
		int ecrireDBdata(string table, float lecture, float m_sConsigne);
		int ecrireDBevent(string table, int8_t alarm);
		//int lireDB(string table);
		string* showTable();
		//bool fermeture();*/
    private:	
      //string execute;
    	//string MYSQL = "com.mysql.jdbc.Driver"; //nom du gestionnaire JDBC pour MySQL
    	string m_sHost;//= "127.0.0.1:3306";     //Adresse IP du serveur
    	string m_sLogin;//= "phpmyadmin";    //Nom de l'utilisateur
      string m_sPassword;//= "phpmyadmin"; //Mot de passe crypté pour la connexion
      string m_sErreur;   //Erreur possible
      string m_sTable;  //Nom de table
      float m_sConsigne; //Setpoint désiré
      //Connection cCon;
      char command[70];
};
 
#endif // DBACCESS_H
