using System;
using System.Collections.Generic;

namespace Algorithms.Sorting {
    public class MergeSort<T> : SortAlg<T>
            where T : IComparable<T>
    {
        public MergeSort() : base("Merge Sort") { }
        
        public override void Sort(T[] array) {
            Sort(array, 0, array.Length - 1);

            void Merge(T[] array, int start, int mid, int end) {
                var left = new T[mid - start + 1];
                var right = new T[end - mid];

                Array.Copy(array, start, left, 0, left.Length);
                Array.Copy(array, mid + 1, right, 0, right.Length);

                int i = 0, j = 0, k = start;
                while (i < left.Length && j < right.Length) {
                    if (Compare(left[i], right[j]) < 0) {
                        array[k] = left[i];
                        i++;
                    } else {
                        array[k] = right[j];
                        j++;
                    }
                    k++;
                }

                while (i < left.Length) {
                    array[k] = left[i];
                    i++;
                    k++;
                }

                while (j < right.Length) {
                    array[k] = right[j];
                    j++;
                    k++;
                }
            }

            void Sort(T[] array, int start, int end) {
                if (start >= end) {
                    return;
                }

                int mid = (start + end) / 2;
                Sort(array, start, mid);
                Sort(array, mid + 1, end);
                Merge(array, start, mid, end);
            }
        }
    }
}