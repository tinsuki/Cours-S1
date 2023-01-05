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
  nom           VARCHAR2(50) NOT NULL,
  adresse       VARCHAR2(255) NOT NULL,
  contact       VARCHAR2(255) NOT NULL,
  CONSTRAINT PK_Agence PRIMARY KEY (idAgence),
  CONSTRAINT UC_Contact_agence UNIQUE (contact)
);

set echo on
DESC AGENCE
set echo off

CREATE TABLE PROPRIETAIRE
(
  idPropri    NUMBER   NOT NULL,
  nom    VARCHAR2(50) NOT NULL,
  prenom VARCHAR2(50) NOT NULL,
  tel   CHAR(10) NOT NULL,
  mail   VARCHAR2(255),
  iban   VARCHAR2(34) NOT NULL,
  CONSTRAINT PK_Proprietaire PRIMARY KEY (idPropri),
  CONSTRAINT UC_tel_propri UNIQUE (tel),
  CONSTRAINT UC_mail_propri UNIQUE (mail),
  CONSTRAINT UC_iban_propri UNIQUE (iban)
);

set echo on
DESC PROPRIETAIRE
set echo off

CREATE TABLE LOCATAIRE
(
  idLocataire        NUMBER   NOT NULL,
  nom                VARCHAR2(50) NOT NULL,
  prenom             VARCHAR2(50) NOT NULL,
  tel                CHAR(10) NOT NULL,
  mail               VARCHAR2(255),
  iban               VARCHAR2(34) NOT NULL,
  CONSTRAINT PK_Locataire PRIMARY KEY (idLocataire),
  CONSTRAINT UC_tel_loc UNIQUE (tel),
  CONSTRAINT UC_mail_loc UNIQUE (mail),
  CONSTRAINT UC_iban_loc UNIQUE (iban)
);

set echo on
DESC LOCATAIRE
set echo off

CREATE TABLE SYNDIC
(
  idSyndic      NUMBER   NOT NULL,
  nom     VARCHAR2(50) NOT NULL,
  prenom  VARCHAR2(50) NOT NULL,
  contact VARCHAR2(255) NOT NULL,
  CONSTRAINT PK_syndic PRIMARY KEY (idSyndic),
  CONSTRAINT CHK_contact_syndic UNIQUE (contact)
);

set echo on
DESC SYNDIC
set echo off

CREATE TABLE BIEN
(
  idBien         NUMBER   NOT NULL,
  adresse        VARCHAR2(255) NOT NULL,
  typeBail       NUMBER(1) NOT NULL,
  surface        NUMBER   NOT NULL,
  idAgence       NUMBER   NOT NULL,
  idPropri       NUMBER   NOT NULL,
  idSyndic       NUMBER   NOT NULL,
  CONSTRAINT PK_Bien PRIMARY KEY (idBien),
  CONSTRAINT CHK_surface CHECK (surface > 0),
  CONSTRAINT CHK_typeBail CHECK (typeBail in (1, 3))
);

set echo on
DESC BIEN
set echo off

CREATE TABLE LOCATION
(
  idLocation  NUMBER NOT NULL,
  dateDebut   DATE   NOT NULL,
  datePrevFin DATE   NOT NULL,
  dateFin     DATE,
  idLocataire NUMBER NOT NULL,
  idBien      NUMBER NOT NULL,
  CONSTRAINT PK_Location PRIMARY KEY (idLocation),
  CONSTRAINT CHK_date CHECK (datePrevFin > dateDebut)
);

set echo on
DESC LOCATION
set echo off

CREATE TABLE VISITE
(
  idBien       NUMBER   NOT NULL,
  dateVisite   DATE     NOT NULL,
  heure        NUMBER   NOT NULL,
  retour       VARCHAR2(500),
  CONSTRAINT PK_visite PRIMARY KEY (idBien, dateVisite, heure),
  CONSTRAINT CHK_heure CHECK (heure >= 0.0 and heure <= 24.0)
);

set echo on
DESC VISITE
set echo off

CREATE TABLE DPE
(
  idBien          NUMBER   NOT NULL,
  dateDebut       DATE     NOT NULL,
  DAdateFin       DATE     NOT NULL,
  classeEnergie   CHAR     NOT NULL,
  classeClimat    CHAR     NOT NULL,
  consomation     NUMBER   NOT NULL,
  emissions       NUMBER   NOT NULL,
  mention         VARCHAR2(30),
  CONSTRAINT PK_DPE PRIMARY KEY (IDBIEN, DATEDEBUT),
  CONSTRAINT CHK_classeEnergie CHECK (classeEnergie >= 'A' and classeEnergie <= 'G'),
  CONSTRAINT CHK_classeClimat CHECK (classeClimat >= 'A' and classeClimat <= 'G'),
  CONSTRAINT CHK_conso CHECK (consomation >= 0),
  CONSTRAINT CHK_emissions CHECK (emissions >= 0)
);

set echo on
DESC DPE
set echo off

spool off
