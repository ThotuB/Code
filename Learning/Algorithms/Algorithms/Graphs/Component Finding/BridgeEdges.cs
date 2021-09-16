using System;
using System.Collections.Generic;

using PriorityQueue;
using Algorithms.Graphs.ComponentFinding;

namespace Algorithms.Graphs {
    public class BridgeEdges {
        public static List<Edge> Find(Graph graph) {
            var list = new List<Edge>();

            DFS(graph, list);

            PrintList(list);

            return list;

            void DFS(Graph graph, List<Edge> list) {
                int time = 0;
                foreach (var vertex in graph.Vertices) { 
                    if ( !vertex.Visited ) {
                        DFSVisit(graph, vertex, list, ref time);
                    }
                }
            }

            void DFSVisit(Graph graph, Vertex vertex, List<Edge> list, ref int time) {
                vertex.Visited = true; // mark vertex as visited
                vertex.Low = vertex.DiscoveryTime = ++time; // set discovery time and low time

                foreach (var neighbor in vertex.Neighbors) { // for each neighbor
                    if ( !neighbor.Visited ) { // if neighbor is not visited
                        neighbor.Parent = vertex; // set parent

                        DFSVisit(graph, neighbor, list, ref time); // visit neighbor

                        vertex.Low = Math.Min(vertex.Low, neighbor.Low); // update low time

                        if ( neighbor.Low > vertex.DiscoveryTime ) { // if neighbor's low time is greater than vertex's discovery time
                            list.Add(graph[vertex, neighbor]); // add vertex to list
                        }
                    } 
                    else if ( neighbor != vertex.Parent ) { // if neighbor is visited and is not parent
                        vertex.Low = Math.Min(vertex.Low, neighbor.DiscoveryTime); // update low time
                    }
                }
            }
        }

        //* Helper Methods
        // Print List - Graph version
        public static void PrintList(List<Edge> list) {
            foreach (Edge edge in list) {
                Console.WriteLine(edge);
            }
            Console.WriteLine();
        }
    }
}