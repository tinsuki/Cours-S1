-- ==========================
-- fichier      : bienPassoireEnergie.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : Janvier 2023
-- role         : tests pour Quel sont les informations energétiques du DPE en cours par logement ?
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

-- Insertion du prorietaire pour les dépendances
INSERT INTO PROPRIETAIRE (IDPROPRI, NOM, PRENOM, TEL, MAIL, IBAN)
VALUES(1, 'SIMON', 'Laurent', '0601010101', 'SimonLaurent@example.com', 'FR2830003000709164663684Y18');

-- Cas 1 : un logement a un DPE valide à la date d’envoi de la requête

-- Insertion du bien
INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(1, 1, 1, 1, 'La Rochelle', 3, 65);

-- Insertion du DPE
INSERT INTO DPE (IDDPE, IDBIEN, DATEDEBUT, DATEFIN, CLASSEENERGIE, CLASSECLIMAT, CONSOMMATION, EMISSIONS)
VALUES(1, 1, to_date('23/12/2021', 'DD/MM/YYYY'), to_date('22/12/2031', 'DD/MM/YYYY'), 'C', 'C', 147, 20);

-- Cas 2 : un logement a un DPE valide et un non-valide à la date d’envoi de la requête

-- Insertion du bien
INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(2, 1, 1, 1, 'La Rochelle', 3, 65);

-- Insertion du DPE valide
INSERT INTO DPE (IDDPE, IDBIEN, DATEDEBUT, DATEFIN, CLASSEENERGIE, CLASSECLIMAT, CONSOMMATION, EMISSIONS,  MENTION)
VALUES(3, 2, to_date('23/12/2021', 'DD/MM/YYYY'), to_date('22/12/2031', 'DD/MM/YYYY'), 'F', 'F', 347, 86, 'Passoire Energetique');

INSERT INTO DPE (IDDPE, IDBIEN, DATEDEBUT, DATEFIN, CLASSEENERGIE, CLASSECLIMAT, CONSOMMATION, EMISSIONS, MENTION)
VALUES(2, 2, to_date('23/12/2011', 'DD/MM/YYYY'), to_date('22/12/2021', 'DD/MM/YYYY'), 'F', 'F', 347, 86, 'Passoire Energetique');


-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================

-- Cas 3 : un logement n'a pas de DPE valide à la date d’envoi de la requête

-- Insertion du bien
INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(3, 1, 1, 1, 'La Rochelle', 3, 65);

-- Insertion d'un DPE invalide
INSERT INTO DPE (IDDPE, IDBIEN, DATEDEBUT, DATEFIN, CLASSEENERGIE, CLASSECLIMAT, CONSOMMATION, EMISSIONS)
VALUES(4, 3, to_date('23/12/2011', 'DD/MM/YYYY'), to_date('22/12/2021', 'DD/MM/YYYY'), 'C', 'C', 147, 20);


-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL testInfoDPEValides.out  
PROMPT fichier resultat du test : testInfoDPEValides.out 


-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base : 
SET echo ON 
@ ../../utilitaires/afficher_base_gestloc.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================

-- Debut de l'affichage du resultat de la requete sur le client SqlPlus
prompt 'Resultat de la requete'
@infoDPEValides.sql

-- Fin de l'affichage sur le client SqlPlus
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

