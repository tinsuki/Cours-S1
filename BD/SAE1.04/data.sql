-- ==========================
-- fichier      : data.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : 20/11/22
-- role         : insert un jeu de données pour l'explication du premier jalon 
-- projet       : gestloc
-- resultat dans: data.out
-- ==========================

spool data.out;


-- Insertion de plusieurs Agences :

-- Agence n°1 : 
INSERT INTO AGENCE (idAgence, nomAgence, adrAgence, contactAgence)
VALUES (1, 'AgenceLyon', '143 Rue Paul Bert, 69003 Lyon, France', '0478622215');


-- Agence n°2 :

INSERT INTO AGENCE (idAgence, nomAgence, adrAgence, contactAgence)
VALUES (2, 'AgenceLille', '255 Rue Nationale, 59800 Lille, France', '0963643769');



-- Insertion de plusieurs proprietaires :

-- proprietaire n°1 :

INSERT INTO PROPRIETAIRE (idProprietaire, nomProprietaire, prenomProprietaire, telProprietaire, mailProprietaire, ibanProprietaire)
VALUES (10, 'MARTIN', 'Jean', '0666666666', 'MartinJean@example.com', 'FRXXXXXXXXXXXXXXXXXXXXXXXXX');

-- proprietaire n°2 :

INSERT INTO PROPRIETAIRE (idProprietaire, nomProprietaire, prenomProprietaire, telProprietaire, mailProprietaire, ibanProprietaire)
VALUES (20, 'Mary', 'Laetitia', '0677777777', 'MaryLaetitia@example.com', 'FRXXXXXXXXXXXXXXXXXXXXXXXXX');

-- proprietaire n°3 :

INSERT INTO PROPRIETAIRE (idProprietaire, nomProprietaire, prenomProprietaire, telProprietaire, mailProprietaire, ibanProprietaire)
VALUES (30, 'Lefort', 'ELisabeth', '0688888888', NULL, 'FRXXXXXXXXXXXXXXXXXXXXXXXXX');



-- Insertion de plusieurs locataire :

-- Locataire n°1 :
INSERT INTO LOCATAIRE (idLocataire, nomLocataire, prenomLocataire, telLocataire, mailLocataire, ibanLocataire)
VALUES (11, 'Muller', 'Lucie', '0611111111', 'MullerLucie@example.com', 'FRXXXXXXXXXXXXXXXXXXXXXXXXXXX');

-- Locataire n°2 :
INSERT INTO LOCATAIRE (idLocataire, nomLocataire, prenomLocataire, telLocataire, mailLocataire, ibanLocataire)
VALUES (22, 'Adam', 'Adele', '0622222222', 'AdamAdele@example.com', 'FRXXXXXXXXXXXXXXXXXXXXXXXXXXX');

-- Locataire n°3 :
INSERT INTO LOCATAIRE (idLocataire, nomLocataire, prenomLocataire, telLocataire, mailLocataire, ibanLocataire)
VALUES (33, 'Girard', 'Olivier', '0633333333', 'GirardOlivier@example.com', 'FRXXXXXXXXXXXXXXXXXXXXXXXXXXX');


-- Insertion de plusieurs syndics :

-- Syndic n°1 :
INSERT INTO SYNDIC  (idSyndic, nomSyndic, prenomSyndic, contactSyndic)
VALUES (1, 'Guyot', 'Gilles', 'GuyotGilles@example.com');

-- Syndic n°2 : 
INSERT INTO SYNDIC  (idSyndic, nomSyndic, prenomSyndic, contactSyndic)
VALUES (2, 'Leroux', 'Pauline', 'LerouxPauline@example.com');



-- Insertion plusieurs Bien :

-- Bien n°1 :
INSERT INTO BIEN (idBien, adrBien, bail, loyer, surface, nbrVisite, idAgence, idProprietaire, idSyndic)
Values (1, '5 rue de l alsace, 69003 Lyon', 1, 385, 25, 16, 1, 10, 1);


-- Bien n°2 :
INSERT INTO BIEN (idBien, adrBien, bail, loyer, surface, nbrVisite, idAgence, idProprietaire, idSyndic)
Values (2, '7 rue de l alsace, 69003 Lyon', 3, 485, 57, 16, 1, 20, 1);

-- Bien n°3
INSERT INTO BIEN (idBien, adrBien, bail, loyer, surface, nbrVisite, idAgence, idProprietaire, idSyndic)
Values (3, '9 rue Duguesclin, 59800 Lille', 3, 600, 200, 34, 2, 30,2);


-- Insertion de locations :

-- Location n°1 :
INSERT INTO LOCATION (idLocation, dateDebut, datePrevFin, idLocataire, idBien)
VALUES (1, to_date('20-11-2022', 'dd-mm-yyyy'), to_date('19-11-2025', 'dd-mm-yyyy'), 11, 3);

-- location n°2 :
INSERT INTO LOCATION (idLocation, dateDebut, datePrevFin, idLocataire, idBien)
VALUES (2, to_date('24-11-2022', 'dd-mm-yyyy'), to_date('23-11-2025', 'dd-mm-yyyy'), 22, 2);

spool off;