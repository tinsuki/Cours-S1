-- ==========================
-- fichier      : drop_gestloc.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : 19/11/22
-- role         : suprime les tables de la bd gestloc
-- projet       : gestloc
-- resultat dans: drop_gestloc.out
-- ==========================

spool drop_gestloc.out

DROP TABLE LOCATION CASCADE CONSTRAINT;

DROP TABLE BIEN CASCADE CONSTRAINT;

DROP TABLE AGENCE CASCADE CONSTRAINT;

DROP TABLE PROPRIETAIRE CASCADE CONSTRAINT;

DROP TABLE LOCATAIRE CASCADE CONSTRAINT;

DROP TABLE SYNDIC CASCADE CONSTRAINT;

spool off;