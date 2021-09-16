using System;
using System.IO;
using System.Collections.Generic;

using Algorithms.Sorting;
using Algorithms.PathFinding;
using PriorityQueue;
using Algorithms.Compression;
using Algorithms.StringMatching;

using Algorithms.Graphs;
using Algorithms.Graphs.ComponentFinding;

namespace Algorithms
{
    class Program
    {
        const string path = "./resources/graph.txt";

        public static void PrintList<T>(List<T> list){
            foreach(T item in list){
                Console.WriteLine(item);
            }
        }

        public static void Main(string[] args) {
            var graph = new Graph(path);
            Console.WriteLine(graph);
            BridgeEdges.Find(graph);
        }
    }
}
