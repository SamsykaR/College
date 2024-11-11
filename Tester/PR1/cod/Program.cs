/*****************************************************
******************************************************
**                                                  **
**  Программа обработки исключений при работе с     **
**  файлами и задачами. Найти в текстовом файле     **
**  строки в которых ровно пять букв "и".           **
**                                                  **
**  Выполнил: студент 3 курса ЕПК И-32 группы       **
**  Самсыка Р. М.                                   **
**  Проверил: преподаватель поддержки и тестирования**
**  программных модулей Фомин А. Т.                 **
**                                                  **
******************************************************
*****************************************************/

using System.Diagnostics;

class Programm{
    static List<string> str = new List<string>();

    static void FileWork(string path){
        using (StreamReader reader = new(path)){
            int k=0;
            string[] lines = File.ReadAllLines(path);
            foreach (string s in lines){
                foreach(char el in s){
                    if(el == 'и' || el == 'И') k++;
                }
                if(k==5) str.Add(s);
                k=0;
            }
        }
        Console.WriteLine("  Строки с пятью и: ");
        foreach(string el in str)
            Console.WriteLine(el);

        Console.WriteLine();
    }

    static void Main(){
        Stopwatch stopwatch = new();
        stopwatch.Start();
        try{
            var task = Task.Run(()=>FileWork("text.txt"));
            task.Wait();
        }
        catch(AggregateException ae){foreach(var ex in ae.InnerExceptions)Console.WriteLine(ex.Message); return;}
        catch(Exception){Console.WriteLine("Иная ошибка"); return;} 
        long elapsedTime = stopwatch.ElapsedMilliseconds;
        Console.WriteLine($"Время выполнения: {elapsedTime} ms");
    }
}

/*
    Если неверно имя файла:
dotnet run
Could not find file 'D:\Tester\PR1\cod\1text.txt'.

    Если всё гладко:
dotnet run
  Строки с пятью и: 
Не все ли нам равно? Бог с ними. ии
Никому ииии
Не гнуть ни совести, ни помыслов, ни шеи;
Счастливый домик охрани! ии
*/
