USE ESCUELA;
DELIMITER $$
CREATE PROCEDURE almacenar_alumno (in nombre01 VARCHAR(20), in apellidoP01 VARCHAR(20), in apellidoM01 VARCHAR(20), in direccion01 VARCHAR(20), in curp01 VARCHAR(20), in fechaNacimiento01 DATE, in padreTutor01 VARCHAR(20), in DGrupo01 VARCHAR(20)) 
BEGIN
	INSERT INTO ALUMNO VALUES(nombre01, apellidoP01, apellidoM01,direccion01,curp01, fechaNacimiento01, padreTutor01, DGrupo01);  
END $$
DELIMITER ;
