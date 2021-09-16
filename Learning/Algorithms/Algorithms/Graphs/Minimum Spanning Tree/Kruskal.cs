using System;
using System.Collections.Generic;

using PriorityQueue;
using Algorithms.Graphs.MST;

namespace Algorithms.Graphs {
    public class Kruskal {
        public static List<Edge> FindMST(Graph graph) {
            var mst = new List<Edge>();

            // FindMST(graph, mst);

            PrintList(mst);

            return mst;

            // void FindMST(Graph graph, List<Edge> mst) {
            //     var pq = new PriorityQueue<Edge>();

            //     foreach (var edge in graph.Edges) {
            //         pq.Enqueue(edge);
            //     }


        }

        //* HELPER METHODS
        // Print list
        private static void PrintList(List<Edge> list) {
            foreach (var edge in list) {
                Console.WriteLine(edge);
            }
        }
    }
}