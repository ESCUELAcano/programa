#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <fstream>
using namespace std;

void inscribir_alumno(string Nombre_grupo, string Curp_alumno) {
	/*VARIABLES*/
	MYSQL* coneccion;
	ifstream archivoSQL{ "SCRIPTS/llamarProcesoIncribirAlumno.sql" };
	string ejecutarScript{ istreambuf_iterator<char>(archivoSQL), istreambuf_iterator<char>() };
	string::size_type pos;
	const char* _Inscribiralumno;
	/*COMIENZA*/
	coneccion = mysql_init(0);
	if (coneccion) {
		coneccion = mysql_real_connect(coneccion, "bj42twrs4vaqpd6iosvg-mysql.services.clever-cloud.com", "uw77bf6ikf5zyq1n", "q8apKjoZ8H2sR6PI2ZI2", "bj42twrs4vaqpd6iosvg", 3306, NULL, 0);
	}
	//REMPLAZAR Nombregrupo
	pos = ejecutarScript.find("Nombregrupo", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Nombregrupo").length(), "\'" + Nombre_grupo + "\'");
	}
	//TERMINA REMPLAZAR Nombregrupo

	//REMPLAZAR Curp_alumno
	pos = ejecutarScript.find("Curp_alumno", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Curp_alumno").length(), "\'" + Curp_alumno + "\'");
	}
	//TERMINA REMPLAZAR Curp_alumno
	_Inscribiralumno = ejecutarScript.c_str();
	mysql_query(coneccion, _Inscribiralumno);
}