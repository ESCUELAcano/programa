#ifndef GEN_LISTA_G
#define GEN_LISTA_G
#include <iostream>
typedef struct listaGrupo {
	std::string rs[100][4];
}listaGrupo;
struct listaGrupo generar_lista_grupo(std::string clave_grupo);

#endif