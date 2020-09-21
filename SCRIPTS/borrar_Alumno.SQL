DELIMITER $$
CREATE PROCEDURE borrar_alumno (clave_borrar_alumno VARCHAR(18)) 
BEGIN
	delete FROM CALIFICACION WHERE DAlumno= clave_borrar_alumno;
	DELETE FROM ALUMNO WHERE CURP = clave_borrar_alumno;
END $$
DELIMITER ;