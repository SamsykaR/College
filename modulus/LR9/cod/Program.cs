using System.Diagnostics;
using System.Diagnostics.Tracing;
using Microsoft.Data.Sqlite;

public static class Programm{
    public static string con = "Data Source =";
    public static string textPath = @"F:\modulus\LR9\cod\text.txt";
    public static string? tableName;
    public static List<string[]> strings = new List<string[]>();
    static string? temp;
    static string? temp2;

    static void Main(){
        Console.WriteLine("Что бы завершить работу нажмите << - >>");
        Console.WriteLine("Начало работы");

        Console.Write("Имя файла: ");
        textPath = Console.ReadLine()!;
        Console.Write("В вашем файле есть информация? (1-да 0-нет): ");
        switch(Console.ReadKey().KeyChar){
            case '0':
                Console.WriteLine();
                Process p = new();
                p.StartInfo.FileName = "notepad.exe";
                p.StartInfo.Arguments = textPath;
                p.Start();
                File.OpenText(textPath);
                Console.Write("Файл заполнять в виде: <имя> <значение> \nКогда закончите нажмите клавишу ");
                Console.ReadKey();
                Console.WriteLine();
            break;

            case '1':
            break;

            case '-':
            return;
        }
        strings = FileWork.FileRead();

        Console.Write("имя базы данных: ");
        con = "Data Source = "+Console.ReadLine()!;

        while(true){
            try{
                Console.Write("Создать таблицу? (1-да 0-нет): ");
                switch(Console.ReadKey().KeyChar){
                    case '0':
                        Console.WriteLine();
                    break;

                    case '1':
                        Console.WriteLine();
                        Console.Write("имя таблицы: ");
                        tableName = Console.ReadLine()!;
                        Console.Write("Первый столбец: ");
                        temp = Console.ReadLine()!;
                        Console.Write("Второй столбец: ");
                        temp2 = Console.ReadLine()!;
                        DBWork.CreateTable(temp, temp2);
                    break;

                    case '-':
                    return;
                }
                break;
            }catch(Exception){
                Console.WriteLine("Ошибка");
                tableName = null;
                continue;
            }
        }

        while(true){
            try{
                Console.Write("Внести данные в таблицу? (1-да 0-нет): ");
                switch(Console.ReadKey().KeyChar){
                    case '0':
                        Console.WriteLine();
                    break;

                    case '1':
                        Console.WriteLine();
                        if(tableName == null || tableName == ""){
                            Console.Write("имя таблицы: ");
                            tableName = Console.ReadLine()!;
                            Console.Write("Первый столбец: ");
                            temp = Console.ReadLine()!;
                            Console.Write("Второй столбец: ");
                            temp2 = Console.ReadLine()!;
                        }
                        DBWork.WriteDB(temp!, temp2!);
                    break;

                    case '-':
                    return;
                }
                break;
            } catch(Exception){
                Console.WriteLine("Ошибка");
                tableName = null;
                continue;
            }
        }

        while(true){
            try{
                Console.Write("Вывести таблицу? (1-да 0-нет): ");
                switch(Console.ReadKey().KeyChar){
                    case '0':
                        Console.WriteLine();
                    break;

                    case '1':
                        Console.WriteLine();
                        if(tableName == null || tableName == ""){
                        Console.Write("имя таблицы: ");
                        tableName = Console.ReadLine()!;
                        Console.Write("Первый столбец: ");
                        temp = Console.ReadLine()!;
                        Console.Write("Второй столбец: ");
                        temp2 = Console.ReadLine()!;
                        }
                        Console.WriteLine("Сейчас выведем");
                        for(int i=0; i<5; i++){
                            Console.Write(". ");
                            Thread.Sleep(200);
                        }
                        Console.WriteLine();
                        DBWork.ReadDB(temp!, temp2!);
                    break;

                    case '-':
                    return;
                }
                break;
            } catch(Exception){
                Console.WriteLine("Ошибка");
                tableName = null;
                continue;
            }
        }
    }
        //foreach(var el in strings){ Console.WriteLine(el[0]); }
}
