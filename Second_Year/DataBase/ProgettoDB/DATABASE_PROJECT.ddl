-- *********************************************
-- * SQL MySQL generation                      
-- *--------------------------------------------
-- * DB-MAIN version: 11.0.2              
-- * Generator date: Sep 14 2021              
-- * Generation date: Fri Jun  3 12:24:06 2022 
-- * LUN file: C:\Users\fabbr\OneDrive\Documenti\Università\anno_2\Basi di dati\Elaborato\DATABASE_PROJECT_rel.lun 
-- * Schema: GESTIONALE_PER_AGENZIE_Rel/1-1-1 
-- ********************************************* 


-- Database Section
-- ________________ 

create database GESTIONALE_PER_AGENZIE_Rel;
use GESTIONALE_PER_AGENZIE_Rel;


-- Tables Section
-- _____________ 

create table ACCESSORIO (
     Tipologia varchar(10) not null,
     UltimoControllo date not null,
     Produttore varchar(10) not null,
     Taglia char(1),
     IDaccessorio char(6) not null,
     IDmagazzino char(3) not null,
     constraint IDACCESSORI primary key (IDaccessorio));

create table AcquistoBiglietto (
     PIVA char(11) not null,
     IDtour char(4) not null,
     constraint IDAcquistoBiglietto primary key (IDtour, PIVA));

create table AGENZIA (
     PIVA char(11) not null,
     Nome varchar(20) not null,
     NumTotDipendenti bigint not null,
     constraint IDAGENZIA_ID primary key (PIVA));

create table ATTRAZIONE (
     Recapito char(12) not null,
     NomeSocio varchar(10) not null,
     PIVA char(11) not null,
     CostoServizio float not null,
     TipoAttrazione varchar(10) not null,
     EtàMinima bigint not null,
     IDIndirizzo char(7) not null,
     constraint IDBUSINESSPARTNER_ID primary key (PIVA));

create table BICICLETTA (
     Produttore varchar(10) not null,
     NumTelaio char(5) not null,
     Taglia char(1) not null,
     RaggioRuota int not null,
     Tipologia varchar(10) not null,
     UltimoControllo date not null,
     NumRapportiAnteriori int not null,
     NumRapportiPosteriori int not null,
     isElettrica char not null,
     PotenzaBatteria int,
     CapacitàBatteria int,
     DurataBatteria int,
     IDmagazzino char(3) not null,
     constraint IDBICICLETTE primary key (NumTelaio));

create table CLIENTE (
     Nome varchar(10) not null,
     Cognome varchar(10) not null,
     CF char(16) not null,
     NumTelefono char(12) not null,
     constraint IDCLIENTE primary key (CF));

create table DIPENDENTE (
     Nome varchar(10) not null,
     Cognome varchar(10) not null,
     CF char(16) not null,
     Recapito char(12) not null,
     CodiceDipendente char(4) not null,
     Stipendio float not null,
     isGuida char not null,
     isTourManager char not null,
     isAltro char not null,
     IDsede char(3) not null,
     constraint IDDIPENDENTE primary key (CF),
     constraint IDDIPENDENTE_1 unique (CodiceDipendente));

create table Gerarchia (
     CFsottoposto char(16) not null,
     CFsuperiore char(16),
     constraint IDGerarchia primary key (CFsottoposto));

create table INDIRIZZO (
     NumCivico varchar(3) not null,
     Via varchar(20) not null,
     CAP char(5) not null,
     Paese varchar(10) not null,
     IDIndirizzo char(7) not null,
     constraint IDINDIRIZZO_ID primary key (IDIndirizzo));

create table MAGAZZINO (
     CapienzaMassimaAccessori bigint not null,
     CapienzaMassimaBici bigint not null,
     IDmagazzino char(3) not null,
     IDIndirizzo char(7) not null,
     IDsede char(3) not null,
     constraint IDMAGAZZINO primary key (IDmagazzino),
     constraint FKIndirizzoMagazzino_ID unique (IDIndirizzo));

