using Microsoft.Data.Sqlite;
public static class DBWork{
    
    public static void CreateTable(string n1, string n2){
        using (var connect = new SqliteConnection(Programm.con)) {
        connect.Open();
        SqliteCommand command = new SqliteCommand();
        command.Connection = connect;
        //Console.WriteLine(tempa);
        command.CommandText = $@"CREATE TABLE {Programm.tableName} (_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
        {n1} TEXT NULL,
        {n2} TEXT NULL)
        ";
        command.ExecuteNonQuery();
        }
    }
    /// /////////////
    public static void WriteDB(string n1, string n2){ 
        foreach (var el in Programm.strings) {
            //Console.WriteLine(el[0]);
            using (var connect = new SqliteConnection(Programm.con)) {
                connect.Open();
                var command = connect.CreateCommand();
                command.CommandText = $@"INSERT 
                INTO {Programm.tableName} ({n1}, {n2}) 
                VALUES ($name, $type)
                ";
                string name = el[0];
                string type = el[1];        
                //string habitat = el[2];  //habitat - место обитания            
                SqliteParameter param1 = new 
                SqliteParameter($"name", name);
                command.Parameters.Add(param1);
                //SqliteParameter param2 = new 
                //SqliteParameter("$habitat", habitat);
                //command.Parameters.Add(param2); 
                SqliteParameter param2 = new 
                SqliteParameter($"type", type);
                command.Parameters.Add(param2); 
                command.ExecuteNonQuery();
            }
        }
    }
    ///////////////
    public static void ReadDB(string n1, string n2){
        //foreach(var el in Programm.strings){ Console.WriteLine(el[0]); }
        using (var connect = new SqliteConnection(Programm.con)) {
            connect.Open();
            var command = connect.CreateCommand();
            command.CommandText = @"SELECT * FROM "+ Programm.tableName;
            SqliteDataReader reader = command.ExecuteReader();
            using (reader) {
                if (reader.HasRows) { 
                        Console.WriteLine($"--------------------------------------------");
                        Console.WriteLine($"|{null, 3}id|{null, 5} {n1} {null, 6}|{null, 3} {n1} {null, 5}|");
                        Console.WriteLine($"--------------------------------------------");
                    while (reader.Read()) { 
                        int id = reader.GetInt32(0);
                        string name = reader.GetString(1);
                        string type = reader.GetString(2);
                        Console.WriteLine($"| {id, 3} | {name, 10}{null, 5} | {type,10}{null, 5} |");
                        Console.WriteLine($"--------------------------------------------");
                    }
                }
            }
        }
    }
}