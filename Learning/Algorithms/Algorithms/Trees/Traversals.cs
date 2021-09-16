using System;
using System.Collections.Generic;

namespace DataStructures.Tree {
    public class Traversals {
        public static void PreOdrer(Tree tree){
            PreOrder( tree.Root );

            void PreOrder(Tree.Node node) {
                if (node == null) {
                    return;
                }
                Console.Write(node.Name + " ");
                PreOrder(node.Left);
                PreOrder(node.Right);
            }
        }

        public static void InOrder(Tree tree) {
            InOrder( tree.Root );

            void InOrder(Tree.Node node) {
                if (node == null) {
                    return;
                }
                InOrder(node.Left);
                Console.Write(node.Name + " ");
                InOrder(node.Right);
            }
        }

        public static void PostOrder(Tree tree) {
            PostOrder( tree.Root );

            void PostOrder(Tree.Node node) {
                if (node == null) {
                    return;
                }
                PostOrder(node.Left);
                PostOrder(node.Right);
                Console.Write(node.Name + " ");
            }
        }

        public static void LevelOrder(Tree tree) {
            LevelOrder( tree.Root );

            void LevelOrder(Tree.Node node) {
                if (node == null) {
                    return;
                }

                var queue = new Queue<Tree.Node>();
                queue.Enqueue(node);
                while (queue.Count > 0) {
                    Tree.Node current = queue.Dequeue();
                    
                    Console.Write(current.Name + " ");

                    if (current.Left != null) {
                        queue.Enqueue(current.Left);
                    }
                    if (current.Right != null) {
                        queue.Enqueue(current.Right);
                    }
                }
            }
        }
    }
}