create table NoleggioAccessorio (
     IDservizio char(6) not null,
     IDaccessorio char(6) not null,
     constraint IDNoleggioAccessorio primary key (IDservizio, IDaccessorio));

create table NoleggioBicicletta (
     IDservizio char(6) not null,
     NumTelaio char(5) not null,
     constraint IDNoleggioBicicletta primary key (IDservizio, NumTelaio));

create table PACCHETTO (
     Prezzo float not null,
     Sconto int not null,
     IDpacchetto char(6) not null,
     CFcliente char(16) not null,
     constraint IDPACCHETTO primary key (IDpacchetto));

create table Partecipazione (
     IDpercorsoGuidato char(6) not null,
     CFguida char(16) not null,
     constraint IDPartecipazione primary key (IDpercorsoGuidato, CFguida));

create table PartnershipAttrazione (
     PIVApartner char(11) not null,
     PIVAagenzia char(11) not null,
     constraint IDPartnershipAttrazione primary key (PIVApartner, PIVAagenzia));

create table PartnershipRistorante (
     PIVApartner char(11) not null,
     PIVAagenzia char(11) not null,
     constraint IDPartnershipRistorante primary key (PIVApartner, PIVAagenzia));

create table PartnershipSoggiorno (
     PIVApartner char(11) not null,
     PIVAagenzia char(11) not null,
     constraint IDPartnershipSoggiorno primary key (PIVApartner, PIVAagenzia));

create table PERCORSO (
     IDpercorso char(3) not null,
     Difficolta varchar(10) not null,
     Nome varchar(10) not null,
     NumTappe int not null,
     LunghezzaPercorso int not null,
     IDsede char(3) not null,
     constraint IDPERCORSO primary key (IDpercorso));

create table Pernottamento (
     PIVA char(11) not null,
     IDtour char(4) not null,
     constraint IDPernottamento primary key (PIVA, IDtour));

create table Prenotazione (
     CFcliente char(16) not null,
     IDtour char(4) not null,
     constraint IDPrenotazione primary key (CFcliente, IDtour));

create table RISTORANTE (
     Recapito char(12) not null,
     NomeSocio varchar(12) not null,
     PIVA char(11) not null,
     CostoServizio float not null,
     IDIndirizzo char(7) not null,
     constraint IDBUSINESSPARTNER_ID primary key (PIVA));

create table Ristorazione (
     PIVA char(11) not null,
     IDtour char(4) not null,
     constraint IDRistorazione primary key (PIVA, IDtour));

create table SEDE (
     IDsede char(3) not null,
     PIVAagenzia char(11) not null,
     IDIndirizzo char(7) not null,
     constraint IDSEDE_ID primary key (IDsede));

create table Sequenza (
     IDtappa char(4) not null,
     Indice int not null,
     IDpercorso char(3) not null,
     constraint IDSequenza primary key (IDtappa, IDpercorso));

create table SERVIZIO (
     DataInizio date not null,
     DataFine date not null,
     CostoGiornaliero float not null,
     IDservizio char(6) not null,
     tipoServizio ENUM('NOLEGGIO_ACCESSORI', 'NOLEGGIO_BICICLETTE', 'PERCORSO_GUIDATO') not null,
     IDpacchetto char(6) not null,
     IDsede char(3) not null,
     IDpercorso char(5),
     constraint IDSERVIZIO primary key (IDservizio));

create table SOGGIORNO (
     Recapito char(1) not null,
     NomeSocio varchar(10) not null,
     PIVA char(11) not null,
     CostoServizio float not null,
     TipoSoggiorno varchar(10) not null,
     IDIndirizzo char(7) not null,
     constraint IDBUSINESSPARTNER_ID primary key (PIVA));

create table TAPPA (
     Inizio varchar(10) not null,
     Fine varchar(10) not null,
     LunghezzaTappa float not null,
     IDtappa char(4) not null,
     constraint IDTAPPA primary key (IDtappa));

