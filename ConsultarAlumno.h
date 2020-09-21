#ifndef CON_ALUMNO
#define CON_ALUMNO
#include <iostream>
typedef struct consultaAlumno {
	std::string rs[1][8];
}consultaAlumno;
struct consultaAlumno ConsultarAlumno(std::string clave_grupo);

#endif