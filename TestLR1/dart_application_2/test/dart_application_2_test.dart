import 'package:test/test.dart';
import 'package:dart_application_2/arrayWork.dart';
void main(){
    group('Числовые массивы', () {
      test('Проверка создания массива', (){
        expect(arCreate(5, 2), equals(isNotEmpty));
      });
      test('Проверка округления', (){
        List<double> list = [0.1, 1.4, 2.6, 3.9];
        expect(arRound(list), equals([0, 1, 2, 3]));
      });
      test('Проверка сложения массивов', (){
        List<double> list1 = [0.1, 1.4, 2.6, 3.9];
        List<double> list2 = [1, 1, 2, 3];
        expect(arPlus(list1, list2), equals([0.1, 1.4, 2.6, 3.9, 1, 1, 2, 3]));
      });
    });
    group('Строковые массивы', () {
      test('Проверка удаления промежутка', (){
        List<String> list = ["a", "b", "c", "d", "e", "abc", "cba", "aaa"];
        expect(arBetwin(list, 2, 5), equals(["a", "b", "cba", "aaa"]));
      });
    });
}