create table TOUR (
     Destinazione varchar(10) not null,
     Nome varchar(10) not null,
     DataInizio date not null,
     DataFine date not null,
     Prezzo float not null,
     IDtour char(4) not null,
     IDsede char(3) not null,
     CFtourManager char(16) not null,
     constraint IDTOUR primary key (IDtour),
     constraint IDTOUR_1 unique (Nome, DataInizio));


-- Constraints Section
-- ___________________ 

alter table ACCESSORIO add constraint FKStoccaggioAccessorio
     foreign key (IDmagazzino)
     references MAGAZZINO (IDmagazzino);

alter table acquistoBiglietto add constraint FKAcq_TOU
     foreign key (IDtour)
     references TOUR (IDtour);

alter table acquistoBiglietto add constraint FKAcq_ATT
     foreign key (PIVA)
     references ATTRAZIONE (PIVA);

-- Not implemented
-- alter table AGENZIA add constraint IDAGENZIA_CHK
--     check(exists(select * from SEDE
--                  where SEDE.PIVAagenzia = PIVA)); 

-- Not implemented
-- alter table ATTRAZIONE add constraint IDBUSINESS PARTNER_CHK
--     check(exists(select * from PartnershipAttrazione
--                  where PartnershipAttrazione.PIVApartner = PIVA)); 

alter table ATTRAZIONE add constraint FKIndirizzoAttrazione
     foreign key (IDIndirizzo)
     references INDIRIZZO (IDIndirizzo);

alter table BICICLETTA add constraint FKStoccaggioBicicletta
     foreign key (IDmagazzino)
     references MAGAZZINO (IDmagazzino);

alter table DIPENDENTE add constraint FKLavoro
     foreign key (IDsede)
     references SEDE (IDsede);

alter table Gerarchia add constraint FKSottoposto
     foreign key (CFsottoposto)
     references DIPENDENTE (CF);

alter table Gerarchia add constraint FKSuperiore
     foreign key (CFsuperiore)
     references DIPENDENTE (CF);

-- Not implemented
-- alter table INDIRIZZO add constraint IDINDIRIZZO_CHK
--     check(exists(select * from SEDE
--                  where SEDE.IDIndirizzo = IDIndirizzo)); 

alter table MAGAZZINO add constraint FKIndirizzoMagazzino_FK
     foreign key (IDIndirizzo)
     references INDIRIZZO (IDIndirizzo);

alter table MAGAZZINO add constraint FKStoccaggioM
     foreign key (IDsede)
     references SEDE (IDsede);

alter table NoleggioAccessorio add constraint FKServizioAccessorio
     foreign key (IDservizio)
     references SERVIZIO (IDservizio);

alter table NoleggioAccessorio add constraint FKAccessorio
     foreign key (IDaccessorio)
     references ACCESSORIO (IDaccessorio);

alter table NoleggioBicicletta add constraint FKServizioBicicletta
     foreign key (IDservizio)
     references SERVIZIO (IDservizio);

alter table NoleggioBicicletta add constraint FKBicicletta
     foreign key (NumTelaio)
     references BICICLETTA (NumTelaio);

alter table PACCHETTO add constraint FKRichiesta
     foreign key (CFcliente)
     references CLIENTE (CF);

alter table Partecipazione add constraint FKPar_DIP
     foreign key (CFguida)
     references DIPENDENTE (CF);

alter table Partecipazione add constraint FKPar_SER
     foreign key (IDpercorsoGuidato)
     references SERVIZIO (IDservizio);

alter table PartnershipAttrazione add constraint FKPartAttrazioneAgenzia
     foreign key (PIVAagenzia)
     references AGENZIA (PIVA);

alter table PartnershipAttrazione add constraint FKPar_ATT
     foreign key (PIVApartner)
     references ATTRAZIONE (PIVA);

alter table PartnershipRistorante add constraint FKPartRistoranteAgenzia
     foreign key (PIVAagenzia)
     references AGENZIA (PIVA);

alter table PartnershipRistorante add constraint FKPar_RIS
     foreign key (PIVApartner)
     references RISTORANTE (PIVA);

