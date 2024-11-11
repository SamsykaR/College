namespace potok;
using System.Diagnostics;
class Program
{
    class NoTask{
        static ulong Rec(ulong x){
        if(x <= 18)
            return x + 3;
        else if(x > 18 && x % 3 == 0)
            return x / 3 * Rec(x / 3) + x - 12;
        else
            return Rec(x - 1) + x * x + 5;
        }
        public static ulong RecSum() {
            ulong k = 0;

            for (ulong i = 800; i <= 10000000; i++) {
                bool ch = true;
                ulong a = Rec(i);
                while (a != 0) {
                    if (a % 2 == 0) {
                        a /= 10;
                    } else {
                        ch = false;
                        break;
                    }
                }
                if (ch == true) k++;
            }
            Console.WriteLine($"Результат вычислений {k}"); 
            return k;
        }
    }
    class Taskhave{
        static ulong Rec(ulong x){
        if(x <= 18)
            return x + 3;
        else if(x > 18 && x % 3 == 0)
            return x / 3 * Rec(x / 3) + x - 12;
        else
            return Rec(x - 1) + x * x + 5;
        }
        public static ulong RecSum(ulong n) {
            ulong k = 0;
            Task[] tasks = new Task[2]{Task.Factory.StartNew(()=>RS1()), Task.Factory.StartNew(()=>RS2())};
            void RS1(){
                for (ulong i = 800; i < n/2; i++) {
                bool ch = true;
                    ulong a = Rec(i);
                    while (a != 0) {
                        if (a % 2 == 0) {
                            a /= 10;
                        } else {
                            ch = false;
                            break;
                        }
                    }
                    if (ch == true) k++;
                }
            } 
            void RS2(){
                for (ulong i = n/2 + 800; i <= n; i++) {
                    bool ch = true;
                        ulong a = Rec(i);
                        while (a != 0) {
                            if (a % 2 == 0) {
                                a /= 10;
                            } else {
                                ch = false;
                                break;
                            }
                        }
                        if (ch == true) k++;
                }
            }
            Task.WaitAll(tasks);  
            Console.WriteLine($"Результат вычислений {k}"); 
            return k;
        }
    }
    static void GetResult() {
    var TaskRec = Task.Factory.StartNew(()=>Taskhave.RecSum(10000000));
    TaskRec.Start();
    //Console.WriteLine($"Результат вычислений {TaskRec.Result}");  
    //Task.WaitAll(TaskRec);  
}
    static void Main(string[] args)
    {
        var stopwatch = new Stopwatch();
        stopwatch.Start();
        NoTask.RecSum();
        stopwatch.Stop();
        long elapsedTime = stopwatch.ElapsedMilliseconds;
        Console.WriteLine($"Время выполнения без задач: {elapsedTime} ms");

        stopwatch.Restart();
        Taskhave.RecSum(10000000);
        stopwatch.Stop();
        elapsedTime = stopwatch.ElapsedMilliseconds;
        Console.WriteLine($"Время выполнения с задачами: {elapsedTime} ms");
    }
}
