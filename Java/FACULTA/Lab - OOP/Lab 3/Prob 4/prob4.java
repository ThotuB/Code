class Sum {
    public static int sum(int a,  int b){
        return a + b;
    }

    public static int sum(int a, int b, int c){
        return sum(a, b) + c;
    }

    public static int sum(int a, int b, int c, int d){
        return sum(a, b, c) + d;
    }
}

class prob4 {
    public static void main(String[] args){
        int s = Sum.sum(2, 4, -2, 6);

        System.out.println("Sum: " + s);
    }
}