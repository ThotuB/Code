class Singleton {
    private static Singleton instance;

    private Singleton() { 
        // constructor: 
        //  - private -> so it can't be instantiated
    }

    public static Singleton Instance {
        get {
            if (instance == null) {
                instance = new Singleton();
            }
            return instance;
        }
    }

    public void DoSomething() {
        // ...
    }
}

class Program {
    public static void Main(String[] args) {
        Singleton s = Singleton.Instance;
        s.DoSomething();
    }
}

Program.Main(null);