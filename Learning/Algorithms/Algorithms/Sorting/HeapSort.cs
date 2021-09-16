using System;
using Algorithms;
using System.Collections.Generic;

namespace Algorithms.Sorting {
    public class HeapSort<T> : SortAlg<T> 
            where T : IComparable<T>
    {
        public HeapSort() : base("Heao Sort") { }

        public override void Sort(T[] array){
            T[] heap = new T[array.Length];

            for (int i = 0; i < array.Length; i++){
                heap[i] = array[i];
                HeapifyUp(heap, i);
            }
            for (int i = array.Length - 1; i > 0; i--){
                Swap(heap, 0, i);
                array[i] = heap[i];
                HeapifyDown(heap, 0, i);
            }
            array[0] = heap[0];

            // Helper functions
            void HeapifyUp(T[] heap, int i){
                if (i == 0) return;

                int parent = (i - 1) / 2;
                if ( Compare(heap[parent], heap[i]) < 0 ){
                    Swap(heap, parent, i);
                    HeapifyUp(heap, parent);
                }
            }

            void HeapifyDown(T[] heap, int i, int size){
                if (i >= size) return;

                int left = 2 * i + 1;   
                int right = 2 * i + 2;
                int largest = i;

                if (left < size && Compare(heap[left], heap[largest]) > 0){
                    largest = left;
                }
                if (right < size && Compare(heap[right], heap[largest]) > 0){
                    largest = right;
                }
                if (largest != i){
                    Swap(heap, i, largest);
                    HeapifyDown(heap, largest, size);
                }
            }
        }
    }
}