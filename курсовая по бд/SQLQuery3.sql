/*
CREATE TRIGGER Totalprice
ON dbo.Orders
AFTER INSERT
AS
    DECLARE @Total DECIMAL(10, 2);
    DECLARE @OrderID INT;

    -- Получить OrderID из вставленных данных
    SELECT @OrderID = OrderID FROM inserted;

    -- Вычислить общую цену для данного OrderID
    SELECT @Total = SUM(Price * Quantity)
    FROM OrderedFood
    WHERE OrderID = @OrderID;

    -- Обновить таблицу Orders с общей ценой
    UPDATE Orders
    SET TotalPrice = @Total
    WHERE OrderID = @OrderID;
	*/




CREATE TRIGGER Totalprice
ON Orders
AFTER INSERT
AS
BEGIN
    UPDATE o
    SET TotalPrice = (
        SELECT SUM(Price * Quantity)
        FROM OrderedFood ordf
        WHERE ordf.OrderID = i.OrderID
    )
    FROM Orders o
    INNER JOIN inserted i ON o.OrderID = i.OrderID;
END



