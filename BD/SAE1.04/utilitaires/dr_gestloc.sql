-- ==========================
-- fichier      : dr_gestloc.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : 19/11/22
-- role         : créer les dépendances de référence de la base de données gestloc
-- projet       : gestloc
-- resultat dans: dr_gestloc.out
-- ==========================

spool dr_gestloc.out

ALTER TABLE Bien
  ADD CONSTRAINT FK_Agence_TO_Bien
    FOREIGN KEY (idAgence)
    REFERENCES Agence (idAgence);

ALTER TABLE Bien
  ADD CONSTRAINT FK_Propriétaire_TO_Bien
    FOREIGN KEY (idProprietaire)
    REFERENCES Proprietaire (idProprietaire);

ALTER TABLE Bien
  ADD CONSTRAINT FK_syndic_TO_Bien
    FOREIGN KEY (idSyndic)
    REFERENCES syndic (idSyndic);

ALTER TABLE Location
  ADD CONSTRAINT FK_Locataire_TO_Location
    FOREIGN KEY (idLocataire)
    REFERENCES Locataire (idLocataire);

ALTER TABLE Location
  ADD CONSTRAINT FK_Bien_TO_Location
    FOREIGN KEY (idBien)
    REFERENCES Bien (idBien);

spool off