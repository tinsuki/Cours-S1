-- ==========================
-- fichier      : bienPassoireEnergie.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : décembre 2022
-- role         : Quel est le nombre de visites par lmogements ?
-- projet       : gestloc
-- ==========================

BREAK ON REPORT
COMPUTE AVG LABEL 'Moyenne' OF NbVisite ON REPORT
SELECT b.IDBIEN, COUNT(v.IDVISITE) AS NbVisite
FROM BIEN b LEFT OUTER JOIN VISITE v on b.IDBIEN=v.IDBIEN
GROUP BY b.IDBIEN;