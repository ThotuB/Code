interface Prototype {
    Prototype Clone();
}

class Vector2 : Prototype {
    protected int x;
    protected int y;

    public Vector2(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Prototype Clone() {
        return new Vector2(x, y);
    }
}

class Vector3 : Vector2 {
    private int z;

    public Vector3(int x, int y, int z) : base(x, y) {
        this.z = z;
    }

    public new Prototype Clone() {
        return new Vector3(x, y, z);
    }
}

class Program {
    public static void Main(string[] args) {
        Vector2 v1 = new Vector2(1, 2);
        Vector2 v2 = (Vector2)v1.Clone();
        Vector3 v3 = new Vector3(1, 2, 3);
        Vector3 v4 = (Vector3)v3.Clone();
    }
}

Program.Main(null);