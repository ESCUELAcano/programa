#ifndef GEN_LISTA_M
#define GEN_LISTA_M
#include <iostream>
typedef struct listaCalMensual {
	std::string rs[100][3];
}listaCalMensual;
struct listaCalMensual generar_lista_mensual(std::string clave_alumno_lista, std::string mes_lista);

#endif