using System;
using System.Collections.Generic;

namespace PriorityQueue {
    public class PriorityQueue<T> where T : IComparable<T> {
        public int Size { get; private set; }
        public int Capacity { get; private set; }
        private List<T> _heap;

        public PriorityQueue() {
            _heap = new List<T>(16);
            Capacity = 16;
        }

        /// Size
        public bool IsEmpty() {
            return Size == 0;
        }

        /// Swap
        public void Swap(int i, int j) {
            (_heap[i], _heap[j]) = (_heap[j], _heap[i]);
        }

        /// Add
        public void Enqueue(T data) {
            if ( Size == Capacity ) {
                Capacity *= 2;
            }

            _heap.Add(data);
            HeapifyUp();
            Size++;

            void HeapifyUp() {
                int i = Size;
                while (i > 0) {
                    int parent = (i - 1) / 2;
                    if (_heap[parent].CompareTo(_heap[i]) > 0) {
                        Swap(i, parent);
                        i = parent;
                        continue;
                    }
                    break;
                }
            }
        }

        /// Pop
        public T Dequeue() {
            if ( IsEmpty() ) throw new System.Exception("PrioQueue is empty");

            T data = _heap[0];
            _heap[0] = _heap[Size - 1];
            _heap.RemoveAt(Size - 1);
            Size--;

            HeapifyDown();

            return data;

            void HeapifyDown() {
                int i = 0;
                while (i * 2 + 1 < Size) {
                    int childL = i * 2 + 1;
                    int childR = i * 2 + 2;
                    int smallest = i;
                    if (childL < Size && _heap[childL].CompareTo(_heap[smallest]) < 0) {
                        smallest = childL;
                    }
                    if (childR < Size && _heap[childR].CompareTo(_heap[smallest]) < 0) {
                        smallest = childR;
                    }

                    if (smallest != i) {
                        Swap(i, smallest);
                        i = smallest;
                        continue;
                    }
                    break;
                }
            }
        }

        /// Peek
        public T Peek() {
            if ( IsEmpty() ) throw new System.Exception("PrioQueue is empty");

            return _heap[0];
        }

        /// Contains
        public bool Contains(T data) {
            return _heap.Contains(data);
        }

        // ToString
        public override string ToString() {
            string output = "";
            foreach (T data in _heap) {
                output += data + " ";
            }
            return output;
        }
    }
}