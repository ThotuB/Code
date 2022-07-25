import java.util.*;

class A {
    public void method() {
        System.out.println("A");
    }
}

class B extends A {
    public void method() {
        System.out.println("B");
    }
}

class Test {
    public static void main(String[] args) {
        ArrayList<A> list = new ArrayList<A>();
        list.add(new A());
        list.add(new B());
        for (A a : list) {
            a.method();
        }
    }
}