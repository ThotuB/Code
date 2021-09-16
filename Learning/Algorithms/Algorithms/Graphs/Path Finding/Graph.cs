using System;
using System.IO;
using System.Collections.Generic;

using PriorityQueue;

namespace Algorithms.Graphs.PathFinding {
    //! VERTEX CLASS
    public class Vertex {
        public char Name;
        public List<Edge> Edges;

        public int Distance = int.MaxValue;
        public Vertex Previous;
        public bool Visited;

        //* CONSTRUCTOR
        public Vertex(char name) {
            Name = name;
            Edges = new List<Edge>();
        }

        //* METHODS
        // Add a edge to the vertex
        public void AddEdge(Vertex vert, int weight) {
            Edges.Add(new Edge(vert, weight));
        }

        // Prints the vertex
        public override string ToString() {
            return Name.ToString();
        }
    }

    //! EDGE CLASS
    public class Edge {
        public int Weight;
        public Vertex To;

        //* CONSTRUCTOR
        public Edge(Vertex vertex, int weight) {
            To = vertex;
            Weight = weight;
        }

        //* METHODS
        // Prints the edge
        public override string ToString() {
            return $" -> {To.Name} ({Weight})";
        }
    }
    
    //! GRAPH CLASS
    public class Graph {
        public Dictionary<char, Vertex> Vertices;

        //* CONSTRUCTOR
        public Graph(string fileName) {
            Vertices = new Dictionary<char, Vertex>();
            Populate(fileName);
        }

        //* METHODS
        // Add Vertex
        public void AddVertex(char value) {
            if (Vertices.ContainsKey(value)) {
                return;
            }

            Vertices[value] = new Vertex(value);
        }

        // Add Edge
        public void AddEdge(char vert1, char vert2, int weight) {
            AddVertex(vert1);
            AddVertex(vert2);

            Vertices[vert1].AddEdge(Vertices[vert2], weight);
            Vertices[vert2].AddEdge(Vertices[vert1], weight);
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
                return Vertices[index];
            }
        }

        // Print Vertices and Edges
        public override string ToString() {
            string output = "";
            foreach (var vertex in Vertices) {
                output += "Vertex " + vertex.Value + ":\n";
                foreach (var edge in vertex.Value.Edges) {
                    output += edge.ToString() + "\n";
                }
            }
            return output;
        }
    }
}