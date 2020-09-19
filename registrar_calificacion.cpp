#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <fstream>
using namespace std;

void registrar_calificacion(string Curp, string Calificacion, string Fecha) {
	/*VARIABLES*/
	MYSQL* coneccion;
	ifstream archivoSQL{ "SCRIPTS/llamarProcesoRegistrarCalificacion.sql" };
	string ejecutarScript{ istreambuf_iterator<char>(archivoSQL), istreambuf_iterator<char>() };
	string::size_type pos;
	const char* _calificacion;
	/*COMIENZA*/
	coneccion = mysql_init(0);
	if (coneccion) {
		coneccion = mysql_real_connect(coneccion, "bj42twrs4vaqpd6iosvg-mysql.services.clever-cloud.com", "uw77bf6ikf5zyq1n", "q8apKjoZ8H2sR6PI2ZI2", "bj42twrs4vaqpd6iosvg", 3306, NULL, 0);
	}
	//REMPLAZAR CURP
	pos = ejecutarScript.find("CURP", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("CURP").length(), "\'" + Curp + "\'");
	}
	//TERMINA REMPLAZAR CURP

	//REMPLAZAR Calificacion
	pos = ejecutarScript.find("Calificacion", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Calificacion").length(), Calificacion);
	}
	//TERMINA REMPLAZAR Calificacion

	//REMPLAZAR Fecha
	pos = ejecutarScript.find("Fecha", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Fecha").length(), "\'" + Fecha + "\'");
	}
	//TERMINA REMPLAZAR Fecha
	_calificacion = ejecutarScript.c_str();
	mysql_query(coneccion, _calificacion);
}