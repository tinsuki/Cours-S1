-- ==========================
-- fichier      : data.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : 20/11/22
-- role         : insert un jeu de données pour l'explication du premier jalon 
-- projet       : gestloc
-- ==========================



-- Insertion de plusieurs Agences

INSERT INTO AGENCE (idAgence, nom, adresse, contact)
VALUES (1, 'AgenceLyon', 'Lyon, France', 'AgenceImmoLyon@example.com');

INSERT INTO AGENCE (idAgence, nom, adr, contact)
VALUES (2, 'AgenceLille', 'Lille, France', 'AgenceImmoLille@example.com');

INSERT INTO AGENCE (idAgence, nom, adr, contact)
VALUES (3, 'AgenceParis', 'Paris, France', 'AgenceImmoParis@example.com');

INSERT INTO AGENCE (idAgence, nom, adr, contact)
VALUES (4, 'AgenceLaRochelle', 'LaRochelle, France', 'AgenceImmoLaRochelle@example.com');

INSERT INTO AGENCE (idAgence, nom, adr, contact)
VALUES (5, 'AgenceRochefort', 'Rochefort, France', 'AgenceImmoRochefort@example.com');



-- Insertion de Plusieurs Proprietaires*

INSERT INTO PROPRIETAIRE (idPropri, nom, prenom, tel, mail, iban)
VALUES (1, 'MARTIN', 'Jean', '0601010101', 'MartinJean@example.com', 'FRXXXXXXXXXXXXXXXXXXXXXXX01');

INSERT INTO PROPRIETAIRE (idPropri, nom, prenom, tel, mail, iban)
VALUES (2, 'MARTIN', 'Lucas', '0602020202', 'MartinJean@example.com', 'FRXXXXXXXXXXXXXXXXXXXXX03');

INSERT INTO PROPRIETAIRE (idPropri, nom, prenom, tel, mail, iban)
VALUES (3, 'MET', 'Delphine', '0603030303', 'MetDelphine@example.com', 'FRXXXXXXXXXXXXXXXXXXXXXXX04');

INSERT INTO PROPRIETAIRE (idPropri, nom, prenom, tel, mail, iban)
VALUES (4, 'MAZURIER', 'Yann', '0604040404', 'MazurierYann@example.com', 'FRXXXXXXXXXXXXXXXXXXXXXXX06');

INSERT INTO PROPRIETAIRE (idPropri, nom, prenom, tel, mail, iban)
VALUES (5, 'JEAN', 'Mark', '0605050505', 'MazurierYann@example.com', 'FRXXXXXXXXXXXXXXXXXXXXXXX07');

-- Insertion de plusieurs Locataire

INSERT INTO LOCATAIRE (id, nom, prenom, tel, mail, iban)
VALUES (1, 'Muller', 'Lucie', '0610101010', 'MullerLucie@example.com', 'FRXXXXXXXXXXXXXXXXXXXXXXXXX02');

INSERT INTO LOCATAIRE (idLocataire, nomLocataire, prenomLocataire, telLocataire, mailLocataire, ibanLocataire)
VALUES (2, 'SIMON', 'Laurent', '0620202020', 'SimonLaurent@example.com', 'FRXXXXXXXXXXXXXXXXXXXXXXXXX05');

INSERT INTO LOCATAIRE (idLocataire, nomLocataire, prenomLocataire, telLocataire, mailLocataire, ibanLocataire)
VALUES (3, 'MATHIEU', 'Leana', '0630303030', 'MathieuLeana@example.com', 'FRXXXXXXXXXXXXXXXXXXXXXXXXX05');

-- Insertion de plusieurs Syndics

INSERT INTO SYNDIC  (id, nom, prenom, contact)
VALUES (1, 'Guyot', 'Gilles', 'GuyotGilles@example.com');

INSERT INTO SYNDIC  (idSyndic, nomSyndic, prenomSyndic, contactSyndic)
VALUES (2, 'MARTIN', 'François', 'MartinFrançois@example.com');

INSERT INTO SYNDIC  (idSyndic, nomSyndic, prenomSyndic, contactSyndic)
VALUES (3, 'MARTIN', 'Lou', 'MartinLou@example.com');

-- Insertion de plusieurs biens

INSERT INTO BIEN (idBien, idAgence, idPropri, idSyndic, adresse, typeBail, Loyer, surface)
Values (1,  2, 2, 2, 'Lyon, France', 3, 385, 25);

INSERT INTO BIEN (idBien, idAgence, idPropri, idSyndic, adresse, typeBail, Loyer, surface)
Values (2,  3, 3, 3, 'Paris, France', 3, 385, 25);

INSERT INTO BIEN (idBien, idAgence, idPropri, idSyndic, adresse, typeBail, Loyer, surface)
Values (3,  4, 4, 4, 'La Rochelle, France', 3, 385, 25);

INSERT INTO BIEN (idBien, idAgence, idPropri, idSyndic, adresse, typeBail, Loyer, surface)
Values (4,  5, 5, 5, 'Rochefort, France', 3, 385, 25);

-- Insertion d'une LOCATION

INSERT INTO LOCATION (idLocation, dateDebut, datePrevFin, dateFin, idLocataire, idBien)
VALUES (1, to_date('20-11-2022', 'dd-mm-yyyy'), to_date('19-11-2025', 'dd-mm-yyyy'), 2, 2);

-- Insertion d'une Visite

INSERT INTO VISITE (idVisite, idBien, dateVisite, Heure, Retour)
VALUES(1, 3, to_date('23/11/2022', 'DD/MM/YYYY'), 14, 'Manque d eclerage');

-- Insertion d'un DPE

INSERT INTO DPE (idDPE, idBien, dateDebut, dateFin, classeEnergie, classeClimat, consommation, emmissions)
VALUES(1, 4, to_date('23/12/2011', 'DD/MM/YYYY'), to_date('22/12/2021', 'DD/MM/YYYY'), 'C', 'C', 147, 20);
