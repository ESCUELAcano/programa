#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include "generar_lista_mensual.h"
using namespace std;
int main(int argc, char* argv[]) {
	/*VARIABLES*/
	/*COMIENZA*/
	struct listaCalMensual a;
	a = generar_lista_mensual("AECJ940429HCHRRS01", "08");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout<<a.rs[i][j];
		}
		cout << endl;
	}
	return 0;
	/*TERMINA*/
}