//Найти сумму квадратов чётных чисел между m и n
fun main() {
    print("m: ")
    var m = readln().toInt()
    print("n: ")
    val n = readln().toInt()
    var sum = 0
    while(m < n){
        if(m%2==0) sum += m*m
        m++
    }
    println(sum)
}