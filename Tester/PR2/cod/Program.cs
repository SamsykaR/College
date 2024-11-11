using System.Diagnostics;

Console.WriteLine("X не может быть больше 1 и не меньше -1");
Console.Write("Введите число x: ");
double x = Convert.ToDouble(Console.ReadLine());
Console.Write("Введите число dx: ");
double dx = Convert.ToDouble(Console.ReadLine()); 
var time = new Stopwatch();
time.Start();
df(x, dx);
Df(x, dx);
time.Stop();
Console.WriteLine($"Время: {time.ElapsedMilliseconds} ms");

void df(double x1, double dx1){
   double g = dx1 / Math.Sqrt(1-(x1*x1));
   Console.WriteLine($"df = {g:f6}");
}
void Df(double x1, double dx1){
   double g = Math.Abs(x1)/Math.Abs(Math.Asin(x1))*Math.Sqrt(1-(x1*x1))*dx1;
   Console.WriteLine($"Df = {g:f6}"); 
}