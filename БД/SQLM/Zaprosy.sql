use hotel;

declare @IDG int --ID гостя
set @IDG = 1
declare @LastG varchar -- фамилия гостя
set @LastG = 'Иванов*'
declare @NumberID int -- номер номера?
set @NumberID = 101
declare @RoomT varchar --Тип номера
set @RoomT = 'Вип'
declare @DataStart datetime -- Начало периода
set @DataStart = '01.01.2020'
declare @DataEnd datetime -- Конец периода
set @DataEnd = '01.01.2024'
declare @NameG varchar --Имя гостя
set @NameG = 'Иван'
declare @DataNow datetime -- Дата сейчас
set @DataNow = '01.01.2024'

declare @Projili int -- Итог чего то (не использовать)
set @Projili = NULL--((Dbo.Bronirovanie.DataOut-Dbo.Bronirovanie.DataIn)*dbo.Room.Cost)
declare @TotalCostUslug int -- Итог чего то (не использовать)
set @TotalCostUslug = NULL--Sum(Dbo.pay_usluga.TotalCost)




--гость по ID
SELECT dbo.Guest.GuestId, dbo.Guest.LastNameG, dbo.Guest.FirstNameG, dbo.Guest.FatherNameG, dbo.Guest.PasportG, dbo.Guest.AdresG, dbo.Guest.TelephoneG
FROM dbo.Guest
GROUP BY dbo.Guest.GuestId, dbo.Guest.LastNameG, dbo.Guest.FirstNameG, dbo.Guest.FatherNameG, dbo.Guest.PasportG, dbo.Guest.AdresG, dbo.Guest.TelephoneG
HAVING (((dbo.Guest.GuestId)=@IDG));
-------------------------------------------------------------------------------

--гость по Фамилии
SELECT dbo.Guest.GuestId, dbo.Guest.LastNameG, dbo.Guest.FirstNameG, dbo.Guest.FatherNameG, dbo.Guest.PasportG, dbo.Guest.AdresG, dbo.Guest.TelephoneG
FROM dbo.Guest
GROUP BY dbo.Guest.GuestId, dbo.Guest.LastNameG, dbo.Guest.FirstNameG, dbo.Guest.FatherNameG, dbo.Guest.PasportG, dbo.Guest.AdresG, dbo.Guest.TelephoneG
HAVING (((dbo.Guest.LastNameG)=@LastG));
-------------------------------------------------------------------------------

--Номер по типу
SELECT dbo.Bronirovanie.DataIn, dbo.Bronirovanie.DataOut, dbo.Bronirovanie.Statu_s, dbo.Bronirovanie.GuestId, dbo.Bronirovanie.DataB, Dbo.Zaselenie.DataZas, dbo.Bronirovanie.RoomID
FROM dbo.Bronirovanie INNER JOIN dbo.Zaselenie ON dbo.Bronirovanie.BronirovanieId = dbo.Zaselenie.BronirovanieId
WHERE (((@NumberID)=dbo.Bronirovanie.RoomID));
-------------------------------------------------------------------------------

--инфо о типе номера
SELECT dbo.RoomType.TypeR, dbo.Room.RoomId, dbo.Room.Cost, dbo.Room.other
FROM dbo.RoomType, dbo.Room
WHERE (((@RoomT) Like dbo.RoomType.TypeR));
-------------------------------------------------------------------------------

--Итог за период
SELECT dbo.Bronirovanie.RoomId, Dbo.buy_usluga.buy_uslugaId, Sum(Dbo.pay_usluga.TotalCost) AS Общая_сумма_Услуги, Convert(int,(Dbo.Bronirovanie.DataOut-Dbo.Bronirovanie.DataIn))*dbo.Room.Cost AS Прожили, @Projili + @TotalCostUslug AS Итого, Dbo.Bronirovanie.DataIn, Dbo.Bronirovanie.DataOut
FROM ((dbo.Room INNER JOIN Dbo.Bronirovanie ON dbo.Room.[RoomId] = Dbo.Bronirovanie.[RoomId]) INNER JOIN Dbo.buy_usluga ON Dbo.Bronirovanie.[BronirovanieId] = Dbo.buy_usluga.[BronirovanieId]) INNER JOIN Dbo.pay_usluga ON Dbo.buy_usluga.[buy_uslugaId] = Dbo.pay_usluga.[buy_uslugaId]
WHERE (((@DataStart)<=Dbo.Bronirovanie.DataIn) AND ((@DataEnd)>=Dbo.Bronirovanie.DataOut))
GROUP BY Dbo.Bronirovanie.RoomId, Dbo.buy_usluga.buy_uslugaId, Dbo.Bronirovanie.DataIn, Dbo.Bronirovanie.DataOut, dbo.Room.Cost;
-------------------------------------------------------------------------------

