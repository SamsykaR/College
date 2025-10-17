import 'package:test/test.dart';
import 'package:dart_application_1/arrayWork.dart';
void main(){
    group('Числовые массивы', () {
      test('Проверка округления', (){
        List<double> list = [0.1, 1.4, 2.6, 3.9];
        expect(arRound(list), equals([0, 1, 2, 3]));
      });
    });
    group('Строковые массивы', () {
      test('Проверка округления', (){
        List<double> list = [0.1, 1.4, 2.6, 3.9];
        expect(arRound(list), equals([0, 1, 2, 3]));
      });
    });
}