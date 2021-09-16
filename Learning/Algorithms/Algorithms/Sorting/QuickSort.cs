using System;
using System.Collections.Generic;

namespace Algorithms.Sorting {
    public class QuickSort<T> : SortAlg<T>
            where T : IComparable<T>
    {
        public QuickSort() : base("Quick Sort") { }

        public override void Sort(T[] array) {
            Sort(array, 0, array.Length - 1);

            void Sort(T[] array, int left, int right) {
                if (left >= right) return;

                int pivot = right;
                int index = left;

                for (int i = left; i < right; i++) {
                    if (Compare(array[i], array[pivot]) < 0) {
                        Swap(array, i, index);
                        index++;
                    }
                }
                Swap(array, index, pivot);

                Sort(array, left, index - 1);
                Sort(array, index + 1, right);
            }
        }
    }
}