/*SCRIPT almacenar_profesor 
Descripcion: Sirve para insertar un nuevo registro en la tabla PROFESOR capturado directamente desde el procedimiento del sistema llamado REGISTRAR_PROFESOR */
USE bj42twrs4vaqpd6iosvg;
#DROP PROCEDURE IF EXISTS almacenar_profesor;

DELIMITER $$
CREATE PROCEDURE almacenar_profesor (IN Nombre VARCHAR(30), IN ApellidoP VARCHAR(15), IN ApellidoM VARCHAR(15),IN RFC VARCHAR(22),IN FechaNacimiento DATE,IN GENERO VARCHAR(6),IN CedulaProfesional INT,IN Telefono VARCHAR(20), IN Experiencia VARCHAR(100)) 
BEGIN
	INSERT INTO PROFESOR VALUES (Nombre,ApellidoP,ApellidoM,RFC,FechaNacimiento,GENERO,CedulaProfesional,Telefono,Experiencia); 
END $$
DELIMITER ;