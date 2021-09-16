using System;

namespace Algorithms.Sorting
{
    public class ExchangeRadixSort : SortAlg<int>
    {
        public ExchangeRadixSort() : base("Exchange Radix Sort") { }

        private static bool GetBit(int nr, int bitNr){
            return (nr & (1 << bitNr)) != 0;
        }

        private static int GetMax(int[] array){
            int max = array[0];
            for (int i = 1; i < array.Length; i++)
            {
                if (array[i] > max)
                {
                    max = array[i];
                }
            }

            return max;
        }

        private static int GetMSB(int nr){
            int msb = 0;
            while (nr > 0){
                nr = nr >> 1;
                msb++;
            }
            
            return msb;
        }

        public override void Sort(int[] array){
            Sort(array, 0, array.Length - 1, GetMSB(GetMax(array)));

            void Sort(int[] array, int left, int right, int bit) {
                if ( bit < 0 || left >= right ) return;

                int i = left, j = right;
                while (i <= j) {
                    while (i <= j && !GetBit(array[i], bit)) i++;
                    while (i <= j && GetBit(array[j], bit)) j--;
                    
                    if (i <= j) {
                        Swap(array, i, j);
                        i++;
                        j--;
                    }
                }

                Sort(array, left, j, bit - 1);
                Sort(array, i, right, bit - 1); 
            }
        }
    }
}