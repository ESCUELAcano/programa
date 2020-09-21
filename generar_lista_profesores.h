#ifndef GEN_LISTA_P
#define GEN_LISTA_P
#include <iostream>
typedef struct listaProfesores {
	std::string rs[100][9];
}listaProfesores;
struct listaProfesores generar_lista_profesores();

#endif