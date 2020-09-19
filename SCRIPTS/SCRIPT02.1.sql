#Archivo: SCRIPT02.1.SQL 
#Descripción Sirve para crear la tabla GRUPO 
USE ESCUELA;
CREATE TABLE IF NOT EXISTS GRUPO ( 
	Nombre VARCHAR(30) NOT NULL, 
    Grado INT not null, 
    Turno VARCHAR(12)NOT NULL, 
    DProfesor INT NOT NULL, 
    DTutor VARCHAR (7)NOT NULL ,  
    PRIMARY KEY (Nombre), 
    FOREIGN KEY(DProfesor) REFERENCES PROFESOR(CedulaProfesional), 
    FOREIGN KEY(DTutor) REFERENCES TUTOR(Credencial)
);


INSERT INTO GRUPO VALUES ('1A',1,'matutino',762722,'1234567');

select * from TUTOR;