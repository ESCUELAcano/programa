
DELIMITER $$
CREATE PROCEDURE ConsultaProfesor (CedulaProfesor:VARCHAR) 
	Select * FROM PROFESOR where CedulaProfesional=CedulaProfesor;
END $$
DELIMITER ;
