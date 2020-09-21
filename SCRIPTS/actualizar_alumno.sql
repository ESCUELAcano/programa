
DELIMITER $$ 
CREATE PROCEDURE actualizar_alumno (in nombre01 VARCHAR(20), in apellidoP01 VARCHAR(20), in apellidoM01 VARCHAR(20), in direccion01 VARCHAR(200), in curp01 VARCHAR(20), in fechaNacimiento01 DATE, in padreTutor01 VARCHAR(20), in DGrupo01 VARCHAR(20))  
BEGIN 
 UPDATE ALUMNO  SET Nombre = nombre01, ApellidoP = apellidoP01, ApellidoM = apellidoM01,Direccion = direccion01, CURP = curp01, FechaNacimiento = fechaNacimiento01, PadreTutor = padreTutor01, DGrupo= DGrupo01 where CURP = curp01 ; 
END $$ 
DELIMITER ; 