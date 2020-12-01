class MyException extends Exception {
    private static int instances = 0;

    public MyException(String exceptionStr){
        super(exceptionStr);
        instances++;
    }

    public static int getNrInstances(){
        return instances;
    }
}

public class Prob8_6 {
    public static void main(String[] args) throws Exception{
        MyException e1 = new MyException("exception 1");
        System.out.println(e1);
        System.out.println(MyException.getNrInstances());

        MyException e2 = new MyException("exception 2");
        System.out.println(e2);
        System.out.println(MyException.getNrInstances());

        MyException e3 = new MyException("exception 3");
        System.out.println(e3);
        System.out.println(MyException.getNrInstances());
    }
}
