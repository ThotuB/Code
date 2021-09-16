using System;
using System.Collections.Generic;

namespace Algorithms.Sorting {
    public class SelectionSort<T> : SortAlg<T>
            where T : IComparable<T>
    {
        public SelectionSort() : base("Selection Sort") { }

        public override void Sort(T[] array) {
            for (int i = 0; i < array.Length - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < array.Length; j++) {
                    if (Compare(array[j], array[minIndex]) < 0) {
                        minIndex = j;
                    }
                }
                Swap(array, i, minIndex);
            }
        }
    }
}