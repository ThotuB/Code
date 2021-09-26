using System;
using System.Collections.Generic;

using PriorityQueue;

namespace Algorithms.Compression {
    public class Huffman {
        private Node _root;

        public class Node {
            public char Character;
            public int Frequency;
            public Node Left;
            public Node Right;

            public Node(char character, int frequency) {
                Character = character;
                Frequency = frequency;
            }

            public Node(char character, int frequency, Node left, Node right)
                : this(character, frequency) 
            {
                Left = left;
                Right = right;
            }

            public override string ToString() {
                return $"{Character} - {Frequency}";
            }
        }

        private static void BuildCodeDictionary(Node node, string code, Dictionary<char, string> codeDict) {
            if (node.Character != '*') {
                codeDict[node.Character] = code;
            }

            if (node.Left != null) {
                BuildCodeDictionary(node.Left, code + "0", codeDict);
            }
            if (node.Right != null) {
                BuildCodeDictionary(node.Right, code + "1", codeDict);
            }
        }

        private static void BuildCodeDictionary(Node node, string code, Dictionary<string, char> codeDict) {
            if (node.Character != '*') {
                codeDict[code] = node.Character;
            }

            if (node.Left != null) {
                BuildCodeDictionary(node.Left, code + "0", codeDict);
            }
            if (node.Right != null) {
                BuildCodeDictionary(node.Right, code + "1", codeDict);
            }
        }

        public string Compress(string input) {
            // Get frequency of each character
            var frequency = new Dictionary<char, int>();

            foreach (var c in input) {
                if (!frequency.ContainsKey(c)) {
                    frequency.Add(c, 0);
                }
                frequency[c]++;
            }

            // Build Huffman tree
            var q = new PriorityQueue<int, Node>();
            foreach (var kvp in frequency) {
                q.Enqueue(kvp.Value, new Node(kvp.Key, kvp.Value));
            }

            for (int i = 0; i < frequency.Count - 1; i++) {
                var left = q.Dequeue().Value;
                var right = q.Dequeue().Value;

                Node node = new Node('*', left.Frequency + right.Frequency, left, right);

                q.Enqueue(node.Frequency, node);
            }

            this._root = q.Dequeue().Value;
            
            // Build code dictionary
            var code = new Dictionary<char, string>();
            BuildCodeDictionary(this._root, "", code);

            // Compress input
            string output = "";
            foreach (var c in input) {
                output += code[c];
            }

            return output;
        }

        public string Decompress(string input) {
            var code = new Dictionary<string, char>();
            BuildCodeDictionary(this._root, "", code);

            string output = "";
            string current = "";
            foreach (var c in input) {
                current += c;
                if (code.ContainsKey(current)) {
                    output += code[current];
                    current = "";
                }
            }

            return output;
        }
    }
}