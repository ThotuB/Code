using System;
using System.Collections.Generic;

namespace Algorithms.Sorting {
    public class CocktailSort<T> : SortAlg<T> 
            where T : IComparable<T>
    {
        public CocktailSort() : base("Cocktail Sort") { }

        public override void Sort(T[] array) {
            int right = array.Length - 1;
            int left = 0;
            while ( left < right ) {
                for ( int i = left; i < right; i++ ) {
                    if ( Compare(array[i], array[i + 1]) > 0 ) {
                        Swap(array, i, i + 1);
                    }
                }
                right--;
                for ( int i = right; i > left; i-- ) {
                    if ( Compare(array[i], array[i - 1]) < 0 ) {
                        Swap(array, i - 1, i);
                    }
                }
                left++;
            }
        }
    }
}