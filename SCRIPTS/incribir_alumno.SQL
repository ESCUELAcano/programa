DELIMITER $$
CREATE PROCEDURE inscribir_alumno (Nombregrupo VARCHAR(30),Curp_alumno VARCHAR(18)) 
BEGIN
	update ALUMNO 
	SET DGrupo=Grupo
	where CURP=Curp_alumno; 
END $$
DELIMITER ;