using System;
using System.IO;
using System.Collections.Generic;

using PriorityQueue;

namespace Algorithms.Graphs.MST {
    //! VERTEX CLASS
    public class Vertex {
        public char Name;

        public bool Visited;

        //* CONSTRUCTOR
        public Vertex(char name) {
            Name = name;
        }

        //* METHODS
        public override string ToString() {
            return Name.ToString();
        }
    }

    //! EDGE CLASS
    public class Edge {
        public Vertex From;
        public Vertex To;

        public int Weight;

        //* CONSTRUCTOR
        public Edge(Vertex from, Vertex to, int weight) {
            From = from;
            To = to;
            Weight = weight;
        }

        //* METHODS
        // Prints the edge
        public override string ToString() {
            return $"{From} -> {To} ({Weight})";
        }
    }
    
    //! GRAPH CLASS
    public class Graph {
        public List<Edge> Edges;
        
        //* CONSTRUCTOR
        public Graph(string fileName) {
            Edges = new List<Edge>();
            Populate(fileName);
        }

        //* METHODS
        // Add Edge
        public void AddEdge(char vert1, char vert2, int weight) {
            Edges.Add(new Edge(new Vertex(vert1), new Vertex(vert2), weight));
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

        // Prints the edges
        public override string ToString() {
            string result = "";
            foreach (Edge edge in Edges) {
                result += $"{edge}\n";
            }
            return result;
        }
    }
}