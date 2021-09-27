using System;
using System.Collections.Generic;

using PriorityQueue;
using Algorithms.Graphs.Traversals;

namespace Algorithms.Graphs {
    public class BFS {
        public static List<char> Traverse(Graph graph, char start) {
            var list = new List<char>();

            Traverse(graph[start], list);

            PrintList(list);

            return list;

            void Traverse(Vertex vertex, List<char> list) {
                var queue = new Queue<Vertex>();
                queue.Enqueue(vertex); // enqueue the start vertex
                vertex.Visited = true; // mark the start vertex as visited

                while ( queue.Count > 0 ) {
                    var current = queue.Dequeue(); // get next vertex in queue
                    list.Add(current.Name); 

                    foreach ( Vertex neighbor in current.Neighbors ) { // foreach neighbor of current
                        if ( !neighbor.Visited ) { // if not visited
                            queue.Enqueue(neighbor); // add to queue
                            neighbor.Visited = true; // mark as visited
                        }
                    }
                }
            }
        }

        /// Helper Methods
        // Print List
        public static void PrintList(List<char> list) {
            foreach (char item in list) {
                Console.Write(item + " ");
            }
            Console.WriteLine();
        }
    }
}