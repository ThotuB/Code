using System;
using System.Collections.Generic;

using PriorityQueue;
using Algorithms.Graphs.PathFinding;

namespace Algorithms.Graphs {
    public class Dijkstra {
        public static void UpdateDistances(Graph graph, char start) {
            UpdateDistances(graph[start]);

            Console.WriteLine(graph);

            void UpdateDistances(Vertex vertex) {
                vertex.Distance = 0; // set distance to start vertex to 0

                var queue = new PriorityQueue<int, Vertex>();
                queue.Enqueue(vertex.Distance, vertex); // enqueue the start vertex

                while (!queue.IsEmpty()) { // while the queue is not empty
                    Vertex current = queue.Dequeue().Value; // dequeue the vertex with the smallest distance

                    foreach (Edge edge in current.Edges) { // for each edge of the current vertex
                        Vertex neighbor = edge.To; // get the edge 'to' vertex

                        // Relax edge if necessary
                        if (neighbor.Distance > current.Distance + edge.Weight) { // if the distance to the neighbor is greater than the distance to the current vertex + the edge weight
                            neighbor.Distance = current.Distance + edge.Weight; // update the distance to the neighbor
                            neighbor.Previous = current; // update the previous vertex

                            queue.Enqueue(neighbor.Distance, neighbor); // enqueue the neighbor
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