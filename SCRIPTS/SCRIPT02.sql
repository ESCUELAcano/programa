#Archivo: SCRIPT02.SQL 
#Descripción: Sirve para crear a la tabla TUTOR. 
USE ESCUELA;
CREATE TABLE IF NOT EXISTS TUTOR ( 
	Nombre VARCHAR(30) NOT NULL, 
	ApellidoP VARCHAR(15) NOT NULL, 
	ApellidoM VARCHAR(15) NOT NULL, 
	Credencial VARCHAR(7) NOT NULL, 
	PRIMARY KEY(Credencial) 
); 