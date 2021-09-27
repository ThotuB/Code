using System;
using System.Collections.Generic;

namespace Algorithms.Sorting {
    public class InsertionSort<T> : SortAlg<T>
            where T : IComparable<T>
    {
        public InsertionSort() : base("Insertion Sort") { }

        public override void Sort(T[] array) {
            for (int i = 1; i < array.Length; i++) {
                T key = array[i];
                int j = i - 1;
                while (j >= 0 && Compare(array[j], key) > 0) {
                    Swap(array, j, j + 1);
                    j--;
                }
                array[j + 1] = key;
            }
        }
    }
}