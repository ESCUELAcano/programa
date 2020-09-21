#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include "generar_lista_mensual.h"
#include "generar_lista_grupo.h"
#include "generar_lista_profesores.h"
#include "borrar_alumno.h"
#include "actualizar_alumno.h"
#include "borrar_profesor.h"
using namespace std;
int main(int argc, char** argv){
	borrar_profesor("13467958");
	return 0;
}
