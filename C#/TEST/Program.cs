using System;

namespace TEST
{
    class Program
    {
        public static (int, int) return_tuple(){
            return (1, 2);
        }

        static void Main(string[] args)
        {
            (int x, int y) = Program.return_tuple();
            Console.WriteLine(x + y);
        }
    }
}
