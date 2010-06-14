CREATE TABLE Cell (id INTEGER PRIMARY KEY AUTOINCREMENT, 
	type VARCHAR(100), 
	content BLOB);
CREATE TABLE Connection (dname TEXT,
	id INTEGER,
	pos INTEGER,
	PRIMARY KEY(dname,id,pos), 
	FOREIGN KEY(id) REFERENCES Cell
		ON DELETE RESTRICT
		ON UPDATE CASCADE,
	FOREIGN KEY(pos) REFERENCES Cell(id)
		ON DELETE RESTRICT
		ON UPDATE CASCADE);
