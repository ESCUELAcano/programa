USE bj42twrs4vaqpd6iosvg;
#DROP PROCEDURE IF EXISTS actualizar_profesor;

DELIMITER $$
CREATE PROCEDURE actualizar_profesor (IN Nombre01 VARCHAR(30), IN ApellidoP01 VARCHAR(15), IN ApellidoM01 VARCHAR(15),IN RFC01 VARCHAR(22),IN FechaNacimiento01 DATE,IN GENERO01 VARCHAR(6),IN CedulaProfesional01 INT,IN Telefono01 VARCHAR(20), IN Experiencia01 VARCHAR(100)) 
BEGIN
	DROP PROFESOR  (Nombre=Nombre01,ApellidoP=ApellidoP01,ApellidoM=ApellidoM01,RFC=RFC01,FechaNacimiento=FechaNacimiento01,GENERO=GENERO01,CedulaProfesional=CedulaProfesional01,Telefono=Telefono01,Experiencia=Experiencia01)
    where CedulaProfesional=CedulaProfesional01; 
END $$
DELIMITER ;