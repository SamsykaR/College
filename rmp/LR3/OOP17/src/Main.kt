open class Vector(val x1: Int,val y1: Int,val x2: Int,val y2: Int){
    fun Long(): Double {
        val x3=x2-x1
        val y3=y2-y1
        return Math.sqrt(Math.pow(x3.toDouble(), 2.0)+Math.pow(y3.toDouble(), 2.0))
    }
}
class Triangle(x1: Int, y1: Int, x2: Int, y2: Int, val x3: Int, val y3: Int) : Vector(x1, y1, x2, y2) {

    var Square : Double
        set(value){
        }
        get() {
            return (Math.abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1)).toDouble()/2)
        }

}

fun main() {
    val coords = Array<Int>(6){0}
    println("Введите координаты вектора")
    print("x1: ")
    coords[0]=readln().toInt()
    print("y1: ")
    coords[1]=readln().toInt()
    print("x2: ")
    coords[2]=readln().toInt()
    print("y2: ")
    coords[3]=readln().toInt()
    var points = Triangle(coords[0], coords[1], coords[2], coords[3], coords[4], coords[5])
    println("Длина вектора: "+points.Long())
    println("А теперь координаты точки")
    print("x3: ")
    coords[4]=readln().toInt()
    print("y3: ")
    coords[5]=readln().toInt()
    println("Площадь получившегося треугольника: "+points.Square)
}