using System;
using System.Collections.Generic;

using PriorityQueue;
using Algorithms.Graphs.Traversals;

namespace Algorithms.Graphs {
    public class DFS {
        // Graph version
        public static List<char> Traverse(Graph graph, char start) {
            var list = new List<char>();

            Traverse_Iterative(graph[start], list);

            PrintList(list);

            return list;

            //* Recursive version
            void Traverse_Recursive(Vertex vertex, List<char> list) {
                list.Add(vertex.Name);
                vertex.Visited = true; // mark as visited

                foreach (Vertex neighbor in vertex.Neighbors) { // for each neighbor of vertex
                    if (!neighbor.Visited) { // if not visited
                        Traverse_Recursive(neighbor, list); // traverse it
                    }
                }
            }

            //* Iterative version
            void Traverse_Iterative(Vertex vertex, List<char> list) {
                var queue = new Stack<Vertex>();
                queue.Push(vertex);

                while (queue.Count > 0) {
                    vertex = queue.Pop(); // pop vertex from stack

                    if (vertex.Visited) { // if visited
                        continue; // skip
                    }
                
                    list.Add(vertex.Name);
                    vertex.Visited = true; // mark as visited

                    foreach (Vertex neighbor in vertex.Neighbors) { // for each neighbor of vertex
                        if (!neighbor.Visited) { // if not visited
                            queue.Push(neighbor); // push to stack
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