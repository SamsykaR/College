--create database Restauran;
use Restauran;

CREATE TABLE Category (
    CategoryID INT PRIMARY KEY CLUSTERED IDENTITY(1, 1),
    CategoryName VARCHAR(100) NOT NULL
);

CREATE TABLE Food (
    FoodID INT PRIMARY KEY CLUSTERED IDENTITY(1, 1),
    Name VARCHAR(100) NOT NULL,
    Description TEXT,
    Price SMALLMONEY NOT NULL check(Price > 0),
    Ingredients TEXT,
    Weight DECIMAL(10, 2) check(Weight > 0),
    Availability BIT,
    CategoryID INT,
    FOREIGN KEY (CategoryID) REFERENCES Category(CategoryID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Addres (
    AddresID INT PRIMARY KEY CLUSTERED IDENTITY(1, 1),
    District VARCHAR(100),
    City VARCHAR(100) NOT NULL,
    Street VARCHAR(100) NOT NULL,
    House VARCHAR(6) NOT NULL,
    Apartment VARCHAR(5)
);

CREATE TABLE WorkDays (
    WorkDaysID INT PRIMARY KEY CLUSTERED IDENTITY(1, 1),
    WorkingDays VARCHAR(100) default('пн, вт, ср, чт, пт') NOT NULL,
    StartTime TIME default('8:00') NOT NULL,
    EndTime TIME default('17:00') NOT NULL,
    BreakStartTime TIME default('11:00') NOT NULL,
    BreakEndTime TIME default('13:00') NOT NULL
);

CREATE TABLE Workers (
    WorkerID INT PRIMARY KEY CLUSTERED IDENTITY(1, 1),
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    FatherName VARCHAR(50),
    Phone VARCHAR(15) CHECK (Phone LIKE '[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]'),
    HireDate DATE NOT NULL,
    Passport VARCHAR(50) NOT NULL,
	RatePerHour SMALLMONEY check(RatePerHour > 0),
    AddresID INT,
    WorkDaysID INT,
    FOREIGN KEY (AddresID) REFERENCES Addres(AddresID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (WorkDaysID) REFERENCES WorkDays(WorkDaysID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Orders (
    OrderID INT PRIMARY KEY CLUSTERED IDENTITY(1, 1),
    OrderDate DATE DEFAULT(GETDATE()),
    OrderTime TIME DEFAULT(CAST(GETDATE() AS TIME)),
    Statuus VARCHAR(50) NOT NULL,
    PaymentMethod VARCHAR(50) NOT NULL,
    Discount DECIMAL(10, 2) DEFAULT(0),
    TotalPrice SMALLMONEY, --протестить в сервере
    DiscountedPrice AS (TotalPrice - (TotalPrice*Discount/100)),
    WorkerID INT,
    FOREIGN KEY (WorkerID) REFERENCES Workers(WorkerID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE OrderedFood (
    OrderedFoodID INT PRIMARY KEY CLUSTERED IDENTITY(1, 1),
    Quantity TINYINT NOT NULL,
    Price SMALLMONEY NOT NULL,
    FoodID INT,
    OrderID INT,
    FOREIGN KEY (FoodID) REFERENCES Food(FoodID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (OrderID) REFERENCES Orders(OrderID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE BookingGuest (
    GuestID INT PRIMARY KEY CLUSTERED IDENTITY(1, 1),
    LastName VARCHAR(50) NOT NULL,
    FirstName VARCHAR(50) NOT NULL,
    FatherName VARCHAR(50),
    GuestPhone VARCHAR(15),
    Age TINYINT NOT NULL
);

CREATE TABLE Reservations (
    ReservationID INT PRIMARY KEY CLUSTERED IDENTITY(1, 1),
    TableNumber TINYINT NOT NULL,
    PreorderAvailable BIT default(0),
    NumberOfPeople INT default(1),
    ReservationDate DATE default(GETDATE()),
    ReservationTime TIME default(GETDATE()),
    Zonee VARCHAR(50) default('Зал'),
    GuestID INT,
	OrderID INT,
    FOREIGN KEY (GuestID) REFERENCES BookingGuest(GuestID) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (OrderID) REFERENCES Orders(OrderID)ON DELETE CASCADE ON UPDATE CASCADE,
		CONSTRAINT CheckPreOrder 
        CHECK (
            (PreorderAvailable = 1 AND OrderID IS NOT NULL) OR (PreorderAvailable = 0 AND OrderID IS NULL)
        ),
);
CREATE UNIQUE INDEX PreOrd
ON Reservations(OrderID) 
WHERE OrderID IS NOT NULL;

CREATE UNIQUE INDEX WorkPasport
ON Workers(Passport);


