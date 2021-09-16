using System;
using System.Collections.Generic;

class Program {
    public static void Print(int[] arr) {
        
    }

    public static void Main(string[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        Print(arr);
        Change(ref arr);
        Print(arr);
    }
}

Program.Main(null)