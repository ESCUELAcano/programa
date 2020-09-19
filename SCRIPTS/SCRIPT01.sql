#Archivo: SCRIPT02.SQL 
#Descripción: Sirve para crear a la tabla PROFESOR. 
CREATE DATABASE ESCUELA;
USE ESCUELA;
CREATE TABLE IF NOT EXISTS PROFESOR ( 
	Nombre VARCHAR (30) NOT NULL, 
	ApellidoP VARCHAR(15) NOT NULL, 
	ApellidoM VARCHAR(15) NOT NULL, 
	RFC VARCHAR(13) NOT NULL UNIQUE, 
	FechaNacimiento DATE, 
	GENERO VARCHAR (6) NOT NULL, 
	CedulaProfesional INT NOT NULL, 
	Telefono VARCHAR(20), 
	Experiencia VARCHAR(100) NOT NULL, 
	primary key (CedulaProfesional)
); 