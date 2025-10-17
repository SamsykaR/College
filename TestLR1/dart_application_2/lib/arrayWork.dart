import 'dart:math';
//7
List<double> arCreate(int len, double max) {
    var random = Random();
    List<double> randomNumbers = List<double>.generate(len, (index) => 
      double.tryParse((random.nextDouble()*max).toStringAsFixed(2))!);
    return randomNumbers;
}

//13
List<int> arRound(List<double> ar) {
    List<int> rounded = List<int>.generate(ar.length, (index) => 
      ar[index].floor());
    return rounded;
}

//14
List<double> arPlus(List<double> ar1, List<double> ar2) {
    return ar1 + ar2;
}

//16
List<String> arBetwin(List<String> ar, int a, int b) {
    List<String> betwined = ar;
    for(int i=a; i<b; i++){
      betwined.removeAt(i);
    }
    return betwined;
}