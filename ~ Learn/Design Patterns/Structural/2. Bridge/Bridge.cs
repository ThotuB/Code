abstract class Shape {
    protected Color color;

    public Shape(Color color) {
        this.color = color;
    }

    public abstract void Paint();
}

class Square : Shape {
    public Square(Color color) : base(color) { }

    public override void Paint() {
        Console.Write("Square: ");
        color.Apply();
    }
}

class Circle : Shape {
    public Circle(Color color) : base(color) { }

    public override void Paint() {
        Console.Write("Circle: ");
        color.Apply();
    }
}

interface Color {
    void Apply();
}

class Red : Color {
    public void Apply() {
        Console.WriteLine("Painted Red");
    }
}

class Blue : Color {
    public void Apply() {
        Console.WriteLine("Painted Blue");
    }
}

class Program {
    public static void Main(string[] args) {
        Shape s = new Square(new Red());
        s.Paint();
    }
}

Program.Main(null);