#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <fstream>
using namespace std;

void borrar_profesor(string clave_profe_borrar) {

	MYSQL* coneccion;
	ifstream archivoSQL{ "SCRIPTS/llamarBorrarProfesor.sql" };
	string ejecutarScript{ istreambuf_iterator<char>(archivoSQL), istreambuf_iterator<char>() };
	string::size_type pos;
	const char* _alumno_borrar;
	//COMIENZA
	coneccion = mysql_init(0);
	if (coneccion) {
		coneccion = mysql_real_connect(coneccion, "bj42twrs4vaqpd6iosvg-mysql.services.clever-cloud.com", "uw77bf6ikf5zyq1n", "q8apKjoZ8H2sR6PI2ZI2", "bj42twrs4vaqpd6iosvg", 3306, NULL, 0);
	}

	//REMPLAZAR Clave alumno borrar
	pos = ejecutarScript.find("clave_borrar_alumno", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("clave_borrar_alumno").length(), "\'" + clave_alumno_borrar + "\'");
	}
	//TERMINA REMPLAZAR Clave alumno borrar
	
	archivoSQL.close();
	_alumno_borrar = ejecutarScript.c_str();
	mysql_query(coneccion, _alumno_borrar);
	//TERMINA
}