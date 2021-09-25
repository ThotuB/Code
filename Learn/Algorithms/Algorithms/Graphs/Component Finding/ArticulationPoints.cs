using System;
using System.Collections.Generic;

using PriorityQueue;
using Algorithms.Graphs.ComponentFinding;

namespace Algorithms.Graphs {
    public class ArticulationPoints {
        public static List<Vertex> Find(Graph graph) {
            var list = new List<Vertex>();

            DFS(graph, list);

            PrintList(list);

            return list;

            void DFS(Graph graph, List<Vertex> list) {
                int time = 0;
                foreach (var vertex in graph.Vertices) { 
                    if ( !vertex.Visited ) {
                        DFSVisit(graph, vertex, list, ref time);
                    }
                }
            }

            void DFSVisit(Graph graph, Vertex vertex, List<Vertex> list, ref int time) {
                vertex.Visited = true; // mark vertex as visited
                vertex.Low = vertex.DiscoveryTime = ++time; // set discovery time and low time

                int children = 0;
                foreach (var neighbor in vertex.Neighbors) { // for each neighbor
                    if ( !neighbor.Visited ) { // if neighbor is not visited
                        children++; // increment children
                        neighbor.Parent = vertex; // set parent of neighbor as vertex

                        DFSVisit(graph, neighbor, list, ref time); // visit neighbor DFS style

                        vertex.Low = Math.Min(vertex.Low, neighbor.Low); // update low time

                        if ( vertex.Parent == null && children > 1 ) { // if vertex has no parent and has more than one child
                            list.Add(vertex); //? ARTICULATION POINT
                        }
                        if ( vertex.Parent != null && neighbor.Low >= vertex.DiscoveryTime ) { // if vertex has parent and neighbor's low time is greater than vertex's discovery time
                            list.Add(vertex); //? ARTICULATION POINT
                        }

                    } 
                    else if ( neighbor != vertex.Parent ) { // if neighbor is visited and is not parent
                        vertex.Low = Math.Min(vertex.Low, neighbor.DiscoveryTime); // update low time
                    }
                }
            }
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