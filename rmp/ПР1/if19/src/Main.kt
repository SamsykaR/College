//Вводится 3 целых числа, определить является ли они тройкой Пифагора
import java.math.*
fun main() {
    println("Ваши числа: ")
    println("1: ")
    val a = readln().toInt()
    println("2: ")
    val b = readln().toInt()
    println("3: ")
    val c = readln().toInt()

    if(a*a == b*b + c*c && b*b == a*a + c*c && c*c == b*b + a*a) println("Это троица пифагора")
    else println("Это не троица пифагора")
}