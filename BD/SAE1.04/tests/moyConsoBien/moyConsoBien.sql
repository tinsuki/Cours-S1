-- ==========================
-- fichier      : moyConsoBien.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : janvier 2023
-- role         : Quelle est la moyenne de consommation par bien  ?
-- projet       : gestloc
-- ==========================

BREAK ON REPORT
COMPUTE AVG LABEL 'Moy. Totale' OF CONSOMMATION ON REPORT
SELECT IDBIEN, IDPROPRI, CONSOMMATION
FROM BIEN NATURAL JOIN DPE
WHERE DATEFIN > CURRENT_DATE;