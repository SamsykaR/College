using System.Diagnostics;


async void Progra(){
    Stopwatch time = new Stopwatch();
    Task<int[]> ar1 = Bubble();
    Task<int[]> ar2 = InsertionSort();
    Task<int[]> ar3 = ViborSort();
    Task<int[]>[] tas = new[]{ar1, ar2, ar3};
    foreach(Task<int[]> t in tas){
        time.Start();
        var res = await t;
        Console.WriteLine("------------");
        for(int i=0; i<10; i++) Console.Write(res[i]+" ");
        Console.WriteLine();
        Console.WriteLine(time.ElapsedMilliseconds);
        //time.Stop();
        time.Reset();
    }
}
//Progra();









async Task<int[]> Bubble(){
    int[] arr = Rand(10);
    int temp = 0;
    for (int write = 0; write < arr.Length; write++) {
        for (int sort = 0; sort < arr.Length - 1; sort++) {
            if (arr[sort] > arr[sort + 1]) {
                temp = arr[sort + 1];
                arr[sort + 1] = arr[sort];
                arr[sort] = temp;
            }
        }
    }
    return arr;
}

async Task<int[]> InsertionSort() {
    int[] inputArray = Rand(10);
    for (int i = 0; i < inputArray.Length - 1; i++) {
        for (int j = i + 1; j > 0; j--) {
            if (inputArray[j - 1] > inputArray[j]) {
                int temp = inputArray[j - 1];
                inputArray[j - 1] = inputArray[j];
                inputArray[j] = temp;
            }
        }
    }
    return inputArray; 
}

async Task<int[]> ViborSort(){
    int[] mas = Rand(10);
    for (int i = 0; i < mas.Length - 1; i++)
    {
        //поиск минимального числа
        int min=i;
        for (int j = i + 1; j < mas.Length; j++)
        {
            if (mas[j] < mas[min])
            {
                min = j;
            }
        }
        //обмен элементов
        int temp = mas[min];
        mas[min] = mas[i];
        mas[i] = temp;
    }
    return mas;
}

int[] Rand(int l){
    int[] m = new int[l];
    Random r = new Random();
    for(int i=0; i<l; i++) m[i] = r.Next(1, 100);
    return m;
}

