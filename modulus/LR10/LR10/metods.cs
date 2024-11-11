public class Methods{
    public string RNDnames(){
        Random r = new Random();
        string[] names = new string[]{"Clara", "Tim", "Robert", "John", "Susie", "Kris", "Tod", "Tor", "Tom"};
        return names[r.Next(0,9)];
    }
    public string RNDfamily(){
        Random r = new Random();
        string[] names = new string[]{"Jobs", "Petrikow", "Simian", "Smith", "Fox", "Jackson"};
        return names[r.Next(0,6)];
    }
    public int RNDage(){
        Random r = new Random();
        return r.Next(1,100);
    }
    public string RNDday(){
        Random r = new Random();
        return Convert.ToString(r.Next(1,30)+"."+r.Next(1,13)+"."+r.Next(1990, 2024));
    }
}