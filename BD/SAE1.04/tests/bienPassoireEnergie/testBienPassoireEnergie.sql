-- ==========================
-- fichier      : bienPassoireEnergie.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : 23/12/22
-- role         : tests pour Quel sont les bien dont la classe énérgie est F ou G ?
-- projet       : gestloc
-- ==========================

-- ============================================================================
-- Modification du format de la date pour se conformer aux donnees du programme de test
-- ============================================================================
alter session set NLS_DATE_FORMAT='dd/mm/yyyy';

-- ============================================================================
-- Suppression des nuplets de la base de donnees
-- NB : Le test est effectué sur une base vide, il est nécessaire 
--      de supprimer tous les nuplets de toutes les relations
-- ============================================================================
@ ../../utilitaires/vider_base_gestloc.sql

-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- ============================================================================

-- Insertion de l'agence gérant les logements pour les dépendences
INSERT INTO AGENCE (IDAGENCE, NOM, ADRESSE, CONTACT)
VALUES(1, 'AgenceExemple', 'La Rochelle', 'AgenceImmoLaRochelle@example.com');

-- Insertion du Syndic pour les dépendances
INSERT INTO SYNDIC (IDSYNDIC, NOM, PRENOM, CONTACT)
VALUES(1, 'MET', 'Delphine', 'MetDelphine@example.com');


-- Cas 1 : un propriétaire a un bien de classe énergie F ou G dont le DPE est valide

-- Insertion du prorietaire
INSERT INTO PROPRIETAIRE (IDPROPRI, NOM, PRENOM, TEL, MAIL, IBAN)
VALUES(1, 'SIMON', 'Laurent', '0601010101', 'SimonLaurent@example.com', 'FR2830003000709164663684Y18');

-- Insertion du bien concerné
INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(1, 1, 1, 1, 'La Rochelle', 3, 70);

-- Insertion du DPE valide
INSERT INTO DPE (IDDPE, IDBIEN, DATEDEBUT, DATEFIN, CLASSEENERGIE, CLASSECLIMAT, CONSOMMATION, EMISSIONS, MENTION)
VALUES(1, 1, to_date('23/12/2021', 'DD/MM/YYYY'), to_date('22/12/2031', 'DD/MM/YYYY'), 'F', 'F', 374, 86, 'Passoire énergétique');

-- Cas 2 : un propriétaire a deux bien de classe énergie F ou G dont les DPE sont valides

-- Insertion du prorietaire
INSERT INTO PROPRIETAIRE (IDPROPRI, NOM, PRENOM, TEL, MAIL, IBAN)
VALUES(2, 'MARTIN', 'Lucas', '0602020202', 'MartinLucas@example.com', 'FR9312739000306762795717Z48');

-- Insertion des biens concernés
INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(2, 2, 1, 1, 'La Rochelle', 3, 65);

INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(3, 2, 1, 1, 'La Rochelle', 3, 75);

-- Insertion du DPE valide
INSERT INTO DPE (IDDPE, IDBIEN, DATEDEBUT, DATEFIN, CLASSEENERGIE, CLASSECLIMAT, CONSOMMATION, EMISSIONS, MENTION)
VALUES(2, 2, to_date('23/12/2021', 'DD/MM/YYYY'), to_date('22/12/2031', 'DD/MM/YYYY'), 'G', 'F', 436, 86, 'Passoire énergétique');

INSERT INTO DPE (IDDPE, IDBIEN, DATEDEBUT, DATEFIN, CLASSEENERGIE, CLASSECLIMAT, CONSOMMATION, EMISSIONS, MENTION)
VALUES(3, 3, to_date('23/12/2021', 'DD/MM/YYYY'), to_date('22/12/2031', 'DD/MM/YYYY'), 'F', 'F', 392, 86, 'Passoire énergétique');

-- Cas 3 : un propriétaire a un bien de classe énergie F ou G et un bien de classe énergie supérieure dont les DPE sont valides

-- Insertion du prorietaire
INSERT INTO PROPRIETAIRE (IDPROPRI, NOM, PRENOM, TEL, MAIL, IBAN)
VALUES(3, 'MARTIN', 'Lou', '0603030303', 'MartinLou@example.com', 'FR0212739000501348268195B43');

-- Insertion des biens concernés
INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(4, 3, 1, 1, 'La Rochelle', 3, 65);

INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(5, 3, 1, 1, 'La Rochelle', 3, 75);

-- Insertion du DPE valide
INSERT INTO DPE (IDDPE, IDBIEN, DATEDEBUT, DATEFIN, CLASSEENERGIE, CLASSECLIMAT, CONSOMMATION, EMISSIONS, MENTION)
VALUES(4, 4, to_date('23/12/2021', 'DD/MM/YYYY'), to_date('22/12/2031', 'DD/MM/YYYY'), 'G', 'F', 436, 86, 'Passoire énergétique');

INSERT INTO DPE (IDDPE, IDBIEN, DATEDEBUT, DATEFIN, CLASSEENERGIE, CLASSECLIMAT, CONSOMMATION, EMISSIONS)
VALUES(5, 5, to_date('23/12/2021', 'DD/MM/YYYY'), to_date('22/12/2031', 'DD/MM/YYYY'), 'B', 'C', 75, 14);

-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================

-- Cas 4 : un propriétaire a un bien de classe énergie superieure à F dont le DPE est valide

-- Insertion du prorietaire
INSERT INTO PROPRIETAIRE (IDPROPRI, NOM, PRENOM, TEL, MAIL, IBAN)
VALUES(4, 'MARTIN', 'Jean', '0604040404', 'MartinJean@example.com', 'FR8914508000404867995618C20');

-- Insertion du bien concerné
INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(6, 4, 1, 1, 'La Rochelle', 3, 70)

-- Insertion du DPE valide
INSERT INTO DPE (IDDPE, IDBIEN, DATEDEBUT, DATEFIN, CLASSEENERGIE, CLASSECLIMAT, CONSOMMATION, EMISSIONS)
VALUES(6, 6, to_date('23/12/2021', 'DD/MM/YYYY'), to_date('22/12/2031', 'DD/MM/YYYY'), 'A', 'B', 65, 9);

-- Cas 5 : un propriétaire a un bien  dont le DPE est invalide

-- Insertion du prorietaire
INSERT INTO PROPRIETAIRE (IDPROPRI, NOM, PRENOM, TEL, MAIL, IBAN)
VALUES(5, 'DUPONT', 'Martin', '0605050505', 'DupontMartin@example.com', 'FR9710096000404933598147H21');

-- Insertion du bien concerné
INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(7, 5, 1, 1, 'La Rochelle', 3, 70)

-- Insertion du DPE invalide
INSERT INTO DPE (IDDPE, IDBIEN, DATEDEBUT, DATEFIN, CLASSEENERGIE, CLASSECLIMAT, CONSOMMATION, EMISSIONS, MENTION)
VALUES(7, 7, to_date('24/12/2012', 'DD/MM/YYYY'), to_date('23/12/2022', 'DD/MM/YYYY'), 'F', 'F', 374, 86, 'Passoire énergétique');


-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL testBienPassoireEnergie.out  
PROMPT fichier resultat du test : testBienPassoireEnergie.out 


-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base : 
SET echo ON 
@ ../../utilitaires/afficher_base_gestloc.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================

-- Debut de l'affichage du resultat de la requete sur le client SqlPlus
prompt 'Resultat de la requete'
@bienPassoireEnergie.sql

-- Fin de l'affichage sur le client SqlPlus
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

