USE bj42twrs4vaqpd6iosvg;
DELIMITER $$
CREATE PROCEDURE almacenar_grupo(nombre01 VARCHAR(30) ,grado01  INT,turno01 VARCHAR(12),Profesor01  VARCHAR, Tutor01 VARCHAR) 
BEGIN
	INSERT INTO GRUPO VALUES(nombre01,grado01,turno01,Tutor01,Profesor01); 
END $$
DELIMITER ;