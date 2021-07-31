using System;
using System.IO;

namespace Level_1
{
    class Game {
        uint rows;
        uint cols;
        uint[,] table;

        public Game(uint rows, uint cols) {
            this.rows = rows;
            this.cols = cols;
            this.table = new uint[rows, cols];
        }

        public (uint, uint) position_to_coords(uint position){
            uint row = (position - 1) / cols + 1;
            uint col = (position - 1) % cols + 1;

            return (row, col);
        }
    }

    class Program {
        const string PATH = "level1-";

        static void Main(string[] args) {
            for (uint i = 0 ; i < 1 ; i++){
                using FileStream fsIn = File.OpenRead(PATH + i + ".in");
                using FileStream fsOut = File.OpenWrite(PATH + i + ".out");

                StreamWriter swOut = new StreamWriter(fsOut);

                string text = new StreamReader(fsIn).ReadToEnd();
                string[] words = text.Split(' ');

                uint rows = uint.Parse(words[0]);
                uint cols = uint.Parse(words[1]);
                uint nrPoints = uint.Parse(words[2]);

                Game game = new Game(rows, cols);

                for (uint j = 0 ; j < nrPoints ; j++){
                    uint position = uint.Parse(words[3 + j]);

                    (uint x, uint y) = game.position_to_coords(position);

                    swOut.Write(x + " " + y + " ");
                }

                swOut.Close();
            }
        }
    }
}
