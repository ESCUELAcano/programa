USE bj42twrs4vaqpd6iosvg;
DROP PROCEDURE IF EXISTS almacenar_tutor;

DELIMITER $$
CREATE PROCEDURE almacenar_tutor (IN nombre VARCHAR(30), IN apellido_p VARCHAR(15), IN apellido_m VARCHAR(15),IN credencial VARCHAR(7)) 
BEGIN
	INSERT INTO TUTOR VALUES (nombre,apellido_p,apellido_m,credencial); 
END $$
DELIMITER ;