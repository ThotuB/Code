interface IProduct {
    void Use();
}

class ProductA : IProduct {
    public void Use() {
        Console.WriteLine("Product: A");
    }
}

class ProductB : IProduct {
    public void Use() {
        Console.WriteLine("Product: B");
    }
}

class Factory {
    public static IProduct CreateProduct(string type) {
        switch ( type ) {
            case "A":
                return new ProductA();
            case "B":
                return new ProductB();
            default:
                return null;
        }
    }
}

class Program1 {
    public static void Main(String[] args) {
        IProduct p = Factory.CreateProduct("A");
        p.Use();
    }
}

Program1.Main(null);