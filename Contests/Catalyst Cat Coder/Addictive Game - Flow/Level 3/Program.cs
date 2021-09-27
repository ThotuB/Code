using System;
using System.IO;
using System.Collections.Generic;

namespace Level_3
{
    class Path {
        public uint id;
        public int invalidPos = -1;

        public uint color;
        public uint length;

        public uint cnt = 0;
        public uint[,] coords;
        public char[] directions;

        public Path(Game game, uint id, uint color, uint length, uint startingPosition) {
            this.id = id;
            this.color = color;
            this.length = length;

            this.coords = new uint[length + 1, 2];
            (this.coords[0, 0], this.coords[0, 1]) = game.PositionToCoords(startingPosition);
            this.directions = new char[length];
        }

        public void makeInvalid(int index) {
            if ( invalidPos == -1 ) {
                invalidPos = index;
            }
        }

        public void AddDirection(char direction) {
            directions[cnt] = direction;
            switch (direction)
            {
                case 'N':
                    coords[cnt + 1, 0] = coords[cnt, 0] - 1;
                    coords[cnt + 1, 1] = coords[cnt, 1];
                    break;
                case 'E':
                    coords[cnt + 1, 0] = coords[cnt, 0];
                    coords[cnt + 1, 1] = coords[cnt, 1] + 1;
                    break;
                case 'S':
                    coords[cnt + 1, 0] = coords[cnt, 0] + 1;
                    coords[cnt + 1, 1] = coords[cnt, 1];
                    break;
                case 'W':
                    coords[cnt + 1, 0] = coords[cnt, 0];
                    coords[cnt + 1, 1] = coords[cnt, 1] - 1;
                    break;
            }
            cnt++;
        }

        public override string ToString() {
            string result = "Path " + id + "(" + length + "): " + (( invalidPos == -1 ) ? "Valid" : "Invalid-" + invalidPos);
            result += "\nDirections: ";
            for (int i = 0; i < length; i++) {
                result += directions[i] + " ";
            }
            result += "\nCoords: ";
            for (int i = 0; i <= length; i++) {
                result += coords[i, 0] + "-" + coords[i, 1] + " ";
            }
            return result;
        }
    }

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

        public Boolean Compare(uint x, uint y) {
            return (x == this.x && y == this.y);
        }
    }

    class Game {
        public uint rows;
        public uint cols;

        public uint colors;

        public Dictionary<uint, Point[]> pointsByColor = new();
        public Dictionary<uint, Point> pointsByPosition = new();
        public List<Path> paths = new();

        public uint[,] table;

        public Game(uint rows, uint cols, uint colors) {
            this.rows = rows;
            this.cols = cols;

            this.colors = colors;

            this.table = new uint[rows+2, cols+2];
        }

        public void AddPoint(uint position, uint color) {
            (uint x, uint y) = PositionToCoords(position);

            Point point = new Point(position, x, y, color);

            table[x, y] = color;

            pointsByPosition.Add(position, point);

            if ( !pointsByColor.ContainsKey(color) ) {
                pointsByColor.Add(color, new Point[2]{point, null});
                return;
            }
            pointsByColor[color][1] = point;
        }

        public (Point, Point) GetPoints(uint color) {
            return (pointsByColor[color][0], pointsByColor[color][1]);
        }

        public Point GetPoint(uint position) {
            return pointsByPosition[position];
        }

        public Boolean IsInBounds(uint x, uint y) {
            return (x > 0 && x < cols + 1 && y > 0 && y < rows + 1);
        }

        public Boolean IsValidPath(Path path) {
            Point[] points = {pointsByColor[path.color][0], pointsByColor[path.color][1]};
            uint pnt = 0;

            if ( points[0].Compare(path.coords[0, 0], path.coords[0, 1]) ) {
                pnt = 1;
            }
            else if ( points[1].Compare(path.coords[0, 0], path.coords[0, 1]) ){
                pnt = 0;
            }
            else {
                path.makeInvalid(0);
            }
            for (uint i = 1; i < path.length ; i++){
                if ( table[path.coords[i, 0], path.coords[i, 1]] != 0 || !IsInBounds(path.coords[i, 0], path.coords[i, 1]) ) {
                    path.makeInvalid((int)i);
                }
                table[path.coords[i, 0], path.coords[i, 1]] = path.color;
            }
            if ( !points[pnt].Compare(path.coords[path.length, 0], path.coords[path.length, 1]) ) {
                path.makeInvalid((int)path.length);
            }

            return ( path.invalidPos == -1 );
        }

        public void AddPath(Path path) {
            // if ( !IsValidPath(path) ) {
            //     return;
            // }
            IsValidPath(path);

            paths.Add(path);
        }

        public (uint, uint) PositionToCoords(uint position){
            uint row = (position - 1) / cols + 1;
            uint col = (position - 1) % cols + 1;

            return (row, col);
        }

        public override string ToString() {
            string result = "";
            for (uint row = 1; row <= rows; row++) {
                for (uint col = 1; col <= cols; col++) {
                    result += table[row, col].ToString() + " ";
                }
                result += "\n";
            }
            return result;
        }
    }

    class Program {
        const string PATH = "level3-";
        const uint NR_FILES = 8;

        static void Main(string[] args) {
            for (uint i = 0 ; i < NR_FILES ; i++){
                using FileStream fsIn = File.OpenRead("Input/" + PATH + i + ".in");
                using FileStream fsOut = File.OpenWrite("Output/" + PATH + i + ".out");

                StreamWriter swOut = new StreamWriter(fsOut);

                string text = new StreamReader(fsIn).ReadToEnd();
                string[] words = text.Split(' ');

                uint rows = uint.Parse(words[0]);
                uint cols = uint.Parse(words[1]);
                uint nrPoints = uint.Parse(words[2]);

                Game game = new Game(rows, cols, nrPoints/2);

                for (uint j = 0 ; j < nrPoints ; j++){
                    uint position = uint.Parse(words[3 + j*2]);
                    uint color = uint.Parse(words[4 + j*2]);

                    game.AddPoint(position, color);
                }

                uint nrPaths = uint.Parse(words[3 + nrPoints*2]);

                for (uint j = 0 ; j < nrPaths ; j++){
                    uint color = uint.Parse(words[4 + nrPoints*2 + j*2]);
                    uint startingPosition = uint.Parse(words[5 + nrPoints*2 + j*2]);
                    uint length = uint.Parse(words[6 + nrPoints*2 + j*2]);

                    Path path = new Path(game, j, color, length, startingPosition);

                    for (uint k = 0 ; k < length ; k++){
                        char direction = words[7 + nrPoints*2 + j*2 + k][0];

                        path.AddDirection(direction);
                    }

                    game.AddPath(path);

                    Console.WriteLine(path);
                    swOut.Write( ( ( path.invalidPos == -1 ) ? "1 " + path.length : "-1 " + path.invalidPos) );
                }

                Console.WriteLine(game);

                swOut.Close();
            }
        }
    }
}
