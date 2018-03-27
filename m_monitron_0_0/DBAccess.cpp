#include "DBAccess.h"
#include <boost/lexical_cast.hpp>

//Constructeur
 DBAccess::DBAccess()
 {
 	m_sHost= "127.0.0.1:3306";     //Adresse IP du serveur
    m_sLogin= "root";    //Nom de l'utilisateur //"phpmyadmin";//"
    m_sPassword= "Aquab10T3ch"; //Mot de passe crypté pour la connexion//"phpmyadmin";//
   
 }
 /*bool DBAccess::connexionDB(string m_sDB)
 {} */
 int DBAccess::createTable(string dataBase, string table, string elements)
 {
 	try
 	{
 		sql::Driver *driver;
 		sql::Connection *con;
 		sql::Statement *stmt;
 		//sql::ResultSet *res;
 		//creation de la connexion 
		driver = get_driver_instance();
		con = driver->connect(m_sHost, m_sLogin, m_sPassword);
		
		//Connexion à la database
		con->setSchema(dataBase);

		//création de la table
		stmt = con->createStatement();
		stmt->execute("CREATE TABLE " + table+ " "+ elements);
		delete stmt;
		delete con;		
 	}
 	catch(sql::SQLException &e)
 	{
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
	return EXIT_FAILURE;
	
 /*	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect(m_sHost, m_sLogin, m_sPassword);*/
 } 
 /*void DBAccess::setConsigne(float consigne)
 {} */
 int DBAccess::ecrireDBdata(string table, float lecture, float m_sConsigne)
 {
 	//char str[100];
 	try
 	{
 		sql::Driver *driver;
 		sql::Connection *con;
 		sql::Statement *stmt;

 		//creation de la connexion 
		driver = get_driver_instance();
		con = driver->connect(m_sHost, m_sLogin, m_sPassword);
 		//Connexion à la database
		con->setSchema("data_login");

		/*cout << table << endl;
		cout << lecture << endl;
		cout << m_sConsigne << endl;*/
		stmt = con->createStatement();
		snprintf(command, sizeof(command), "INSERT INTO %s(Lecture, Consigne) VALUES ('%f','%f');", table.c_str(), lecture, m_sConsigne);
		cout << command << endl;		
		//execute = string(str);
		//cout << execute << endl;
		stmt->execute(command);

 		delete stmt;
		delete con;	
 	}
 	catch(sql::SQLException &e)
 	{
 		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
 	}
 	return EXIT_FAILURE;
 } 

 /**
 * @brief  Écriture d'évènement dans la base de données (les alarmes)
 */
 int DBAccess::ecrireDBevent(string table, int8_t alarm)
 {
 	//char str[50];
 	try
 	{
 		sql::Driver *driver;
 		sql::Connection *con;
 		sql::Statement *stmt;

 		//creation de la connexion 
		driver = get_driver_instance();
		con = driver->connect(m_sHost, m_sLogin, m_sPassword);
 		//Connexion à la database
		con->setSchema("event_login");

		stmt = con->createStatement();
		snprintf(command, sizeof(command),"INSERT INTO %s(Alarmes) VALUES ('%d');", table.c_str(), alarm);
		//execute = string(command);

		stmt->execute(command);

 		delete stmt;
		delete con;	
 	}
 	catch(sql::SQLException &e)
 	{
 		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
 	}
 	return EXIT_FAILURE;
 } 

 /*int DBAccess::lireDB(string table)
 {
 	
 	//("SELECT * FROM "+ table + " WHERE ID=(SELECT MAX(ID) FROM "+ table + ");");
 } */
 
string* DBAccess::showTable()
 {
 	string* result = new string[NB_MODULE];
 	try
 	{
 		sql::Driver *driver;
 		sql::Connection *con;
 		sql::Statement *stmt;
 		sql::ResultSet  *res;

 		//creation de la connexion 
		driver = get_driver_instance();
		con = driver->connect(m_sHost, m_sLogin, m_sPassword);
 		//Connexion à la database
		con->setSchema("data_login");
		stmt = con->createStatement();
		res = stmt->executeQuery("SHOW TABLES");// IN data_login" );
		//int num = res->rowsCount();
		//cout << num <<endl;
		int i = 0;
		while(res->next())
		{
			result[i]=res->getString(1);
		//	cout << result[i] << endl;
			i++;
			//cout << res->getString(1) << endl;
		}
		
 		delete stmt;
		delete con;	
		delete res;

		return result;
 	}
 	catch(sql::SQLException &e)
 	{
 		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
 	}
 	return result;
 } 
 /*bool DBAccess::fermeture()
 {} */
