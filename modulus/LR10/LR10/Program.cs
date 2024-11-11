using System.Diagnostics;
using Microsoft.Data.Sqlite;

class Programm{
    static void Main(){
        //NumbersHaveTranz();
        //NumbersNotHaveTranz();
        //Zapros1();
        //Zapros6();
        //Zapros7();
        //Output();
     
    }
    static Stopwatch timer = new Stopwatch();
    static string con = "Data Source = db_1";

    static void NumbersHaveTranz(){
        timer.Start();
        using (var connect = new SqliteConnection(con)) {
            Random r = new Random();
            connect.Open();
            var transaction = connect.BeginTransaction();
            // Получение запросов для транзакции
            for (int i = 0; i < 1000; i++) {                
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
        timer.Stop();
        Console.WriteLine($"Транзакция: {timer.ElapsedMilliseconds}ms");
    }
    /////////////
    static void NumbersNotHaveTranz(){
        timer.Restart();
        using (var connect = new SqliteConnection(con)) {
            Random r = new Random();
            connect.Open();
            // Получение запросов для транзакции
            for (int i = 0; i < 1000; i++) {                
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
        }
        timer.Stop();
        Console.WriteLine($"Не транзакция: {timer.ElapsedMilliseconds}ms");
    }
    //////////////
    static void Zapros1(){
        using (var connect = new SqliteConnection(con)) {
            connect.Open();
            var command = connect.CreateCommand();
            command.CommandText = @"
                SELECT * 
                FROM numbers 
                WHERE long > 1000 
                AND long < 5000 
                AND long % 7 == 0;
                ";
            var reader = command.ExecuteReader();
            while (reader.Read()) {
                Console.WriteLine($"{reader["short"]} -> {reader["long"]}");
            }
        }
    }
    //////////////
    static void Zapros6(){
        using (var connect = new SqliteConnection(con)) {
            connect.Open();
            var command = connect.CreateCommand();
            command.CommandText = @"
                SELECT * 
                FROM numbers 
                WHERE
                CAST (long as TEXT) not like '%0%'
                AND CAST(long as INTEGER) % 3 == 0 
                ORDER BY long
                ;";
            var reader = command.ExecuteReader();
            while (reader.Read()) {
                Console.WriteLine($"{reader["short"]} -> {reader["long"]}");
            }
        }
    }
    //////////////////////
    static void Zapros7(){
        using (var connect = new SqliteConnection(con)) {
            connect.Open();
            var command = connect.CreateCommand();
            command.CommandText = @"
                SELECT * 
                FROM person
                WHERE name like 'T%'
                AND Length(name) == 3
                AND age < 45
                ;";
            var reader = command.ExecuteReader();
            while (reader.Read()) {
                Console.WriteLine($"{reader["name"]} -> {reader["age"]}");
            }
        }
    }
    /////////////////
        static void Output(){
            using (var connect = new SqliteConnection(con)) {
            connect.Open();
            var command = connect.CreateCommand();
                command.CommandText = @"
                SELECT *
                FROM friends;

                SELECT *
                FROM person;
                ";
            var reader = command.ExecuteReader();
            Console.WriteLine("---friends---");
            while (reader.Read()) {
                Console.WriteLine($"{reader["id"]} -> {reader["name"]}");
            }
            // Чтение следующего запроса
            reader.NextResult();
            Console.WriteLine("---person---");
            while (reader.Read()) {
                Console.WriteLine($"{reader["name"]} -> {reader["age"]}");
            }
        }  
    }
}
