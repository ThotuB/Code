using System;
using System.IO;
using System.Collections.Generic;

using PriorityQueue;

namespace Algorithms.Graphs.Traversals {
    //! VERTEX CLASS
    public class Vertex {
        public char Name;
        public List<Vertex> Neighbors;

        public bool Visited;

        //* CONSTRUCTOR
        public Vertex(char name) {
            Name = name;
            Neighbors = new List<Vertex>();
        }

        //* METHODS
        // Add a edge to the vertex
        public void AddNeighbor(Vertex vert) {
            Neighbors.Add(vert);
        }

        // Prints the vertex
        public override string ToString() {
            return Name.ToString();
        }
    }

    //! GRAPH CLASS
    public class Graph {
        private Dictionary<char, Vertex> _vertices;

        //* CONSTRUCTOR
        public Graph(string fileName) {
            _vertices = new Dictionary<char, Vertex>();
            Populate(fileName);
        }

        //* METHODS
        // Add Vertex
        public void AddVertex(char value) {
            if (_vertices.ContainsKey(value)) {
                return;
            }

            _vertices[value] = new Vertex(value);
        }

        // Add Edge
        public void AddEdge(char vert1, char vert2) {
            AddVertex(vert1);
            AddVertex(vert2);

            _vertices[vert1].AddNeighbor(_vertices[vert2]);
            _vertices[vert2].AddNeighbor(_vertices[vert1]);
        }

        // Add Vertices and Edges from file
        public void Populate(string fileName) {
            string[] lines = File.ReadAllLines(fileName);

            for (int i = 1 ; i < lines.Length ; i++) {
                string[] values = lines[i].Split(' ');

                char vert1 = values[0][0];
                char vert2 = values[1][0];

                AddEdge(vert1, vert2);
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
                var v = vertex.Value;
                output += "Vertex " + v + ":\n";
                foreach (var neighbor in v.Neighbors) {
                    output += " -> " + neighbor + "\n";
                }
            }
            return output;
        }
    }
}