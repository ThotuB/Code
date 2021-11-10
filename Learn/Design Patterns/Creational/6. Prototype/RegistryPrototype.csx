class PrototypeRegistry {
    private static Dictionary<string, Prototype> registry = new Dictionary<string, Prototype>();

    public void AddItem(Prototype prototype) {
        registry[prototype.GetID()] = prototype;
    }

    public Prototype GetItem(string id) {
        return registry[id];
    }
}

interface Prototype {
    string GetID();
    Prototype Clone();
}

class Square : Prototype {
    private string id;
    private int x;
    private int y;
    private int side;

    public Square(int x, int y, int side) {
        this.id = "Square_" + x + "_" + y + "_" + side;
        this.x = x;
        this.y = y;
        this.side = side;
    }

    public string GetID() {
        return id;
    }

    public Prototype Clone() {
        return new Square(x, y, side);
    }
}

class Program {
    public static void Main(string[] args) {
        PrototypeRegistry registry = new PrototypeRegistry();
        Square square1 = new Square(1, 1, 1);
        Square square2 = new Square(2, 2, 2);
        Square square3 = new Square(3, 3, 3);
        registry.AddItem(square1);
        registry.AddItem(square2);
        registry.AddItem(square3);
    }
}

Program.Main(null);