alter table PartnershipSoggiorno add constraint FKPartSoggiornoAgenzia
     foreign key (PIVAagenzia)
     references AGENZIA (PIVA);

alter table PartnershipSoggiorno add constraint FKPar_SOG
     foreign key (PIVApartner)
     references SOGGIORNO (PIVA);

alter table PERCORSO add constraint FKOffertaPercorsi
     foreign key (IDsede)
     references SEDE (IDsede);

alter table Pernottamento add constraint FKPer_TOU
     foreign key (IDtour)
     references TOUR (IDtour);

alter table Pernottamento add constraint FKPer_SOG
     foreign key (PIVA)
     references SOGGIORNO (PIVA);

alter table Prenotazione add constraint FKPre_TOU
     foreign key (IDtour)
     references TOUR (IDtour);

alter table Prenotazione add constraint FKPre_CLI
     foreign key (CFcliente)
     references CLIENTE (CF);

-- Not implemented
-- alter table RISTORANTE add constraint IDBUSINESS PARTNER_CHK
--     check(exists(select * from PartnershipRistorante
--                  where PartnershipRistorante.PIVApartner = PIVA)); 

alter table RISTORANTE add constraint FKIndirizzoRistorante
     foreign key (IDIndirizzo)
     references INDIRIZZO (IDIndirizzo);

alter table Ristorazione add constraint FKRis_TOU
     foreign key (IDtour)
     references TOUR (IDtour);

alter table Ristorazione add constraint FKRis_RIS
     foreign key (PIVA)
     references RISTORANTE (PIVA);

-- Not implemented
-- alter table SEDE add constraint IDSEDE_CHK
--     check(exists(select * from MAGAZZINO
--                  where MAGAZZINO.IDsede = IDsede)); 

-- Not implemented
-- alter table SEDE add constraint IDSEDE_CHK
--     check(exists(select * from DIPENDENTE
--                  where DIPENDENTE.IDsede = IDsede)); 

-- Not implemented
-- alter table SEDE add constraint IDSEDE_CHK
--     check(exists(select * from SERVIZIO
--                  where SERVIZIO.IDsede = IDsede)); 

-- Not implemented
-- alter table SEDE add constraint IDSEDE_CHK
--     check(exists(select * from PERCORSO
--                  where PERCORSO.IDsede = IDsede)); 

-- Not implemented
-- alter table SEDE add constraint IDSEDE_CHK
--     check(exists(select * from TOUR
--                  where TOUR.IDsede = IDsede)); 

alter table SEDE add constraint FKFiliale
     foreign key (PIVAagenzia)
     references AGENZIA (PIVA);

alter table SEDE add constraint FKIndirizzoSede
     foreign key (IDIndirizzo)
     references INDIRIZZO (IDIndirizzo);

alter table Sequenza add constraint FKSeq_TAP
     foreign key (IDtappa)
     references TAPPA (IDtappa);

alter table Sequenza add constraint FKPercorso
     foreign key (IDpercorso)
     references PERCORSO (IDpercorso);

alter table SERVIZIO add constraint FKComposizioneServizio
     foreign key (IDpacchetto)
     references PACCHETTO (IDpacchetto);

alter table SERVIZIO add constraint FKOffertaServizio
     foreign key (IDsede)
     references SEDE (IDsede);

alter table SERVIZIO add constraint FKScelta
     foreign key (IDpercorso)
     references PERCORSO (IDpercorso);

-- Not implemented
-- alter table SOGGIORNO add constraint IDBUSINESS PARTNER_CHK
--     check(exists(select * from PartnershipSoggiorno
--                  where PartnershipSoggiorno.PIVApartner = PIVA)); 

alter table SOGGIORNO add constraint FKIndirizzoSoggiorno
     foreign key (IDIndirizzo)
     references INDIRIZZO (IDIndirizzo);

alter table TOUR add constraint FKOffertaTour
     foreign key (IDsede)
     references SEDE (IDsede);

alter table TOUR add constraint FKViaggio
     foreign key (CFtourManager)
     references DIPENDENTE (CF);


-- Index Section
-- _____________ 

