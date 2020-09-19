#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <fstream>
using namespace std;

void registrar_alumno(string Nombre, string ApellidoP, string ApellidoM, string Direccion, string CURP, string Fechanacimiento, string PadreTutor, string DGrupo) {
	/*Nombre: REGISTRAR_ALUMNO
	FLUJOS DE ENTRADA:
	FLUJO 01: generales_alumno
	Composición: nombre+ApellidoP+ApellidoM+Direccion+CURP+Fechanacimiento+PadreTutor+DGrupo
	Flujo de salida: */
	/*VARIABLES*/
	MYSQL* coneccion;
	ifstream archivoSQL{ "SCRIPTS/llamarProcesoRegistrarAlumno.sql" };
	string ejecutarScript{ istreambuf_iterator<char>(archivoSQL), istreambuf_iterator<char>() };
	string::size_type pos;
	const char* _alumno;
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
	//REMPLAZAR DIRECCION
	pos = ejecutarScript.find("Direccion", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Direccion").length(), "\'" + ApellidoM + "\'");
	}
	//TERMINA REMPLAZAR DIRECCION
	//REMPLAZAR CURP
	pos = ejecutarScript.find("CURP", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("CURP").length(), "\'" + CURP + "\'");
	}
	//TERMINA REMPLAZAR CURP
	//REMPLAZAR FECHANACIMIENTO
	pos = ejecutarScript.find("Fechanacimiento", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Fechanacimiento").length(), "\'" + Fechanacimiento + "\'");
	}
	//TERMINA REMPLAZAR FECHANACIMIENTO
	//REMPLAZAR PADRETUTOR
	pos = ejecutarScript.find("PadreTutor", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("PadreTutor").length(), "\'" + PadreTutor + "\'");
	}
	//TERMINA REMPLAZAR PADRETUTOR
	//REMPLAZAR DGRUPO
	pos = ejecutarScript.find("DGrupo", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("DGrupo").length(), "\'" + DGrupo + "\'");
	}
	//TERMINA REMPLAZAR DGRUPO
	_alumno = ejecutarScript.c_str();
	mysql_query(coneccion, _alumno);
}