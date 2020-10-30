public class Test {
    private int nr;

    public Test(int n){
        nr = n;
    }

    public void print(){
        System.out.print(nr + "\n");
    }

    public static void main(String[] args){
        Test t = new Test(3);
        t.print();
    }
}
