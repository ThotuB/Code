using System;

namespace Algorithms.Sorting {
    public class BubbleSort<T> : SortAlg<T> 
            where T : IComparable<T>
    {
        public BubbleSort() : base("Bubble Sort") { }

        public override void Sort(T[] array) {
            int right = array.Length;
            while (right > 0) {
                for (int i = 0; i < right - 1; i++) {
                    if (Compare(array[i], array[i + 1]) > 0) {
                        Swap(array, i, i + 1);
                    }
                }
                right--;
            }
        }
    }
}