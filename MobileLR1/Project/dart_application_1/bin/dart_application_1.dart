import 'dart:io';

import 'package:dart_application_1/arrayWork.dart' as arWork;

void main(List<String> arguments) {
  int? n, a, b;
  List<double> arr, arr2;
    print("lenght: ");
  n = int.tryParse(stdin.readLineSync()!);
    print("max: ");
  var max = double.tryParse(stdin.readLineSync()!);
  arr = arWork.arCreate(n!, max!);
  arr2 = arWork.arCreate(n, max);
  print("arr1:");
  print(arr);
  print("arr2:");
  print(arr2);
  print("rounded:");
  print(arWork.arRound(arr2));
  print("arr1+arr2:");
  print(arWork.arPlus(arr, arr2));
  print("String list (,): ");
  List<String> strList = stdin.readLineSync()!.split(",");
  print("first index = ");
  a = int.tryParse(stdin.readLineSync()!);
  print("last index = ");
  b = int.tryParse(stdin.readLineSync()!);
  print("removed: ");
  print(arWork.arBetwin(strList, a!, b!));
}
