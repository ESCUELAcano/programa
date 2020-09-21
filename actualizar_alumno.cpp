#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <fstream>
using namespace std;

void actualizar_alumno(string Nombre, string ApellidoP, string ApellidoM, string Direccion, string CURP, string Fechanacimiento, string PadreTutor, string DGrupo) {
	/*Nombre: ACTUALIZAR_ALUMNO 
	Flujo de entrada:  
	Flujo 01: generales_alumno 
	Composición: Nombre, ApellidoP, ApellidoM, Direccion, Curp, Fechanacimiento, PadreTutor, Dgrupo. 
	Flujo de salida:  
	Flujo 01: personales_alumno.  
	Tipo: Registro de Tabla Alumno */
	/*VARIABLES*/
	MYSQL* coneccion;
	ifstream archivoSQL{ "SCRIPTS/llamarActualizarAlumno.sql" };
	string ejecutarScript{ istreambuf_iterator<char>(archivoSQL), istreambuf_iterator<char>() };
	string::size_type pos;
	const char* _alumno;
	/*COMIENZA*/
	coneccion = mysql_init(0);
	if (coneccion) {
		coneccion = mysql_real_connect(coneccion, "bj42twrs4vaqpd6iosvg-mysql.services.clever-cloud.com", "uw77bf6ikf5zyq1n", "q8apKjoZ8H2sR6PI2ZI2", "bj42twrs4vaqpd6iosvg", 3306, NULL, 0);
	}
	//REMPLAZAR NOMBRE
	pos = ejecutarScript.find("nombre01", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("nombre01").length(), "\'" + Nombre + "\'");
	}
	//TERMINA REMPLAZAR NOMBRE
	//REMPLAZAR APELLIDO PATERNO
	pos = ejecutarScript.find("apellidoP01", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("apellidoP01").length(), "\'" + ApellidoP + "\'");
	}
	//TERMINA REMPLAZAR APELLIDO PATERNO
	//REMPLAZAR APELLIDO MATERNO
	pos = ejecutarScript.find("apellidoM01", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("apellidoM01").length(), "\'" + ApellidoM + "\'");
	}
	//TERMINA REMPLAZAR APELLIDO MATERNO
	//REMPLAZAR DIRECCION
	pos = ejecutarScript.find("direccion01", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("direccion01").length(), "\'" + Direccion + "\'");
	}
	//TERMINA REMPLAZAR DIRECCION
	//REMPLAZAR CURP
	pos = ejecutarScript.find("curp01", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("curp01").length(), "\'" + CURP + "\'");
	}
	//TERMINA REMPLAZAR CURP
	//REMPLAZAR FECHANACIMIENTO
	pos = ejecutarScript.find("fechaNacimiento01", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("fechaNacimiento01").length(), "\'" + Fechanacimiento + "\'");
	}
	//TERMINA REMPLAZAR FECHANACIMIENTO
	//REMPLAZAR PADRETUTOR
	pos = ejecutarScript.find("padreTutor01", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("padreTutor01").length(), "\'" + PadreTutor + "\'");
	}
	//TERMINA REMPLAZAR PADRETUTOR
	//REMPLAZAR DGRUPO
	pos = ejecutarScript.find("DGrupo01", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("DGrupo01").length(), "\'" + DGrupo + "\'");
	}
	//TERMINA REMPLAZAR DGRUPO
	_alumno = ejecutarScript.c_str();
	mysql_query(coneccion, _alumno);
	mysql_close(coneccion);
}