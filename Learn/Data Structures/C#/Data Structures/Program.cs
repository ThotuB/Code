using System;
using System.IO;
using System.Threading;

using Data_Structures.Array;
using Data_Structures.List;
using Data_Structures.Stack;
using Data_Structures.Queue;
using Data_Structures.Tree;

namespace Data_Structures
{
    internal static class Program
    {
        private const string path = @"..\\resources\\heap.txt";

        private static void WriteToFile(string text)
        {
            File.WriteAllText(path, text);
            Thread.Sleep(1000);
        }

        public static void Main(string[] args)
        {
            var datastruct = new AVL<int>();
            int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            foreach (int item in arr)
            {
                datastruct.Add(item);
            }
            // Console.WriteLine(datastruct.InOrder());
        }
    }
}