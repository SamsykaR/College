//дано Д. Есть последовательность А1=1 А2 = 2 Ан = (А[н-2]+А[н-1])/2 . Найти н при котором |Ан-А[н-1]|< Д и вывести Ан и Ан-1
fun main() {
    var A1 = 1.0
    var A2 = 2.0
    var A3: Double
    print("D = ")
    val D = readln().toDouble()
    for (i in 3..100){
        A3 = (A1+A2)/2
        A1=A2
        A2=A3
        if(Math.abs(A2-A1)<D){
            println("Номер: $i  An: $A2  An-1: $A1")
            break
        }
    }
} //1 2 1.5