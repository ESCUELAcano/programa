#Archivo: SCRIPT03.SQL 
#Descripción: Sirve para crear a la tabla ALUMNO. 
USE ESCUELA;
CREATE TABLE IF NOT EXISTS ALUMNO ( 
    Nombre VARCHAR(30) NOT NULL, 
    ApellidoP VARCHAR(30) NOT NULL, 
    ApellidoM VARCHAR(30) NOT NULL, 
    Direccion VARCHAR(200) NOT NULL, 
    CURP VARCHAR(20) NOT NULL PRIMARY KEY, 
    FechaNacimiento DATE NOT NULL, 
	PadreTutor VARCHAR(7) NOT NULL, 
    DGrupo VARCHAR(30) NOT NULL, 
	FOREIGN KEY (PadreTutor) REFERENCES TUTOR(Credencial),
    FOREIGN KEY (DGrupo) REFERENCES GRUPO (Nombre) 
); 