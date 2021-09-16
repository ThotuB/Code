using System;

namespace Algorithms.Sorting
{
    public class DirectRadixSort : SortAlg<int>
    {
        public DirectRadixSort() : base("Direct Radix Sort") { }

        private static int GetBits(int nr, int left, int size){
            return (nr >> left) & ~(~0 << size);
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
            Sort(array, 2, GetMSB(GetMax(array)));

            void Sort(int[] array, int mask, int msb) {
                int buckets = 1 << mask;

                int passMax = (int)Math.Ceiling((float)msb / mask);
                for (int pass = 0 ; pass < passMax ; pass++){
                    int[] counts = new int[buckets];
                    for (int i = 0; i < array.Length; i++){
                        int bucket = GetBits(array[i], pass * mask, mask);
                        counts[bucket]++;
                    }

                    for (int i = 1; i < buckets; i++){
                        counts[i] += counts[i - 1];
                    }

                    int[] temp = new int[array.Length];
                    for (int i = array.Length - 1; i >= 0; i--){
                        int bucket = GetBits(array[i], pass * mask, mask);
                        temp[counts[bucket] - 1] = array[i];
                        counts[bucket]--;
                    }

                    for (int i = 0; i < array.Length; i++){
                        array[i] = temp[i];
                    }
                }
            }
        }
    }
}