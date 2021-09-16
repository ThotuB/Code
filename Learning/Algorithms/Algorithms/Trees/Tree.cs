using System;
using System.Collections.Generic;

namespace DataStructures.Tree {
    public class Tree {
        public Node Root;

        public class Node {
            public char Name;
            public int Value;

            public Node Left;
            public Node Right;

            public Node(char name, int value) {
                Name = name;
                Value = value;
            }

            public override string ToString() {
                return $"{Name}";
            }
        }

        // Constructor
        public Tree(){}

        // IsEmpty
        public bool IsEmpty() {
            return Root == null;
        }

        public void Add(char name, int value) {
            if ( IsEmpty() ) {
                Root = new Node(name, value);
                return;
            }

            Add(new Node(name, value), Root);

            void Add(Node newNode, Node node) {
                if ( newNode.Value < node.Value ) {
                    if (node.Left == null) {
                        node.Left = newNode;
                    }
                    else {
                        Add(newNode, node.Left);
                    }
                }
                else {
                    if (node.Right == null) {
                        node.Right = newNode;
                    }
                    else {
                        Add(newNode, node.Right);
                    }
                }
            }
        }
    }
}