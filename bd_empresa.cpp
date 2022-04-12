#include <mysql.h>
#include <iostream>

using namespace std;

class conex
{
	private: mysql* conectar;
	public : void abrir_conex()	{
		conectar = mysql_int(0);

		conectar =mysql_real_connect(conectar,"localhost","usr_empresa","bdempresa", "canella","bdempresa",3306,NULL,0);
	}
		MYSQL* getConetar(){
		return conectar;
	}
	void cerrar_conex(){
		mysql_close(conectar);
	}

};