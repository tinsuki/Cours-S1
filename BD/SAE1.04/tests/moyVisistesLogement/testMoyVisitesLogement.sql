-- ==========================
-- fichier      : testMoyVisitesLogement.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : décembre 2022
-- role         : tests pour Quel est le nombre de visites par logements ?
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


-- Cas 1 : un logement a été visité une fois
-- Insertion du bien concerné
INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(1, 1, 1, 1, 'La Rochelle', 3, 70);

-- insertion d'une visite
INSERT INTO VISITE (IDVISITE, IDBIEN, DATEVISITE, HEURE)
VALUES(1, 1, to_date('15/12/2022', 'DD/MM/YYYY'), 14);

-- Cas 2 : un logement a été visité 2 fois

-- Insertion du bien concerné
INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(2, 1, 1, 1, 'La Rochelle', 3, 65);

-- Insertion des visites
INSERT INTO VISITE (IDVISITE, IDBIEN, DATEVISITE, HEURE)
VALUES(2, 2, to_date('23/11/2022', 'DD/MM/YYYY'), 13.5);

INSERT INTO VISITE (IDVISITE, IDBIEN, DATEVISITE, HEURE)
VALUES(3, 2, to_date('23/11/2022', 'DD/MM/YYYY'), 14);

-- Cas 3 : un logement n’a pas été visité

-- Insertion du bien concerné
INSERT INTO BIEN (IDBIEN, IDPROPRI, IDAGENCE, IDSYNDIC, ADRESSE, TYPEBAIL, SURFACE)
VALUES(3, 1, 1, 1, 'La Rochelle', 3, 65);



-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================


-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL testMoyVisitesLogement.out  
PROMPT fichier resultat du test : testMoyVisitesLogement.out 


-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base : 
SET echo ON 
@ ../../utilitaires/afficher_base_gestloc.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================

-- Debut de l'affichage du resultat de la requete sur le client SqlPlus
prompt 'Resultat de la requete'
@moyVisitesLogement.sql

-- Fin de l'affichage sur le client SqlPlus
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