--отчёт об услугах
SELECT Dbo.buy_usluga.BronirovanieId, Dbo.buy_usluga.UslugiId, Dbo.buy_usluga.Countt, Dbo.Bronirovanie.DataIn, Dbo.Bronirovanie.DataOut, Dbo.Uslugi.NameU, Dbo.Uslugi.Cost, Dbo.Uslugi.Cost*Dbo.buy_usluga.Countt AS Доход
FROM Dbo.Bronirovanie INNER JOIN (Dbo.Uslugi INNER JOIN Dbo.buy_usluga ON Dbo.Uslugi.UslugiId = Dbo.buy_usluga.buy_uslugaId) ON Dbo.Bronirovanie.[BronirovanieId] = Dbo.buy_usluga.[BronirovanieId]
WHERE (((@DataStart)<=Dbo.Bronirovanie.DataIn) AND ((@DataEnd)>=Dbo.Bronirovanie.DataOut))
ORDER BY Dbo.Uslugi.Cost*Dbo.buy_usluga.Countt DESC;
-------------------------------------------------------------------------------

--Постоялец (Запрос временно не работает. Просьба его не запускать. Приносим свои извинения)
/*
SELECT Dbo.Guest.LastNameG, Dbo.Guest.FirstNameG, Dbo.Guest.PasportG, Dbo.Bronirovanie.BronirovanieId, Dbo.Bronirovanie.DataIn, Dbo.Bronirovanie.DataOut, Dbo.Bronirovanie.RoomId, dbo.Room.Cost, datediff(day, Dbo.Bronirovanie.DataIn, Dbo.Bronirovanie.DataOut) AS Дней_пробыл, datediff(day, Dbo.Bronirovanie.DataIn, Dbo.Bronirovanie.DataOut) * Convert(int,dbo.Room.Cost) AS Доход, Count(Dbo.Bronirovanie.GuestId) AS Countt
FROM dbo.Room INNER JOIN (Dbo.Guest INNER JOIN Dbo.Bronirovanie ON Dbo.Guest.[GuestId] = Dbo.Bronirovanie.[GuestId]) ON dbo.Room.[RoomId] = Dbo.Bronirovanie.[RoomId]
GROUP BY Dbo.Guest.LastNameG, Dbo.Guest.FirstNameG, Dbo.Guest.PasportG, Dbo.Bronirovanie.BronirovanieId, Dbo.Bronirovanie.DataIn, Dbo.Bronirovanie.DataOut, Dbo.Bronirovanie.RoomId, dbo.Room.Cost, (Dbo.Bronirovanie.DataOut-Dbo.Bronirovanie.DataIn)
HAVING (((@LastG)=Dbo.Guest.LastNameG) AND ((@NameG)=Dbo.Guest.FirstNameG))
ORDER BY (Dbo.Bronirovanie.DataOut-Dbo.Bronirovanie.DataIn)*dbo.Room.Cost DESC;
*/
-------------------------------------------------------------------------------

--свободный номер
SELECT Dbo.Bronirovanie.[DataIn], Dbo.Bronirovanie.[DataOut], Dbo.Bronirovanie.[RoomId], IIf(@DataNow>Dbo.Bronirovanie.DataOut,'уже уехали',IIf(@DataNow<Dbo.Bronirovanie.DataIn,'Ещё не заехали', '01.01.2000')) AS Статус
FROM Dbo.Bronirovanie
WHERE @DataNow>Dbo.Bronirovanie.DataOut Or @DataNow<Dbo.Bronirovanie.DataIn;
-------------------------------------------------------------------------------

