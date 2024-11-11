/*

using Microsoft.Data.Sqlite;
var m = new Methods();
string con = "Data Source = db_1";
using (var connect = new SqliteConnection(con)) {
    connect.Open();
    var transaction = connect.BeginTransaction();
    // Получение запросов для транзакции
    for (int i = 0; i < 10; i++) {                
        var command = connect.CreateCommand();
        command.CommandText = @"INSERT 
        INTO person (name, family, age) 
        VALUES ($name, $family, $age)
        ";
        string name = m.RNDnames();
        string family = m.RNDfamily();  
        int age = m.RNDage();       
        SqliteParameter param1 = new SqliteParameter("$name", name);
        command.Parameters.Add(param1);
        SqliteParameter param2 = new SqliteParameter("$family", family);
        command.Parameters.Add(param2); 
        SqliteParameter param3 = new SqliteParameter("$age", age);
        command.Parameters.Add(param3);

        command.ExecuteNonQuery();
    }
    // Выполнение транзакции
    transaction.Commit();
}

//////////////
///
using (var connect = new SqliteConnection(con)) {
        connect.Open();
        var transaction = connect.BeginTransaction();
        // Получение запросов для транзакции
        for (int i = 0; i < 10; i++) {                
            var command = connect.CreateCommand();
            command.CommandText = @"INSERT 
            INTO friends (name, birthday) 
            VALUES ($name, $birthday)
            ";
            string name = m.RNDnames();
            string birthday = m.RNDday();        
            SqliteParameter param1 = new SqliteParameter("$name", name);
            command.Parameters.Add(param1);
            SqliteParameter param2 = new SqliteParameter("$birthday", birthday);
            command.Parameters.Add(param2); 
 
            command.ExecuteNonQuery();
        }
        // Выполнение транзакции
        transaction.Commit();
    }

    //////
    ///

    using (var connect = new SqliteConnection(con)) {
        Random r = new Random();
        connect.Open();
        var transaction = connect.BeginTransaction();
        // Получение запросов для транзакции
        for (int i = 0; i < 10; i++) {                
            var command = connect.CreateCommand();
            command.CommandText = @"INSERT 
            INTO numbers (short, long) 
            VALUES ($short, $long)
            ";
            int name = r.Next(1,10);
            int birthday = r.Next(1, 10000);        
            SqliteParameter param1 = new SqliteParameter("$short", name);
            command.Parameters.Add(param1);
            SqliteParameter param2 = new SqliteParameter("$long", birthday);
            command.Parameters.Add(param2); 
 
            command.ExecuteNonQuery();
        }
        // Выполнение транзакции
        transaction.Commit();
    }



CREATE TABLE numbers (
	short INTEGER (250) NOT NULL,
	long INTEGER NOT NULL
);



Транзакция: 135 ms
Не транзакция: 72895 ms


Tor -> 14
Tom -> 8
Tod -> 41
Tor -> 41


---friends---
11 -> Kris
12 -> Susie
13 -> Susie
14 -> Tor
15 -> Clara
16 -> Kris
17 -> Tim
18 -> Tom
19 -> Clara
20 -> Tim
---person---
Susie -> 70
John -> 44
John -> 65
Steev -> 22
Susie -> 72
Robert -> 31
Steev -> 64
Susie -> 45
John -> 51
Toby -> 18
Robert -> 33
Robert -> 87
Kris -> 75
Toby -> 12
Robert -> 68
Susie -> 85
Kris -> 55
Tor -> 14
Kris -> 9
Tim -> 84
John -> 66
Tom -> 8
Tod -> 41
Tor -> 41
Clara -> 38
Tom -> 98
Tim -> 64
Susie -> 71
Clara -> 12
Tim -> 82


8 -> 1771
9 -> 4214
8 -> 2688
5 -> 1295
5 -> 1687
3 -> 3745
4 -> 3192
6 -> 1442
4 -> 3052
3 -> 1225
1 -> 3570
7 -> 1876
3 -> 3269
9 -> 3794
3 -> 3269
6 -> 2870
3 -> 2254
1 -> 4424
8 -> 3808
2 -> 1092
5 -> 4067
8 -> 3241
8 -> 4445
1 -> 3227
4 -> 2807
5 -> 4207
7 -> 3948
2 -> 1708
8 -> 1400
7 -> 1288
8 -> 4991
3 -> 4977
4 -> 2401
5 -> 4620
6 -> 4655
6 -> 3003
8 -> 1260
1 -> 4081
3 -> 1344
3 -> 3171
4 -> 3724
5 -> 2723
3 -> 4655
1 -> 2870
3 -> 1533
6 -> 1582
4 -> 1113
6 -> 1323
3 -> 3850
7 -> 2149
9 -> 3941
7 -> 1134
7 -> 3878
9 -> 3465
2 -> 4844
9 -> 2303
7 -> 4053
7 -> 1813
9 -> 2744
7 -> 3101
1 -> 2457
3 -> 3304
6 -> 3031
3 -> 4844
5 -> 2492
6 -> 2100
1 -> 3234
2 -> 2324
7 -> 2149
3 -> 1029
4 -> 3129
4 -> 2912
6 -> 2408
7 -> 3682
8 -> 1897
7 -> 2737
2 -> 2653
6 -> 1946
2 -> 1155
4 -> 1505
7 -> 2912
3 -> 2324
3 -> 4011
7 -> 4347
2 -> 2660
3 -> 4459
6 -> 2611
2 -> 4844
8 -> 1470
3 -> 2394
1 -> 3507
2 -> 2548
5 -> 4795
2 -> 4305
9 -> 1008
1 -> 3885
7 -> 2877
4 -> 2044
6 -> 1603
8 -> 2317
6 -> 3451
4 -> 3479
8 -> 1876
1 -> 3927
6 -> 2226
2 -> 2002
4 -> 3703
8 -> 4200
8 -> 4494
1 -> 4949
3 -> 1071
7 -> 3472
2 -> 2891
4 -> 3668
8 -> 2485
3 -> 1274
4 -> 2177
6 -> 4473
2 -> 4263
2 -> 1414
7 -> 2933
5 -> 2954
5 -> 4396



1 -> 15
8 -> 33
8 -> 66
7 -> 87
2 -> 156
4 -> 174
3 -> 174
6 -> 219
2 -> 249
5 -> 264
3 -> 279
3 -> 294
8 -> 348
7 -> 369
9 -> 387
8 -> 387
9 -> 411
6 -> 432
6 -> 435
3 -> 441
5 -> 453
5 -> 459
1 -> 498
9 -> 498
1 -> 516
7 -> 519
9 -> 522
1 -> 537
2 -> 558
3 -> 597
1 -> 624
6 -> 639
5 -> 642
8 -> 642
4 -> 648
5 -> 663
8 -> 669
7 -> 744
9 -> 765
2 -> 783
3 -> 786
8 -> 789
3 -> 828
1 -> 834
7 -> 861
8 -> 882
1 -> 894
5 -> 921
8 -> 924
3 -> 942



*/