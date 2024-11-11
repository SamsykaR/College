//4. чётные отрицательные, обратный порядок
//7. положительные двузначные окончание на N по убыванию
using System.Linq;
using Microsoft.VisualBasic;

class Programm{
    static void Main(){
        Console.Write("Длина массива: ");
        int n = Convert.ToInt32(Console.ReadLine());
        var array = Input(n);
        Console.WriteLine();
        Console.WriteLine("---------------№4---------------");
        var Lin4 = Work4Lambda(array);
        Console.WriteLine("Новый массив 4 (Lambda): ");
        foreach(int l in Lin4) Console.Write(l + " ");
        Console.WriteLine();
        Console.WriteLine();
        Console.WriteLine("---------------№7---------------");
        Console.Write("Цифра N на которую заканчивается другое число: ");
        int N = Convert.ToInt32(Console.ReadLine());
        var Lin7 = Work7Lambda(array, N);
        Console.WriteLine("Новый массив 7 (Lambda): ");
        foreach(int l in Lin7) Console.Write(l + " ");
    }
    static int[] Input(int n){
        int[] a = new int[n];
        Random rnd = new Random();
        Console.WriteLine("Массив: ");
        for(int i=0; i<n; i++){
            a[i] = rnd.Next(-20, 101);
            Console.Write(a[i]+" ");
        }
        Console.WriteLine();
        return a;
    }
    static IEnumerable<int> Work4(int[] a){
        IEnumerable<int> numbers = from n in a.Reverse()
        where n < 0 && n % 2 == 0
        select n;

        return numbers;
    }
    static IEnumerable<int> Work4Lambda(int[] a){
        IEnumerable<int> numbers = a.Reverse()
        .Where (n => n < 0 && n % 2 == 0);
        return numbers;
    }
    static IEnumerable<int> Work7(int[] a, int N){
        IEnumerable<int> numbers = from n in a
        where n < 100 && n > 9 && n % 10 == N
        orderby n
        select n;

        return numbers;
    }
    static IEnumerable<int> Work7Lambda(int[] a, int N){
        IEnumerable<int> numbers = a.Reverse()
        .Where (n => n < 100 && n > 9 && n % 10 == N)
        .OrderByDescending(n => n);
        return numbers;
    }
}