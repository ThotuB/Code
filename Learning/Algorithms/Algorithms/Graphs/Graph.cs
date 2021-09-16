using System;
using System.IO;
using System.Collections.Generic;

using PriorityQueue;

namespace Algorithms.Graphs.Common {
    public class Graph {
        private Dictionary<char, Vertex> _vertices;

        /// EDGE CLASS
        public class Edge {
            public int Weight;
            public Vertex To;

            // Constructor
            public Edge(Vertex vertex, int weight) {
                To = vertex;
                Weight = weight;
            }

            // Prints the edge
            public override string ToString() {
                return $" -> {To.Name} ({Weight})";
            }
        }

        /// VERTEX CLASS
        public class Vertex {
            public char Name;
            public List<Edge> Edges;
            public Dictionary<char, int> Distances;

            public int Distance = int.MaxValue;
            public Vertex Previous;
            public bool Visited;

            // Constructor
            public Vertex(char name) {
                Name = name;
                Edges = new List<Edge>();
                Distances = new Dictionary<char, int>();
            }

            // Add a edge to the vertex
            public void AddEdge(Vertex vert, int weight) {
                Edges.Add(new Edge(vert, weight));
                Distances[vert.Name] = weight;
            }

            // Gets distance to a vertex
            public int this[char vert] {
                get {
                    if (Distances.ContainsKey(vert)) {
                        return Distances[vert];
                    }
                    return int.MaxValue;
                }
            }

            // Prints the vertex
            public override string ToString() {
                return Name.ToString();
            }
        }

        // Constructor
        public Graph(string fileName) {
            _vertices = new Dictionary<char, Vertex>();
            Populate(fileName);
        }

        // Add Vertex
        public void AddVertex(char value) {
            if (_vertices.ContainsKey(value)) {
                return;
            }

            _vertices[value] = new Vertex(value);
        }

        // Add Edge
        public void AddEdge(char vert1, char vert2, int weight) {
            AddVertex(vert1);
            AddVertex(vert2);

            _vertices[vert1].AddEdge(_vertices[vert2], weight);
            _vertices[vert2].AddEdge(_vertices[vert1], weight);
        }

        // Add Vertices and Edges from file
        public void Populate(string fileName) {
            string[] lines = File.ReadAllLines(fileName);

            for (int i = 1 ; i < lines.Length ; i++) {
                string[] values = lines[i].Split(' ');

                char vert1 = values[0][0];
                char vert2 = values[1][0];
                int weight = int.Parse(values[2]);

                AddEdge(vert1, vert2, weight);
            }
        }

        // Get Vertex
        public Vertex this[char index]{
            get {
                return _vertices[index];
            }
        }

        // Print Vertices and Edges
        public override string ToString() {
            string output = "";
            foreach (var vertex in _vertices) {
                output += "Vertex " + vertex.Value + ":\n";
                foreach (var edge in vertex.Value.Edges) {
                    output += edge.ToString() + "\n";
                }
            }
            return output;
        }
    }

    public class Graph_AdjMatrix {
        private int[,] _matrix;
        private int _size;

        // Constructor
        public Graph_AdjMatrix(string fileName) {
            Populate(fileName);
        }

        // Char and Index Converters
        private int CharToIndex(char c) {
            return c - 'A';
        }

        private char IndexToChar(int i) {
            return (char)(i + 'A');
        }

        // Add Edge
        public void AddEdge(char from, char to, int weight) {
            int vert1 = CharToIndex(from);
            int vert2 = CharToIndex(to);

            Console.WriteLine($"Adding edge from {vert1} to {vert2} with weight {weight}");

            _matrix[vert1, vert2] = weight;
            _matrix[vert2, vert1] = weight;
        }

        // Add Vertices and Edges from file
        public void Populate(string fileName) {
            string[] lines = File.ReadAllLines(fileName);
            int numVertices = int.Parse(lines[0]);

            this._size = numVertices;
            this._matrix = new int[_size, _size];

            for (int i = 1 ; i < lines.Length ; i++) {
                string[] values = lines[i].Split(' ');

                char vert1 = values[0][0];
                char vert2 = values[1][0];
                int weight = int.Parse(values[2]);

                AddEdge(vert1, vert2, weight);
            }
        }

        // Get Vertex
        public int[] this[char index] {
            get {
                int vert = CharToIndex(index);
                int[] row = new int[_size];
                for (int i = 0 ; i < _size ; i++) {
                    row[i] = _matrix[vert, i];
                }
                return row;
            }
        }

        public int this[char from, char to] {
            get => _matrix[CharToIndex(from), CharToIndex(to)];
        }

        // Print Vertices and Edges
        public override string ToString() {
            string output = "  ";
            for (int i = 0 ; i < _size ; i++) {
                output += IndexToChar(i) + "\t";
            }
            output += "\n";
            for (int i = 0 ; i < _size ; i++) {
                output += IndexToChar(i) + " ";
                for (int j = 0 ; j < _size ; j++) {
                    output += _matrix[i, j] + "\t";
                }
                output += "\n";
            }
            return output;
        }
    }
}