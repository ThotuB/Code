using System;
using System.Collections.Generic;

using PriorityQueue;

namespace Algorithms.PathFinding {
    public class AStar {
        public static List<Node> FindPath(Grid grid, Node start, Node goal) {
            var open = new PriorityQueue<Node>();

            open.Enqueue(start);
            while ( open.Size > 0 ) {
                Console.WriteLine(grid);
                Node current = open.Dequeue();
                current.Walkable = false;

                if ( current == goal ) { // goal found
                    return goal.Path();
                }

                foreach ( Node neighbor in grid.Neighbors(current) ) { // for each neighbor of current node
                    if ( !neighbor.Walkable ) {
                        continue;
                    }

                    int gCost = Node.Distance(current, neighbor); // distance from start to current
                    int hCost = Node.Distance(neighbor, goal); // distance from current to goal
                    int fCost = gCost + hCost; // g cost + h cost

                    if ( neighbor.FCost > fCost || neighbor.FCost == int.MaxValue ) { // if neighbor is not in open or has a lower f cost
                        neighbor.Update(current, fCost); // update neighbor's f cost and parent

                        if ( !open.Contains(neighbor) ) {
                            open.Enqueue(neighbor);
                        }
                    }
                }
            }
            return null;
        }
    }
}