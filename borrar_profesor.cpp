#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <fstream>
#include "borrar_profesor.h"
using namespace std;

void borrar_profesor(string clave_profe_borrar) {

	MYSQL* coneccion;
	ifstream archivoSQL{ "SCRIPTS/llamarEliminarProfesor.sql" };
	string ejecutarScript{ istreambuf_iterator<char>(archivoSQL), istreambuf_iterator<char>() };
	string::size_type pos;
	const char* _profesor_borrar;
	//COMIENZA
	coneccion = mysql_init(0);
	if (coneccion) {
		coneccion = mysql_real_connect(coneccion, "bj42twrs4vaqpd6iosvg-mysql.services.clever-cloud.com", "uw77bf6ikf5zyq1n", "q8apKjoZ8H2sR6PI2ZI2", "bj42twrs4vaqpd6iosvg", 3306, NULL, 0);
	}

	//REMPLAZAR Clave alumno borrar
	pos = ejecutarScript.find("CedulaProfesor", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("CedulaProfesor").length(), clave_profe_borrar);
	}
	//TERMINA REMPLAZAR Clave alumno borrar
	
	archivoSQL.close();
	_profesor_borrar = ejecutarScript.c_str();
	mysql_query(coneccion, _profesor_borrar);
	//TERMINA
}