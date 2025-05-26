--use Restauran;

/*
---зарплата сл
SELECT Workers.LastName, Workers.FirstName, 
DATEDIFF(HOUR, WorkDays.StartTime, WorkDays.EndTime) * (LEN(WorkDays.WorkingDays) - LEN(REPLACE(WorkDays.WorkingDays, ',', '')) + 1) * Workers.RatePerHour AS 'Pay in week'
FROM Workers INNER JOIN WorkDays ON Workers.WorkDaysID = WorkDays.WorkDaysID;
*/


/*
---премия сл
SELECT TOP 3 Workers.LastName, Workers.FirstName, 
((DATEDIFF(HOUR, WorkDays.StartTime, WorkDays.EndTime)*6)*Workers.RatePerHour) AS 'Premia',
(COUNT(Orders.OrderID)) AS OrderCount
FROM (Workers INNER JOIN WorkDays ON Workers.WorkDaysID = WorkDays.WorkDaysID) INNER JOIN Orders ON Workers.WorkerID = Orders.WorkerID
GROUP BY Workers.LastName, Workers.FirstName, WorkDays.EndTime, WorkDays.StartTime, Workers.RatePerHour
ORDER BY OrderCount;
*/


/*
---топ блюд и их доля сл
WITH Temp AS (
SELECT Food.FoodID, Food.Name, Category.CategoryName, SUM(OrderedFood.Quantity * OrderedFood.Price) AS FoodPrice,
(SELECT SUM(TotalPrice) FROM Orders) AS TotalPrice 
FROM OrderedFood INNER JOIN Food ON OrderedFood.FoodID = Food.FoodID INNER JOIN Category ON Food.CategoryID = Category.CategoryID
GROUP BY Food.FoodID, Food.Name, Category.CategoryName
)
SELECT TOP 3 *, (FoodPrice / TotalPrice) * 100 AS TotalPiece
FROM Temp
ORDER BY TotalPiece DESC;
*/

/*
--выручка на каждый день недели пр
SELECT DATENAME(WEEKDAY, OrderDate) AS WeekDays, AVG(TotalPrice) AS AvgPrice
FROM Orders
GROUP BY DATENAME(WEEKDAY, OrderDate)
ORDER BY WeekDays;
*/






/*
---Количество и выручка всех заказов пр
SELECT COUNT(Orders.OrderID) AS OrdersCount, SUM(Orders.TotalPrice) AS Total, SUM(Orders.DiscountedPrice) AS RealPrice
FROM Orders;
*/


/*
---Выручка по зонам пр/сл
SELECT Reservations.Zonee, SUM(Orders.DiscountedPrice) AS RealPrice
FROM Reservations INNER JOIN Orders ON Reservations.OrderID = Orders.OrderID
WHERE Reservations.PreorderAvailable = 1
GROUP BY Reservations.Zonee;
*/


/*
---Выручка на каждый день месяца пр
DECLARE @MONTH INT
SET @MONTH = 10
SELECT Orders.OrderDate, SUM(Orders.DiscountedPrice) AS RealPrice
FROM Orders
WHERE MONTH(Orders.OrderDate) = @MONTH
GROUP BY Orders.OrderDate;
*/


/*
---Месяцы до отпуска пр
SELECT Workers.WorkerID, Workers.LastName, 
(6 - (DATEDIFF(MONTH, HireDate, GETDATE()) % 6)) AS 'Month'
FROM Workers
*/


/*
---Тяжёлые в каждой категории
*/


/*
---Брони и предположения пр
SELECT *, iif(Reservations.NumberOfPeople=1, 'Один', iif(Reservations.NumberOfPeople<5, 'Группа', 'Компания')) AS 'Peoples'
FROM Reservations;
*/

--сложных 3, простых 5, итог 8








/*
--Подробности о заказах
CREATE VIEW OrderDetails AS
SELECT Orders.OrderID, Orders.OrderDate, Orders.OrderTime, Food.Name, OrderedFood.Quantity, OrderedFood.Price, Reservations.PreorderAvailable
FROM Orders 
INNER JOIN OrderedFood ON Orders.OrderID = OrderedFood.OrderID
INNER JOIN Food ON OrderedFood.FoodID = Food.FoodID
LEFT JOIN Reservations ON Orders.OrderID = Reservations.OrderID;
*/


/*
--Вся информация о сотрудниках
CREATE VIEW WorkersInfo AS
SELECT Workers.WorkerID, CONCAT(Workers.LastName, ' ', Workers.FirstName, ' ', Workers.FatherName) AS FullName, CONCAT(Addres.City, ', ', Addres.Street, ', д. ', Addres.House) AS FullAddress, WorkDays.WorkingDays
FROM Workers 
INNER JOIN Addres ON Workers.AddresID = Addres.AddresID
INNER JOIN WorkDays ON Workers.WorkDaysID = WorkDays.WorkDaysID;
*/


/*
--Все гости и брони
CREATE VIEW GuestReservations AS
SELECT BookingGuest.GuestID, CONCAT(BookingGuest.LastName, ' ', BookingGuest.FirstName) AS GuestName, Reservations.ReservationDate, Reservations.Zonee, Reservations.NumberOfPeople
FROM BookingGuest INNER JOIN Reservations ON BookingGuest.GuestID = Reservations.GuestID;
*/


/*
--Финансы (за месяц)
CREATE VIEW FinancialReport AS
WITH 
WeeklyWorkers AS (
SELECT Workers.WorkerID, Workers.LastName, Workers.FirstName, 
DATEDIFF(HOUR, WorkDays.StartTime, WorkDays.EndTime) * 
(LEN(WorkDays.WorkingDays) - LEN(REPLACE(WorkDays.WorkingDays, ',', '')) + 1) * Workers.RatePerHour AS WeeklyPay
FROM Workers INNER JOIN WorkDays ON Workers.WorkDaysID = WorkDays.WorkDaysID
),
MonthlyOrders AS (
SELECT SUM(ISNULL(TotalPrice, 0)) AS TotalRevenue, SUM(TotalPrice - DiscountedPrice) AS TotalDiscounts
FROM Orders
WHERE MONTH(OrderDate) = MONTH(OrderDate) --заменить на GETDATE()
)
SELECT MonthlyOrders.TotalRevenue, MonthlyOrders.TotalRevenue - MonthlyOrders.TotalDiscounts AS PriceAfterDiscounts,
SUM(WeeklyWorkers.WeeklyPay * 4) AS Salary,
(MonthlyOrders.TotalRevenue - MonthlyOrders.TotalDiscounts) - SUM(WeeklyWorkers.WeeklyPay * 4) AS 'Total Revenue'
FROM MonthlyOrders, WeeklyWorkers
GROUP BY MonthlyOrders.TotalRevenue, MonthlyOrders.TotalDiscounts;
*/


/*
--Статистика бронирований
CREATE VIEW ReservationStats AS
SELECT Reservations.Zonee, COUNT(Reservations.ReservationID) AS TotalReservations, AVG(Reservations.NumberOfPeople) AS AvgGuests, (SUM(CASE WHEN PreorderAvailable = 1 THEN 1 ELSE 0 END) * 100.0 / COUNT(Reservations.ReservationID)) AS PreorderProcent
FROM Reservations
GROUP BY Zonee;
*/


