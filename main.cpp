#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include "generar_lista_mensual.h"
using namespace std;
int main(int argc, char* argv[]) {
	/*VARIABLES*/
	string Nombre = "Alexis";
	string ApellidoP = "Bonilla";
	string ApellidoM = "Acevedo";
	string Credencial = "IGHS72E";
	/*COMIENZA*/
	generar_lista_mensual("AECJ940429HCHRRS01", "07");
	return 0;
	/*TERMINA*/
}