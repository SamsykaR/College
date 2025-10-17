import 'package:dart_application_1/dart_application_1.dart' as classes;

void main(List<String> arguments) {
  var calc = classes.Calculator();
  print("1+3 = ${calc.plus(1, 3)}");
  print("10-33 = ${calc.minus(10, 33)}");
  print("11*3 = ${calc.mult(11, 3)}");
  print("100/32 = ${calc.div(100, 32)}");
  print("cos(100) = ${calc.cosinus(100)}");
  print("sin(3) = ${calc.sinus(3)}");
  print("2^4 = ${calc.power(2, 4)}");
  print("√16 = ${calc.coren(16)}");
}
