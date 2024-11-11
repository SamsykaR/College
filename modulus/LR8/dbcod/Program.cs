using Microsoft.Data.Sqlite;
using System.Text;

class Programm{
    static string con = "Data Source = test";
    static string textPath = "text.txt";
    static List<string[]> strings = new List<string[]>();

    static void Main(){
        Console.InputEncoding = Encoding.Unicode;
        //CreateTable();
        //FileRead();
        //WriteDB();
        ReadDB();
    }
    static void CreateTable(){
        using (var connect = new SqliteConnection(con)) {
        connect.Open();
        SqliteCommand command = new SqliteCommand();
        command.Connection = connect;
        command.CommandText = @"
            CREATE TABLE Nature(_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, 
            Type TEXT NULL,
            Habitat TEXT NULL,
            Name TEXT NULL)
        ";
        command.ExecuteNonQuery();
        }
    }
    static void WriteDB(){
        foreach (var el in strings) {
            using (var connect = new SqliteConnection(con)) {
                connect.Open();
                var command = connect.CreateCommand();
                command.CommandText = @"INSERT 
                INTO nature (type, habitat, name) 
                VALUES ($type, $habitat, $name)
                ";
                string name = el[0];
                string type = el[1];        
                string habitat = el[2];  //habitat - место обитания            
                SqliteParameter param1 = new 
                SqliteParameter("$name", name);
                command.Parameters.Add(param1);
                SqliteParameter param2 = new 
                SqliteParameter("$habitat", habitat);
                command.Parameters.Add(param2); 
                SqliteParameter param3 = new 
                SqliteParameter("$type", type);
                command.Parameters.Add(param3); 
                command.ExecuteNonQuery();
            }
        }
    }
    static void FileRead(){
        using(StreamReader str = new StreamReader(textPath)){
            string[] lines = File.ReadAllLines(textPath);
                foreach (string s in lines)
                    strings.Add(str.ReadLine()!.Split(' '));
        }
        for(int i=0; i<strings.Count; i++){
            for(int j=i+1; j<strings.Count; j++){
                if(strings[i][0] == strings[j][0]) strings.Remove(strings[i]); 
            }   
        }
        foreach(var el in strings){ Console.WriteLine(el[0]); }
    }

    static void ReadDB(){
        using (var connect = new SqliteConnection(con)) {
            connect.Open();
            var command = connect.CreateCommand();
            command.CommandText = @"SELECT * FROM nature";
            SqliteDataReader reader = command.ExecuteReader();
            using (reader) {
                if (reader.HasRows) { 
                        Console.WriteLine($"-------------------------------------------------------------");
                        Console.WriteLine($"|{null, 3}id|{null, 5} name {null, 6}|{null, 4} type {null, 7}|{null, 3} habitat {null, 5}|");
                        Console.WriteLine($"-------------------------------------------------------------");
                    while (reader.Read()) { 
                        int id = reader.GetInt32(0);
                        string name = reader.GetString(3);
                        string type = reader.GetString(1);
                        string habitat = reader.GetString(2);
                        Console.WriteLine($"| {id, 3} | {name, 10}{null, 5} | {type,10}{null, 5} | {habitat,10}{null, 5} |");
                        Console.WriteLine($"-------------------------------------------------------------");
                    }
                }
            }
        }
    }
}
