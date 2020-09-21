     #include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <fstream>
using namespace std;

void Actualizar_profesor(string Nombre, string ApellidoP, string ApellidoM, string RFC, string FechaNacimiento, string Genero, string CedulaProfesional, string Telefono, string Experiencia) {
	/*FLUJOS DE ENTRADA:
    FLUJO 01: generales_profesor
    COMPOSICION:nombre:CADENA,ApellidoP:CADENA,ApellidoM:CADENA,RFC:CADENA,Fechanacimiento:FECHA,Edad:ENTERO,Genero:CADENA,Cedulaprofesional:ENTERO,Telefono:Entero,Experiencia:CADENA
    FLUJOS DE SALIDA:
    FLUJO 01: personales_profesor: REGISTRO de tabla PROFESOR
    PROCEDIMIENTO ACTUALIZAR_PROFESOR(nombre:CADENA,ApellidoP:CADENA,ApellidoM:CADENA,RFC:CADENA,Fechanacimiento:FECHA,Edad:ENTERO,Genero:CADENA,Cedulaprofesional:ENTERO,Telefono:Entero,Experiencia:CADENA)
	VARIABLES*/

	MYSQL* coneccion;
	ifstream archivoSQL{ "SCRIPTS/llamarActualizarProfesor.sql" };
	string ejecutarScript{ istreambuf_iterator<char>(archivoSQL), istreambuf_iterator<char>() };
	string::size_type pos;
	const char* _profesor;
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
	//REMPLAZAR RFC
	pos = ejecutarScript.find("RFC", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("RFC").length(), "\'" + RFC + "\'");
	}
	//TERMINA REMPLAZAR RFC
	//REMPLAZAR FECHA DE NACIMIENTO
	pos = ejecutarScript.find("FechaNacimiento", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("FechaNacimiento").length(), "\'" + FechaNacimiento + "\'");
	}
	//TERMINA REMPLAZAR FECHA DE NACIMIENTO
	//REMPLAZAR GENERO
	pos = ejecutarScript.find("Genero", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Genero").length(), "\'" + Genero + "\'");
	}
	//TERMINA REMPLAZAR GENERO
	//REMPLAZAR CEDULA PROFECIONAL
	pos = ejecutarScript.find("CedulaProfesional", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("CedulaProfesional").length(), CedulaProfesional);
	}
	//TERMINA REMPLAZAR CEDULA PROFECIONAL
	//REMPLAZAR TELEFONO
	pos = ejecutarScript.find("Telefono", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Telefono").length(), "\'" + Telefono + "\'");
	}
	//TERMINA REMPLAZAR TELEFONO
	//REMPLAZAR EXPERIENCIA
	pos = ejecutarScript.find("Experiencia", 0);
	if (pos < string::npos) {
		ejecutarScript.replace(pos, string("Experiencia").length(), "\'" + Experiencia + "\'");
	}
	//TERMINA REMPLAZAR EXPERIENCIA
	archivoSQL.close();
	_profesor = ejecutarScript.c_str();
	mysql_query(coneccion, _profesor);
	/*TERMINA*/
}