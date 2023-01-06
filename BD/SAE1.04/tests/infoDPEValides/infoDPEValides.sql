-- ==========================
-- fichier      : listeDPEValides.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : janvier 2023
-- role         : Quel sont les informations energétiques du DPE en cours par logement ?
-- projet       : gestloc
-- ==========================

SELECT IDBIEN, CLASSEENERGIE, CLASSECLIMAT, CONSOMATION, EMISSIONS, MENTION
FROM BIEN NATURAL JOIN DPE
WHERE DATEFIN > CURRENT_DATE;