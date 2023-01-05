-- ==========================
-- fichier      : ddl_gestloc.sql
-- base         : gestloc
-- auteur(s)    : SIMON Kevin
-- date         : 19/11/22
-- role         : créer les tables de la bd gestloc sans les dépendances de référence
-- projet       : gestloc
-- resultat dans: ddl_gestloc.out
-- ==========================

spool ddl_gestloc.out

CREATE TABLE AGENCE
(
  idAgence      NUMBER   NOT NULL,
  nomAgence     VARCHAR2(50) NOT NULL,
  adrAgence     VARCHAR2(255) NOT NULL,
  contactAgence VARCHAR2(255) NOT NULL,
  CONSTRAINT PK_Agence PRIMARY KEY (idAgence)
);

set echo on
DESC AGENCE
set echo off

CREATE TABLE PROPRIETAIRE
(
  idProprietaire     NUMBER   NOT NULL,
  nomProprietaire    VARCHAR2(50) NOT NULL,
  prenomProprietaire VARCHAR2(50) NOT NULL,
  telProprietaire    CHAR(10) NOT NULL,
  mailProprietaire   VARCHAR2(255),
  ibanProprietaire   VARCHAR2(34) NOT NULL,
  CONSTRAINT PK_Proprietaire PRIMARY KEY (idProprietaire)
);

set echo on
DESC PROPRIETAIRE
set echo off

CREATE TABLE LOCATAIRE
(
  idLocataire        NUMBER   NOT NULL,
  nomLocataire       VARCHAR2(50) NOT NULL,
  prenomLocataire    VARCHAR2(50) NOT NULL,
  telLocataire CHAR(10) NOT NULL,
  mailLocataire      VARCHAR2(255),
  ibanLocataire      VARCHAR2(34) NOT NULL,
  CONSTRAINT PK_Locataire PRIMARY KEY (idLocataire)
);

set echo on
DESC LOCATAIRE
set echo off

CREATE TABLE SYNDIC
(
  idSyndic      NUMBER   NOT NULL,
  nomSyndic     VARCHAR2(50) NOT NULL,
  prenomSyndic  VARCHAR2(50) NOT NULL,
  contactSyndic VARCHAR2(255) NOT NULL,
  CONSTRAINT PK_syndic PRIMARY KEY (idSyndic)
);

set echo on
DESC SYNDIC
set echo off

CREATE TABLE BIEN
(
  idBien         NUMBER   NOT NULL,
  adrBien        VARCHAR2(255) NOT NULL,
  bail           NUMBER(1)   NOT NULL,
  loyer          NUMBER(10,2)   NOT NULL,
  surface        NUMBER   NOT NULL,
  nbrVisite      NUMBER   NOT NULL,
  idAgence       NUMBER   NOT NULL,
  idProprietaire NUMBER   NOT NULL,
  idSyndic       NUMBER   NOT NULL,
  CONSTRAINT PK_Bien PRIMARY KEY (idBien),
  CONSTRAINT CHK_loyer CHECK (loyer > 0),
  CONSTRAINT CHK_surface CHECK (surface > 0),
  CONSTRAINT CHK_nbrVisiste CHECK (nbrVisite >= 0),
  CONSTRAINT CHK_bail CHECK (bail in (1, 3))
);

set echo on
DESC BIEN
set echo off

CREATE TABLE LOCATION
(
  idLocation  NUMBER NOT NULL,
  dateDebut   DATE   NOT NULL,
  datePrevFin DATE   NOT NULL,
  idLocataire NUMBER NOT NULL,
  idBien      NUMBER NOT NULL,
  CONSTRAINT PK_Location PRIMARY KEY (idLocation)
);

set echo on
DESC LOCATION
set echo off

spool off
