using System;
using System.Collections.Generic;

namespace Data_Structures.Tree {
    public class AVL<T> where T : IComparable<T>, IComparable {
        public int Size { get; private set; }
        private Node _root;

        private class Node {
            public T Data { get; set; }

            public int Balance { get; set; }
            public int Height { get; set; }

            public Node Left { get; set;}
            public Node Right { get; set;}

            public Node(T data) {
                Data = data;
            }

            public void Update() {
                int heightLeft = ( Left == null ) ? -1 : Left.Height;
                int heightRight = ( Right == null ) ? -1 : Right.Height;

                Height = Math.Max(heightLeft, heightRight) + 1;
                Balance = heightRight - heightLeft;
            }

            public string ToString(Node root) {
                return Data + ":\n" 
                + ( root == this ? "Root\n" : "" )
                + (Left == null && Right == null ? "Leaf\n" :
                  (Left != null ? "Left: " + Left.Data + "\n" : "")
                + (Right != null ? "Right: " + Right.Data + "\n" : ""));
            }
        }

        public AVL() {}

        // IsEmpty
        public bool IsEmpty() {
            return Size == 0;
        }

        public int Height() {
            return _root.Height;
        }

        // Rotations
        private Node LeftRotation(Node A) {
            Node B = A.Right;
            A.Right = B.Left;
            B.Left = A;

            A.Update();
            B.Update();

            return B;
        }

        private Node RightRotation(Node A) {
            Node B = A.Left;
            A.Left = B.Right;
            B.Right = A;

            A.Update();
            B.Update();

            return B;
        }

        // Cases
        private Node LeftLeftCase(Node node) {
            return RightRotation(node);
        }

        private Node RightRightCase(Node node) {
            return LeftRotation(node);
        }

        private Node LeftRightCase(Node node) {
            node.Left = LeftRotation(node.Left);
            return RightRotation(node);
        }

        private Node RightLeftCase(Node node) {
            node.Right = RightRotation(node.Right);
            return LeftRotation(node);
        }

        // Balance
        private Node Balance(Node node) {
            if ( node.Balance == -2 ) {
                if ( node.Left.Balance <= 0 ) {
                    Console.WriteLine("LL");
                    return LeftLeftCase(node);
                } else {
                    Console.WriteLine("LR");
                    return LeftRightCase(node);
                }
            } else if ( node.Balance == 2 ) {
                if ( node.Right.Balance >= 0 ) {
                    Console.WriteLine("RR");
                    return RightRightCase(node);
                } else {
                    Console.WriteLine("RL");
                    return RightLeftCase(node);
                }
            }

            return node;
        }

        // Insert
        public void Add(T data) {
            _root = Add(data, _root);
            Size++;

            Node Add(T data, Node node) {
                if ( node == null ) {
                    return new Node(data);
                }

                if ( data.CompareTo(node.Data) < 0 ) {
                    node.Left = Add(data, node.Left);
                } else {
                    node.Right = Add(data, node.Right);
                }

                node.Update();

                return Balance(node);
            }
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
                return node.ToString(_root) + " " + PreOrder(node.Left) + PreOrder(node.Right);
            }
        }

        public string InOrder() {
            return InOrder(_root);

            string InOrder(Node node) {
                if (node == null) {
                    return "";
                }
                return InOrder(node.Left) + node.ToString(_root) + " " + InOrder(node.Right);
            }
        }

        public string PostOrder() {
            return PostOrder(_root);

            string PostOrder(Node node) {
                if (node == null) {
                    return "";
                }
                return PostOrder(node.Left) + PostOrder(node.Right) + node.ToString(_root) + " ";
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
                    result += current.ToString(_root) + " ";
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
            return InOrder();
        }
    }
}