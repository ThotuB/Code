abstract class ProductA {
    abstract public void UseA();
}

class ProductA1 : ProductA {
    public override void UseA() {
        Console.WriteLine("ProductA1");
    }
}

class ProductA2 : ProductA {
    public override void UseA() {
        Console.WriteLine("ProductA2");
    }
}

abstract class ProductB {
    abstract public void UseB(); 
}

class ProductB1 : ProductB {
    public override void UseB() {
        Console.WriteLine("ProductB1");
    }
}

class ProductB2 : ProductB {
    public override void UseB() {
        Console.WriteLine("ProductB2");
    }
}

abstract class Factory {
    abstract public ProductA CreateProductA();
    abstract public ProductB CreateProductB();
}

class Product1Factory : Factory {
    public override ProductA CreateProductA() {
        return new ProductA1();
    }
    public override ProductB CreateProductB() {
        return new ProductB1();
    }
}

class Product2Factory : Factory {
    public override ProductA CreateProductA() {
        return new ProductA2();
    }
    public override ProductB CreateProductB() {
        return new ProductB2();
    }
}


class Program {
    public static void Main(String[] args) {
        Factory factory = new Product1Factory();
        ProductA product = factory.CreateProductA();
        product.UseA();
    }
}

Program.Main(null);