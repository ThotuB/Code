using System;
using System.IO;
using System.Collections.Generic;

using PriorityQueue;

namespace Algorithms.Graphs.ComponentFinding {
    //! VERTEX CLASS
    public class Vertex {
        public char Name;
        public List<Vertex> Neighbors;

        public int DiscoveryTime; // time of discovering the vertex
        public int FinishTime; // time of finishing processing the vertex
        public int Low; // lowest discovery time

        public Vertex Parent;
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

    //! EDGE CLASS
    public class Edge {
        public Vertex From;
        public Vertex To;

        //* CONSTRUCTOR
        public Edge(Vertex from, Vertex to) {
            From = from;
            To = to;
        }

        //* METHODS
        // Prints the edge
        public override string ToString() {
            return From.Name + " -> " + To.Name;
        }
    }

    //! GRAPH CLASS
    public class Graph {
        public List<Vertex> Vertices;
        private Dictionary<char, Vertex> _vertexMap;

        //* CONSTRUCTOR
        public Graph(string fileName) {
            Vertices = new List<Vertex>();
            _vertexMap = new Dictionary<char, Vertex>();
            Populate(fileName);
        }

        //* METHODS
        // Add Vertex
        public void AddVertex(char value) {
            if (_vertexMap.ContainsKey(value)) {
                return;
            }

            Vertex v = new Vertex(value);

            Vertices.Add(v);
            _vertexMap[value] = v;
        }

        // Add Edge
        public void AddEdge(char vert1, char vert2) {
            AddVertex(vert1);
            AddVertex(vert2);

            _vertexMap[vert1].AddNeighbor(_vertexMap[vert2]);
            _vertexMap[vert2].AddNeighbor(_vertexMap[vert1]);
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
            get => _vertexMap[index];
        }

        public Edge this[Vertex from, Vertex to] {
            get => new Edge(from, to);
        }

        // Print Vertices and Edges
        public override string ToString() {
            string output = "";
            foreach (var vertex in Vertices) {
                output += "Vertex " + vertex + ":\n";
                foreach (var vert in vertex.Neighbors) {
                    output += " -> " + vert.ToString() + "\n";
                }
            }
            return output;
        }
    }
}