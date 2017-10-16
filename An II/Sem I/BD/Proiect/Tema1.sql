CREATE DATABASE EnterpriseFirm
use EnterpriseFirm

CREATE TABLE Managers(
	ManagerCNP uniqueidentifier NOT NULL,
	ManagerName nvarchar(50) NOT NULL,
	Department nvarchar(50) NOT NULL,


	CONSTRAINT PK_Managers PRIMARY KEY (ManagerCNP),
);
CREATE TABLE Teams(
	TeamName uniqueidentifier NOT NULL,
	TeamCapacity int NOT NULL,

	CONSTRAINT PK_Teams PRIMARY KEY(TeamName),
);

CREATE TABLE Employees(
	CNP uniqueidentifier NOT NULL,
	EmployeesName nvarchar(50) NOT NULL,
	Manager nvarchar(50) NOT NULL,
	ManagerCNP uniqueidentifier NOT NULL,
	TeamName uniqueidentifier NOT NULL,

	CONSTRAINT PK_Employees PRIMARY KEY (CNP),
	CONSTRAINT FK_Managers FOREIGN KEY (ManagerCNP)
		REFERENCES Managers (ManagerCNP),
	CONSTRAINT FK_Teams FOREIGN KEY(TeamName)
		REFERENCES Teams (TeamName)

);
CREATE TABLE Projects(
	ProjectID uniqueidentifier NOT NULL,
	Deadline nvarchar(50) NOT NULL,
	ProjectName nvarchar(50) NOT NULL,
	

	CONSTRAINT PK_Projects PRIMARY KEY(ProjectID),
	CONSTRAINT FK_Projects FOREIGN KEY(ProjectID) REFERENCES Managers(ManagerCNP)
	 


); 
CREATE TABLE Departaments(
	DepartamentID uniqueidentifier NOT NULL,
	NumberOfEmployees int,

	CONSTRAINT PK_Departaments PRIMARY KEY(DepartamentID),
	CONSTRAINT FK_Departaments FOREIGN KEY(DepartamentID) REFERENCES Managers(ManagerCNP)


);

CREATE TABLE Bagdes(
	BadgeID uniqueidentifier NOT NULL,
	BadgeNumber int NOT NULL,

	CONSTRAINT PK_Badges PRIMARY KEY(BadgeID),
	CONSTRAINT FK_Badges FOREIGN KEY(BadgeID) REFERENCES Employees(CNP)

);

CREATE TABLE ConferenceRooms(
	RoomID uniqueidentifier NOT NULL,
	RoomName nvarchar(50) NOT NULL,

	CONSTRAINT PK_ConferenceRooms PRIMARY KEY(RoomID),
);

CREATE TABLE Conference_Employees(
	RoomID uniqueidentifier NOT NULL,
	CNP uniqueidentifier NOT NULL,

	CONSTRAINT PK_Conference_Employees PRIMARY KEY (RoomID,CNP),
	CONSTRAINT FK_RoomID FOREIGN KEY(RoomID) REFERENCES ConferenceRooms(RoomID),
	CONSTRAINT FK_Employees FOREIGN KEY(CNP) REFERENCES Employees(CNP)
);

CREATE TABLE Computers(
	ComputerID uniqueidentifier NOT NULL,
	ComputerName nvarchar(50) NOT NULL,
	
	CONSTRAINT PK_Computers PRIMARY KEY(ComputerID)
);

CREATE TABLE Computers_Employees(
	ComputerID uniqueidentifier NOT NULL,
	CNP uniqueidentifier NOT NULL,

	CONSTRAINT PK_Computers_Employees PRIMARY KEY(ComputerID, CNP),
	CONSTRAINT FK_Computers_Employes FOREIGN KEY(ComputerID) REFERENCES Computers(ComputerID),
	CONSTRAINT FK_Employees_Computer FOREIGN KEY(CNP) REFERENCES Employees(CNP)
);




DROP TABLE Conference_Employees;
DROP TABLE Employees;
DROP TABLE Bagdes;
DROP TABLE Managers;
DROP TABLE Projects;
DROP TABLE Teams;
DROP TABLE Departaments;
DROP TABLE ConferenceRooms;