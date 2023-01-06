-- ==========================
-- fichier      : dr_gestloc.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : 19/11/22
-- role         : créer les dépendances de référence de la base de données gestloc
-- projet       : gestloc
-- ==========================

ALTER TABLE Bien
  ADD CONSTRAINT FK_Agence_TO_Bien
    FOREIGN KEY (idAgence)
    REFERENCES Agence (idAgence);

ALTER TABLE Bien
  ADD CONSTRAINT FK_Proprietaire_TO_Bien
    FOREIGN KEY (idPropri)
    REFERENCES Proprietaire (idPropri);

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

ALTER TABLE Visite
  ADD CONSTRAINT FK_Bien_TO_Visite
    FOREIGN KEY (idBien)
    REFERENCES Bien (idBien);

ALTER TABLE DPE
  ADD CONSTRAINT FK_Bien_TO_DPE
    FOREIGN KEY (idBien)
    REFERENCES Bien (idBien);