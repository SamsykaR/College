--create database Restauran;
use Restauran;

CREATE TABLE Category (
    CategoryID INT PRIMARY KEY,
    CategoryName VARCHAR(100) NOT NULL
);

CREATE TABLE Food (
    FoodID INT PRIMARY KEY,
    Name VARCHAR(100) NOT NULL,
    Description TEXT,
    Price DECIMAL(10, 2) NOT NULL check(Price < 0),
    Ingredients TEXT,
    Weight DECIMAL(10, 2) check(Weight < 0),
    Availability BIT,
    CategoryID INT,
    FOREIGN KEY (CategoryID) REFERENCES Category(CategoryID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Addres (
    AddresID INT PRIMARY KEY,
    District VARCHAR(100) NOT NULL,
    City VARCHAR(100) NOT NULL,
    Street VARCHAR(100) NOT NULL,
    House VARCHAR(6) NOT NULL,
    Apartment VARCHAR(5)
);

CREATE TABLE WorkDays (
    WorkDaysID INT PRIMARY KEY,
    WorkingDays VARCHAR(100) default('пн, вт, ср, чт, пт') NOT NULL,
    StartTime TIME default('8:00') NOT NULL,
    EndTime TIME default('17:00') NOT NULL,
    BreakStartTime TIME default('11:00') NOT NULL,
    BreakEndTime TIME default('13:00') NOT NULL
);

CREATE TABLE Workers (
    WorkerID INT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    FatherName VARCHAR(50),
    Phone VARCHAR(15),
    HireDate DATE NOT NULL,
    Passport VARCHAR(50) NOT NULL,
    AddresID INT,
    WorkDaysID INT,
    FOREIGN KEY (AddresID) REFERENCES Addres(AddresID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (WorkDaysID) REFERENCES WorkDays(WorkDaysID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    OrderDate DATE DEFAULT(GETDATE()),
    OrderTime TIME DEFAULT(GeTDATE()),
    Statuus VARCHAR(50) NOT NULL,
    PaymentMethod VARCHAR(50) NOT NULL,
    Discount DECIMAL(10, 2) DEFAULT(0),
    TotalPrice DECIMAL(10, 2), --протестить в сервере
    DiscountedPrice AS (TotalPrice - (TotalPrice*Discount/100)),
    WorkerID INT,
    FOREIGN KEY (WorkerID) REFERENCES Workers(WorkerID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE OrderedFood (
    OrderedFoodID INT PRIMARY KEY,
    Quantity INT NOT NULL,
    Price DECIMAL(10, 2) NOT NULL,
    FoodID INT,
    OrderID INT,
    FOREIGN KEY (FoodID) REFERENCES Food(FoodID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (OrderID) REFERENCES Orders(OrderID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE BookingGuest (
    GuestID INT PRIMARY KEY,
    LastName VARCHAR(50) NOT NULL,
    FirstName VARCHAR(50) NOT NULL,
    FatherName VARCHAR(50),
    GuestPhone VARCHAR(15),
    Age INT NOT NULL
);

CREATE TABLE Reservations (
    ReservationID INT PRIMARY KEY,
    TableNumber INT NOT NULL,
    PreorderAvailable BIT default(1),
    NumberOfPeople INT default(1),
    ReservationDate DATE default(GETDATE()),
    ReservationTime TIME default(GETDATE()),
    Zonee VARCHAR(50) default('Зал'),
    GuestID INT,
    FOREIGN KEY (GuestID) REFERENCES BookingGuest(GuestID) ON DELETE CASCADE ON UPDATE CASCADE
);

