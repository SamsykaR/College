import 'dart:math';
mixin TrigonometricCalculator{
  double sinus(double a){ return sin(a*(pi / 180));}
  double cosinus(double a){ return cos(a*(pi / 180));}
}

mixin AdvancedCalculator{
  double coren(double a){ return sqrt(a);}
  double power(double a, double b){ return pow(a, b).toDouble();}
}

class Calculator with TrigonometricCalculator, AdvancedCalculator{
  double plus(double a, double b){ return a+b;}
  double minus(double a, double b){ return a-b;}
  double mult(double a, double b){ return a*b;}
  double div(double a, double b){ return a/b;}
}