using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;

namespace Tasks
{
    public class Program
    {
        public static ulong Rec(ulong x)
        {
            if (x <= 18)
                return x + 3;
            else if (x > 18 && x % 3 == 0)
                return (x / 3) * Rec(x / 3) + x - 12;
            else
                return Rec(x - 1) + (x * x) + 5;
        }

        public static bool IsAllDigitsEven(ulong number)
        {
            while (number != 0)
            {
                if (number % 2 != 0)
                {
                    return false;
                }
                number /= 10;
            }
            return true;
        }

        public static ulong CountValidNumbersInRange(ulong start, ulong end)
        {
            ulong count = 0;

            for (ulong i = start; i <= end; i++)
            {
                ulong result = Rec(i);
                if (IsAllDigitsEven(result))
                {
                    count++;
                }
            }
            return count;
        }

        public static ulong CountValidNumbersParallel(ulong range)
        {
            int numTasks = Environment.ProcessorCount; // Количество потоков
            ulong chunkSize = range / (ulong)numTasks;
            List<Task<ulong>> tasks = new List<Task<ulong>>();

            for (int i = 0; i < numTasks; i++)
            {
                ulong start = (ulong)i * chunkSize + 1;
                ulong end = (i == numTasks - 1) ? range : start + chunkSize - 1;

                // Запускаем задачу в отдельном потоке
                tasks.Add(Task.Run(() => CountValidNumbersInRange(start, end)));
            }

            Task.WaitAll(tasks.ToArray()); // Ожидаем завершения всех задач

            // Суммируем результаты
            ulong totalCount = 0;
            foreach (var task in tasks)
            {
                totalCount += task.Result; // Суммируем результаты выполнения задач
            }

            return totalCount;
        }

        public static void Main(string[] args)
        {
            const ulong range = 10000000;

            // Замер времени без задач
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            ulong countWithoutTasks = CountValidNumbersInRange(1, range);
            stopwatch.Stop();
            Console.WriteLine("Количество чисел (без задач): " + countWithoutTasks);
            Console.WriteLine("Время выполнения (без задач): " + stopwatch.ElapsedMilliseconds + " ms");

            // Замер времени с задачами
            stopwatch.Restart();
            ulong countWithTasks = CountValidNumbersParallel(range);
            stopwatch.Stop();
            Console.WriteLine("Количество чисел (с задачами): " + countWithTasks);
            Console.WriteLine("Время выполнения (с задачами): " + stopwatch.ElapsedMilliseconds + " ms");
        }
    }
}
