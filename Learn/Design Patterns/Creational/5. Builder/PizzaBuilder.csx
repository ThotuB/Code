class Pizza {
    public class Builder {
        private string name;

        private int size;
        private int price;

        private string[] toppings;
        private string[] sauces;

        public Builder(string name) {
            this.name = name;
        }

        public Builder OfSize(int size) {
            this.size = size;
            return this;
        }

        public Builder WithPrice(int price) {
            this.price = price;
            return this;
        }

        public Builder AddToppings(string[] toppings) {
            this.toppings = toppings;
            return this;
        }

        public Builder AddSauces(string[] sauces) {
            this.sauces = sauces;
            return this;
        }

        public Pizza Build() {
            Pizza pizza = new Pizza();

            pizza.name = name;
            pizza.size = size;
            pizza.price = price;
            pizza.toppings = toppings;
            pizza.sauces = sauces;

            return pizza;
        }
    }

    private string name;
    private int size;
    private int price;

    private string[] toppings;
    private string[] sauces;

    private Pizza() {}

    public override string ToString() {
        return "Pizza: " + name + "\n - size: " + size + "cm\n - price: " + price 
            + "\u20AC\n - toppings: " + string.Join(", ", toppings) + "\n - sauces: " + string.Join(", ", sauces);
    }
}


class Program {
    public static void Main(string[] args) {
        Pizza pizza = new Pizza.Builder("Pizza")
            .OfSize(20)
            .WithPrice(12)
            .AddToppings(new string[] { "Pepperoni", "Mushrooms", "Onions" })
            .AddSauces(new string[] { "Marinara", "Garlic" })
            .Build();
        Console.WriteLine(pizza);
    }
}

Program.Main(null);