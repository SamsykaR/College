fun main(){
    val numbers = mutableListOf(0)
    numbers.removeFirst()
    for(i in 1..10){
        numbers.add((0..10).random())
    }
    println(numbers)
    var k = 0
    for(i in 1..8){
        if((numbers[i]<numbers[i+1]) and (numbers[i]<numbers[i-1])) k++
    }
    println("Локальных минимумов: " + k)
}

