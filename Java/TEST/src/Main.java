class MyObject {
    public int x;

    public MyObject(int x){
        this.x = x;
    }

    @Override
    public String toString() {
        return "Obj: {\n" +
                "\t\"x\": " + x + "\n" +
                "}";
    }
}

class MyObjectChanger {
    public static void changeObj(MyObject obj) {
        obj = new MyObject(4);
    }
}

public class Main {
    public static void main(String[] args){
        MyObject o = new MyObject(1);
        System.out.println(o);
        MyObjectChanger.changeObj(o);
        System.out.println(o);
    }
}
