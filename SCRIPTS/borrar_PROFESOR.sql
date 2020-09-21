DELIMITER $$
CREATE PROCEDURE borrar_profesor (CedulaProfesor INT) 
BEGIN
	delete FROM PROFESOR WHERE CedulaProfesional=CedulaProfesor;
END $$
DELIMITER ;