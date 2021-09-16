using System;
using System.Collections.Generic;

namespace Algorithms.Sorting
{
    public class BucketSort : SortAlg<int>
    {
        public BucketSort() : base("Bucket Sort") { }

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
            Sort(array, 4, GetMSB(GetMax(array)));

            void Sort(int[] array, int mask, int msb) {
                int buckets = 1 << mask;
                List<int>[] bucket = new List<int>[buckets];

                for (int i = 0; i < array.Length; i++){
                    int bucketNr = GetBits(array[i], msb - mask, mask);

                    if (bucket[bucketNr] == null){
                        bucket[bucketNr] = new List<int>();
                    }

                    Insert(bucket[bucketNr], array[i]);
                }

                int index = 0;
                for (int i = 0; i < buckets; i++){
                    if (bucket[i] != null){
                        foreach (int nr in bucket[i]){
                            array[index++] = nr;
                        }
                    }
                }

                void Insert(List<int> list, int nr){
                    if (list.Count == 0){
                        list.Add(nr);
                        return;
                    }

                    int index = 0;
                    for ( ; index < list.Count; index++){
                        if (list[index] > nr){
                            break;
                        }
                    }
                    list.Insert(index, nr);
                }
            }
        }
    }
}