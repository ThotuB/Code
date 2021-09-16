using System;
using System.Collections.Generic;

namespace PriorityQueue {
    public class PriorityQueue<TKey, TValue>
            where TKey : IComparable<TKey> 
    {
        public int Size { get; private set; }
        public int Capacity { get; private set; }
        private List<TValue> _values;
        private List<TKey> _keys;

        public PriorityQueue() {
            _values = new List<TValue>(16);
            _keys = new List<TKey>(16);
            Capacity = 16;
        }

        /// Size
        public bool IsEmpty() {
            return Size == 0;
        }

        /// Swap
        public void Swap(int i, int j) {
            (_values[i], _values[j]) = (_values[j], _values[i]);
            (_keys[i], _keys[j]) = (_keys[j], _keys[i]);
        }

        /// Add
        private void Add(TKey key, TValue value) {
            if ( Size == Capacity ) {
                Capacity *= 2;
            }
            _values.Add(value);
            _keys.Add(key);
        }
        
        public void Enqueue(TKey key, TValue value) {
            this.Add(key, value);
            HeapifyUp();
            Size++;

            void HeapifyUp() {
                int i = Size;
                while (i > 0) {
                    int parent = (i - 1) / 2;
                    if ( _keys[parent].CompareTo(_keys[i]) > 0 ) {
                        Swap(i, parent);
                        i = parent;
                        continue;
                    }
                    break;
                }
            }
        }

        /// Pop
        public KeyValuePair<TKey, TValue> Dequeue() {
            if ( IsEmpty() ) throw new System.Exception("PrioQueue is empty");

            TValue val = _values[0];
            TKey key = _keys[0];
            _values[0] = _values[Size - 1];
            _keys[0] = _keys[Size - 1];
            _values.RemoveAt(Size - 1);
            _keys.RemoveAt(Size - 1);
            Size--;

            HeapifyDown();

            return new KeyValuePair<TKey, TValue>(key, val);

            void HeapifyDown() {
                int i = 0;
                while (i * 2 + 1 < Size) {
                    int childL = i * 2 + 1;
                    int childR = i * 2 + 2;
                    int smallest = i;

                    if (childL < Size && _keys[childL].CompareTo(_keys[smallest]) < 0) {
                        smallest = childL;
                    }
                    if (childR < Size && _keys[childR].CompareTo(_keys[smallest]) < 0) {
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
        public KeyValuePair<TKey, TValue> Peek() {
            if ( IsEmpty() ) throw new System.Exception("PrioQueue is empty");

            return new KeyValuePair<TKey, TValue>(_keys[0], _values[0]);
        }

        /// Contains
        public bool ContainsValue(TValue value) {
            return _values.Contains(value);
        }

        // ToString
        public override string ToString() {
            string output = "";
            for (int i = 0; i < Size; i++) {
                output += $"{_values[i]}, {_keys[i]}\n";
            }
            return output;
        }
    }
}