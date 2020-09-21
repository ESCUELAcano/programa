#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <fstream>
using namespace std;

void registrar_grupo(STRING nombre,STRING grado,STRING Turno,STRING Profesor) {
/*Nombre: REGISTRAR_GRUPO
FLUJO DE ENTRADA:
FLUJO 08:generales_grupos
Composición: 
nombreCADENA,grado:ENTERO,turno:CADENA,Tutor:CADENA,Profesor:CADENA
Flujo de salida:
 

	VARIABLES*/
	MYSQL* coneccion;
	ifstream archivoSQL{ "SCRIPTS/llamarProcesoRegistrarGrupo.sql" };
	string ejecutarScript{ istreambuf_iterator<char>(archivoSQL), istreambuf_iterator<char>() };
	string::size_type pos;
	const char* _grupo;
	/*COMIENZA*/
	coneccion = mysql_init(0);
	if (coneccion) {
		coneccion = mysql_real_connect(coneccion, "bj42twrs4vaqpd6iosvg-mysql.services.clever-cloud.com", "uw77bf6ikf5zyq1n", "q8apKjoZ8H2sR6PI2ZI2", "bj42twrs4vaqpd6iosvg", 3306, NULL, 0);
	}

	//REMPLAZAR NOMBRE
	pos = ejecutarScript.find("Nombre", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Nombre").length(), "\'" + nombre + "\'");
	}
	//TERMINA REMPLAZAR NOMBRE
	//REMPLAZAR Grado
	pos = ejecutarScript.find("Grado", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Grado").length(), "\'" + grado + "\'");
	}
	//TERMINA REMPLAZAR Grado
	//REMPLAZAR Turno
	pos = ejecutarScript.find("Turno", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Turno").length(), "\'" + Turno + "\'");
	}
	//TERMINA REMPLAZAR Turno
	//REMPLAZAR DProfesor
	pos = ejecutarScript.find("DProfesor", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("DProfesor").length(), "\'" + DProfesor + "\'");
	}
	//TERMINA REMPLAZAR DProfesor
	//REMPLAZAR DTuto
	pos = ejecutarScript.find("DTuto", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("DTuto").length(), "\'" + DTuto + "\'");
	}
	//TERMINA REMPLAZAR DTuto
	archivoSQL.close();
	_grupo = ejecutarScript.c_str();
	mysql_query(coneccion, _grupo);
	/*TERMINA*/
}