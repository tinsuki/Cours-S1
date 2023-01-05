-- ==========================
-- fichier      : vider_base_gestloc.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : 19/11/22
-- role         : vide chaque table de la base de données gestloc
-- projet       : gestloc
-- resultat dans: vider_base_gestloc.out
-- ==========================

spool vider_base_gestloc.out

DELETE DPE;

DELETE VISITE;

DELETE LOCATION;

DELETE BIEN;

DELETE LOCATAIRE;

DELETE PROPRIETAIRE;

DELETE SYNDIC;

DELETE AGENCE;

spool off;