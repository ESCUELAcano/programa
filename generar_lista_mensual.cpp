#include "generar_lista_mensual.h"
#include <mysql.h>
#include <mysqld_error.h>
#include <fstream>

#include <iostream>
using namespace std;

struct listaCalMensual generar_lista_mensual(string clave_alumno_lista, string mes_lista){
    /*Nombre: GENERAR_LISTA_MENSUAL 
    FLUJOS DE ENTRADA: 
    FLUJO 01: conjunto_calificacion, TIPO Tabla_CALIFICACION
    FLUJO 02:  clave_alumno_lista de TIPO CADENA
    FLUJO03: mes_lista, de Tipo FECHA
    FLUJOS DE SALIDA: 
    FLUJO 01: lista_cal_mensual TIPO: arreglo de cadena */
    /*CONSTANTES*/
    
    /*VARIABLES*/
    struct listaCalMensual a;
    MYSQL* coneccion;
    ifstream archivoSQL{ "SCRIPTS/lista_calificacion.sql" };
    string ejecutarScript{ istreambuf_iterator<char>(archivoSQL), istreambuf_iterator<char>() };
    string::size_type pos;
    unsigned int num_filas;
    unsigned int num_f = 0;
    const char* _lista;
    MYSQL_RES* res;
    MYSQL_ROW row;
    /*COMIENZA*/
    coneccion = mysql_init(0);
    if (coneccion) {
        coneccion = mysql_real_connect(coneccion, "bj42twrs4vaqpd6iosvg-mysql.services.clever-cloud.com", "uw77bf6ikf5zyq1n", "q8apKjoZ8H2sR6PI2ZI2", "bj42twrs4vaqpd6iosvg", 3306, NULL, 0);
    }
    //REMPLAZAR CURP
    pos = ejecutarScript.find("CURP", 0);
    if (pos < string::npos) {
        ejecutarScript.replace(pos, string("CURP").length(), "\'" + clave_alumno_lista + "\'");
    }
    //TERMINA REMPLAZAR CURP
    //REMPLAZAR MES
    pos = ejecutarScript.find("Mes", 0);
    if (pos < string::npos) {
        ejecutarScript.replace(pos, string("Mes").length(), "\'" + mes_lista + "\'");
    }
    //TERMINA REMPLAZAR MES
    
    _lista = ejecutarScript.c_str();
    mysql_query(coneccion, _lista);
    res = mysql_store_result(coneccion);
    num_filas = mysql_num_fields(res);
    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < num_filas; i++) {
            if (row[i] != NULL) {
                a.rs[num_f][i] = row[i];
            }
        }
        num_f = num_f + 1;
    }
    if (res != NULL)
        mysql_free_result(res);

    mysql_close(coneccion);
    return a;
    /*TERMINA*/
}
