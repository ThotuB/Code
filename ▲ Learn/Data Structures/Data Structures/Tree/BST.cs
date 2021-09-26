using System;
using System.Collections.Generic;

namespace DataStructures.Tree {
    public class BST<T> where T : IComparable<T>, IComparable {
        public int Size { get; private set; }
        private Node _root;

        private class Node {
            public T Data { get; set; }
            public Node Left { get; set; }
            public Node Right { get; set; }

            public Node(T data) {
                Data = data;
            }

            public override string ToString() {
                return Data.ToString();
            }
        }

        public BST(){}

        public void Add(T data) {
            if ( IsEmpty() ) {
                _root = new Node(data);
                Size++;
                return;
            }

            Add(data, _root);
            Size++;

            void Add(T data, Node node) {
                if (data.CompareTo(node.Data) < 0) {
                    if (node.Left == null) {
                        node.Left = new Node(data);
                    }
                    else {
                        Add(data, node.Left);
                    }
                }
                else {
                    if (node.Right == null) {
                        node.Right = new Node(data);
                    }
                    else {
                        Add(data, node.Right);
                    }
                }
            }
        }

        // IsEmpty
        public bool IsEmpty() {
            return Size == 0;
        }

        // Search
        public bool Contains(T data) {
            return Contains(data, _root);

            bool Contains(T data, Node node) {
                if (node == null) {
                    return false;
                }
                switch ( data.CompareTo(node.Data) ) {
                    case -1:
                        return Contains(data, node.Left);
                    case 0:
                        return true;
                    case 1:
                        return Contains(data, node.Right);
                    default:
                        throw new System.Exception("???");
                }
            }
        }

        // Traversals
        public string PreOdrer(){
            return PreOrder( _root );

            string PreOrder(Node node) {
                if (node == null) {
                    return "";
                }
                return node.Data.ToString() + " " + PreOrder(node.Left) + PreOrder(node.Right);
            }
        }

        public string InOrder() {
            return InOrder(_root);

            string InOrder(Node node) {
                if (node == null) {
                    return "";
                }
                return InOrder(node.Left) + node.Data.ToString() + " " + InOrder(node.Right);
            }
        }

        public string PostOrder() {
            return PostOrder(_root);

            string PostOrder(Node node) {
                if (node == null) {
                    return "";
                }
                return PostOrder(node.Left) + PostOrder(node.Right) + node.Data.ToString() + " ";
            }
        }

        public string LevelOrder() {
            return LevelOrder(_root);

            string LevelOrder(Node node) {
                if (node == null) {
                    return "";
                }

                string result = "";
                Queue<Node> queue = new Queue<Node>();
                queue.Enqueue(node);
                while (queue.Count > 0) {
                    Node current = queue.Dequeue();
                    result += current.Data.ToString() + " ";
                    if (current.Left != null) {
                        queue.Enqueue(current.Left);
                    }
                    if (current.Right != null) {
                        queue.Enqueue(current.Right);
                    }
                }
                return result;
            }
        }

        // ToString
        public override string ToString() {
            return LevelOrder();
        }

    }
}