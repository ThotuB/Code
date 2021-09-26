using System;
using System.Collections.Generic;

namespace Algorithms.PathFinding {
    public class Node : IComparable<Node> {
        public int X { get; }
        public int Y { get; }

        public bool Walkable;

        public Node Parent;
        
        public int FCost { get; private set; }

        public Node(int x, int y) {
            X = x;
            Y = y;

            Walkable = true;
            
            FCost = int.MaxValue;
        }

        public static int Distance(Node a, Node b) {
            var dx = Math.Abs(a.X - b.X);
            var dy = Math.Abs(a.Y - b.Y);

            if (dx > dy) {
                return 14 * dy + 10 * (dx - dy);
            }
            return 14 * dx + 10 * (dy - dx);
        }

        public void Update(Node parent, int fCost) {
            Parent = parent;
            FCost = fCost;
        }

        // Path from start to this node
        public List<Node> Path() {
            var path = new List<Node>();
            for (var node = this; node != null; node = node.Parent) { // parent traversal
                path.Add(node);
            }
            path.Reverse();
            return path;
        }

        public int CompareTo(Node other) {
            return FCost.CompareTo(other.FCost);
        }

        public override string ToString() {
            return (Walkable) ? "O" : "X";
        }
    }
    
    public class Grid {
        public int Width { get; }
        public int Height { get; }
        private Node[,] _grid;

        public Grid(int width, int height) {
            Width = width;
            Height = height;

            _grid = new Node[height, width];
            ResetGrid();
        }

        public void ResetGrid() {
            for (var y = 0; y < Height; y++) {
                for (var x = 0; x < Width; x++) {
                    _grid[y, x] = new Node(x, y);
                }
            }
        }

        public void PlaceWall(params (int y, int x)[] walls) {
            foreach (var (y, x) in walls) {
                _grid[y, x].Walkable = false;
            }
        }

        public List<Node> Neighbors(Node node) {
            var neighbours = new List<Node>();
            for (var y = -1; y <= 1; y++) {
                for (var x = -1; x <= 1; x++) {
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    var neighbourX = node.X + x;
                    var neighbourY = node.Y + y;
                    if (neighbourX < 0 || neighbourX >= Width || neighbourY < 0 || neighbourY >= Height) {
                        continue;
                    }
                    neighbours.Add(_grid[neighbourY, neighbourX]);
                }
            }
            return neighbours;
        }

        public Node this[int x, int y] {
            get => _grid[y, x];
        }

        public override string ToString() {
            var output = "";
            for (var y = 0; y < Height; y++) {
                for (var x = 0; x < Width; x++) {
                    output += _grid[y, x] + " ";
                }
                output += "\n";
            }
            return output;
        }
    }
}