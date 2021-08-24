interface IVector {
    float CalcMagnitude();
}

class Vector2D : IVector {
    float x;
    float y;

    public Vector2D(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public float CalcMagnitude() {
        return (float)Math.Sqrt(x * x + y * y);
    }
}

class Vector3D : IVector {
    float x;
    float y;
    float z;

    public Vector3D(float x, float y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public float CalcMagnitude() {
        return (float)Math.Sqrt(x * x + y * y + z * z);
    }
}

class VectorFactory {
    public static IVector CreateVector(float x, float y) {
        return new Vector2D(x, y);
    }

    public static IVector CreateVector(float x, float y, float z) {
        return new Vector3D(x, y, z);
    }
}

class Program1 {
    public static void Main(String[] args) {
        IVector v = VectorFactory.CreateVector(3.0f, 4.0f);
        Console.WriteLine(v.CalcMagnitude());
    }
}

Program1.Main(null);