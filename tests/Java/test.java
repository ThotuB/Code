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
        try {
            return;
        } finally {
            System.out.println("Finally");
        }
    }
}