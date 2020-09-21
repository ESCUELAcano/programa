DELIMITER $$
CREATE PROCEDURE borrar_profesor (in CedulaProfesor INT) 
BEGIN
	update GRUPO SET Dprofesor=null where Dprofesor=CedulaProfesor;
	delete FROM PROFESOR WHERE CedulaProfesional=CedulaProfesor;
END $$
DELIMITER ;