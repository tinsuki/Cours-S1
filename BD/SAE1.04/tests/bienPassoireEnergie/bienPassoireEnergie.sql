-- ==========================
-- fichier      : bienPassoireEnergie.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : 23/12/22
-- role         : Quel sont les bien dont la classe énérgie est F ou G ?
-- projet       : gestloc
-- ==========================

SELECT idBien, idPropri, idAgence, classeEnergie
FROM BIEN NATURAL JOIN DPE
WHERE (classeEnergie='F' or classeEnergie='G') AND dateFin > CURRENT_DATE;