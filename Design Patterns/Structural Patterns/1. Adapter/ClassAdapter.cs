// ! Not Prefferable

interface Target {
    void Request();
}

class LegacyAdaptee {
    public void SpecificRequest() {
        Console.WriteLine("Legacy Adaptee: SpecificRequest()");
    }
}

class Adapter : LegacyAdaptee, Target {
    public void Request(){
        SpecificRequest();
    }
}

class Program {
    public static void Main(string[] args) {
        Target target = new Adapter();
        target.Request();
    }
}

Program.Main(null);