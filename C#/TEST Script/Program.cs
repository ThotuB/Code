using System;
using System.Collections.Generic;

class Program {
    public static void Main(string[] args) {
        var list = new List<int>(5);
        list.Add(1);
        list.Add(2);
        list.Add(3);
        list.Add(4);
        list.Add(5);
        list.Add(6);
        list.Add(7);
        list.Add(8);
        list.Add(9);
        list.Add(10);
        list.Add(11);
        Console.WriteLine(list.Capacity);
    }
}

Program.Main(null)