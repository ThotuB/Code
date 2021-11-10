interface IProduct {
    void Use();
}

class ProductA : IProduct {
    public void Use() {
        Console.WriteLine("Product: A");
    }
}

abstract class Factory {
    abstract public IProduct CreateProduct();

    public void UseProduct(IProduct product){
        product.Use();
    }
}

class ProductAFactory : Factory {
    public override IProduct CreateProduct() {
        return new ProductA();
    }
}


class Program {
    public static void Main(String[] args) {
        Factory factory = new ProductAFactory();
        IProduct product = factory.CreateProduct();
        factory.UseProduct(product);
    }
}

Program.Main(null);