using System;
using System.Collections.Generic;

namespace Algorithms.Sorting {
    public class CountingSort : SortAlg<int>
    {
        public CountingSort() : base("Counting Sort") { }

        public override void Sort(int[] array){
            int max = 0;
            for (int i = 0; i < array.Length; i++) {
                if ( Compare(array[i], array[max]) > 0 ) {
                    max = i;
                }
            }
            int[] count = new int[array[max] + 1];
            for (int i = 0; i < array.Length; i++) {
                count[array[i]]++;
            }
            for (int i = 1; i < count.Length; i++) {
                count[i] += count[i - 1];
            }
            int[] result = new int[array.Length];
            for (int i = array.Length - 1; i >= 0; i--) {
                result[count[array[i]] - 1] = array[i];
                count[array[i]]--;
            }
            for (int i = 0; i < array.Length; i++) {
                array[i] = result[i];
            }
        }
    }
}