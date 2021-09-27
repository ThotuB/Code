using System;
using System.Collections.Generic;

using PriorityQueue;
using Algorithms.Graphs.PathFinding;

namespace Algorithms.Graphs {
    public class BellmanFord {
        public static void UpdateDistances(Graph graph, char start) {
            UpdateDistances(graph, graph[start]);

            Console.WriteLine(graph);

            void UpdateDistances(Graph graph, Vertex vertex) {
                vertex.Distance = 0; // set distance to start vertex to 0

                for (int i = 0 ; i < graph.Vertices.Count - 1 ; i++) { // V - 1 times (max)
                    foreach (var kvp in graph.Vertices) { // for each vertex
                        Vertex v = kvp.Value;
                        foreach (Edge edge in v.Edges) { // for each edge from vertex
                            Vertex u = edge.To;

                            // Relax edge (u, v) if necessary
                            if (u.Distance > v.Distance + edge.Weight) {
                                u.Distance = v.Distance + edge.Weight; // update distance
                                u.Previous = v; // update previous
                            }
                        }
                    }
                }
            }
        }

        public static List<Vertex> FindShortestPath(Graph graph, char start, char end) {
            var list = new List<Vertex>();

            UpdateDistances(graph, start);

            for (Vertex current = graph[end]; current != null; current = current.Previous) {
                list.Add(current);
            }
            list.Reverse();

            PrintList(list);

            return list;
        }


        /// Helper Methods
        // Print List - Graph version
        public static void PrintList(List<Vertex> list) {
            foreach (Vertex vertex in list) {
                Console.Write(vertex.Name + " ");
            }
            Console.WriteLine();
        }
    }
}