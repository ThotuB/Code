using System;
using System.Collections.Generic;

namespace Algorithms.Sorting {
    public class ShellSort<T> : SortAlg<T> 
            where T : IComparable<T>
    {
        public ShellSort() : base("Shell Sort") { }

        public override void Sort(T[] array){
            int[] gaps = { 701, 301, 132, 57, 23, 10, 4, 1 };

            foreach (int gap in gaps){
                for (int i = gap; i < array.Length; i++){
                    T temp = array[i];
                    int j = i;
                    for ( ; j >= gap && Compare(temp, array[j - gap]) < 0 ; j -= gap){
                        Swap(array, j, j - gap);
                    }
                    array[j] = temp;
                }
            }
        }
    }
}