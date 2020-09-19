#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <fstream>
using namespace std;

void registrar_tutor(string Nombre, string ApellidoP, string ApellidoM, string Credencial) {
	/*NOMBRE REGISTRAR_TUTORES
	FLUJOS DE ENTRADA:
	FLUJO 01: generales_tutor
	COMPOSICION: Nombre:CADENA,ApellidoP:CADENA,ApellidoM:CADENA,Credencial:CADENA
	VARIABLES*/
	MYSQL* coneccion;
	ifstream archivoSQL{ "SCRIPTS/llamarProcesoRegistrarTutor.sql" };
	string ejecutarScript{ istreambuf_iterator<char>(archivoSQL), istreambuf_iterator<char>() };
	string::size_type pos;
	const char* _tutor;
	/*COMIENZA*/
	coneccion = mysql_init(0);
	if (coneccion) {
		coneccion = mysql_real_connect(coneccion, "bj42twrs4vaqpd6iosvg-mysql.services.clever-cloud.com", "uw77bf6ikf5zyq1n", "q8apKjoZ8H2sR6PI2ZI2", "bj42twrs4vaqpd6iosvg", 3306, NULL, 0);
	}
	//REMPLAZAR NOMBRE
	pos = ejecutarScript.find("Nombre", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Nombre").length(), "\'" + Nombre + "\'");
	}
	//TERMINA REMPLAZAR NOMBRE
	//REMPLAZAR APELLIDO PATERNO
	pos = ejecutarScript.find("ApellidoP", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("ApellidoP").length(), "\'" + ApellidoP + "\'");
	}
	//TERMINA REMPLAZAR APELLIDO PATERNO
	//REMPLAZAR APELLIDO MATERNO
	pos = ejecutarScript.find("ApellidoM", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("ApellidoM").length(), "\'" + ApellidoM + "\'");
	}
	//TERMINA REMPLAZAR APELLIDO MATERNO
	//REMPLAZAR CREDENCIAL
	pos = ejecutarScript.find("Credencial", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Credencial").length(), "\'" + Credencial + "\'");
	}
	//TERMINA REMPLAZAR CREDENCIAL

	archivoSQL.close();
	_tutor = ejecutarScript.c_str();
	mysql_query(coneccion, _tutor);
}