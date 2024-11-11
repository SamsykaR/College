public static class FileWork{
    static List<string[]> strings = new List<string[]>();

    public static List<string[]> FileRead(){
        FileInfo fw = new FileInfo(Programm.textPath);
        if(!fw.Exists){
            fw.Create();
        }

        using(StreamReader str = new StreamReader(Programm.textPath)){
            string[] lines = File.ReadAllLines(Programm.textPath);
                foreach (string s in lines)
                    strings.Add(str.ReadLine()!.Split(' '));
        }
        for(int i=0; i<strings.Count; i++){
            for(int j=i+1; j<strings.Count; j++){
                if(strings[i][0] == strings[j][0]) strings.Remove(strings[i]); 
            }   
        }
        //foreach(var el in strings){ Console.WriteLine(el[0]); }
        return strings;
    }
}