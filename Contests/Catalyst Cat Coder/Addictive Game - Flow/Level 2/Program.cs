using System;
using System.IO;
using System.Collections.Generic;

namespace Level_2
{
    class Point {
        public uint position;
        public uint x, y;
        public uint color;

        public Point(uint position, uint x, uint y, uint color) {
            this.position = position;
            this.x = x;
            this.y = y; 
            this.color = color;
        }

        public uint ManhattanDistanceTo(Point p) {
            return (uint)Math.Abs((int)p.x - (int)x) + (uint)Math.Abs((int)p.y - (int)y);
        }
    }

    class Game {
        public uint rows;
        public uint cols;
        public Dictionary<uint, Point[]> points;
        public uint[,] table;

        public Game(uint rows, uint cols) {
            this.rows = rows;
            this.cols = cols;
            this.table = new uint[rows, cols];
            this.points = new Dictionary<uint, Point[]>();
        }

        public void AddPoint(uint position, uint color) {
            (uint x, uint y) = PositionToCoords(position);

            Point point = new Point(position, x, y, color);

            if ( !points.ContainsKey(color) ) {
                points.Add(color, new Point[2]{point, null});
                return;
            }
            points[color][1] = point;
        }

        public (Point, Point) GetPoints(uint color) {
            return (points[color][0], points[color][1]);
        }

        public (uint, uint) PositionToCoords(uint position){
            uint row = (position - 1) / cols + 1;
            uint col = (position - 1) % cols + 1;

            return (row, col);
        }
    }

    class Program {
        const string PATH = "level2-";

        static void Main(string[] args) {
            for (uint i = 0 ; i < 4 ; i++){
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
                    uint position = uint.Parse(words[3 + j*2]);
                    uint color = uint.Parse(words[4 + j*2]);

                    game.AddPoint(position, color);
                }

                for (uint j = 0 ; j < nrPoints/2 ; j++){
                    (Point point1, Point point2) = game.GetPoints(j + 1);

                    swOut.Write(point1.ManhattanDistanceTo(point2) + " ");
                }

                swOut.Close();
            }
        }
    }
}
