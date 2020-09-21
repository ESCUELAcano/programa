#ifndef CON_PRO
#define CON_PRO
#include <iostream>
typedef struct PROFESOR {
	std::string rs[1][10];
}PROFESOR;
struct PROFESOR CONSULTAR_PROFESORES (std::string Rfc_profesor);

#endif