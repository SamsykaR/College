import kotlin.random.Random

//Дан массив − 19 элементов целого типа. Найти сумму элементов, расположенных до первого отрицательного элемента. Если отрицательных
//элементов нет, то выдать соответствующее сообщение.
fun main() {
    var sum = 0
    val numbers = List(19){ Random.nextInt(-5, 11)}
    println("Числа: $numbers")
    for(i in numbers){
        if(i>=0) {
            sum += i
        }
        else break
    }
    println("Сумма: $sum")
    if (sum == numbers.sum()) println("Отрицательных нет")
}