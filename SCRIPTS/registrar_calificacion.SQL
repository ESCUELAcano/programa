USE bj42twrs4vaqpd6iosvg;
DROP PROCEDURE IF EXISTS registrar_calificacion;
DELIMITER $$
CREATE PROCEDURE registrar_calificacion (in Vcurp VARCHAR(18),in Vcalificacion FLOAT(2),in Vfecha DATE) 
BEGIN
	INSERT INTO CALIFICACION VALUES(Vcurp,Vcalificacion,Vfecha,Vcurp); 
END $$
DELIMITER ;
