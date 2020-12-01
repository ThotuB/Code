class Operation {
    public static void performDivision(int number, int divisor) throws Exception{
        if ( divisor == 0 ){
            throw new Exception("Division by 0");
        }
        System.out.println((float)number/divisor);
    }
}

// class DivisionByZeroException extends Exception {
//     public DivisionByZeroException(){
//         super("Cannot Divide by Zero");
//     }
// }

public class Prob8_2 {
    public static void main(String[] args){
        //Operation.performDivision(4, 3);
        //Operation.performDivision(4, 0);

        int[] c = new int[3];
        System.out.println(c[5]);
    }
}
