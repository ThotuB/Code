interface Target {
    void Request();
}

class Adapter : Target {
    private LegacyAdaptee adaptee = new LegacyAdaptee();

    public void Request() {
        adaptee.SpecificRequest();
    }
}

class LegacyAdaptee {
    public void SpecificRequest() {
        Console.WriteLine("Legacy Adaptee: SpecificRequest()");
    }
}


class Program {
    public static void Main(string[] args) {
        Target target = new Adapter();
        target.Request();
    }
}

Program.Main(null);