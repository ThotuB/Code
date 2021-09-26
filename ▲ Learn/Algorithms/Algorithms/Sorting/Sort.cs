using System;
using System.Collections.Generic;

namespace Algorithms.Sorting {
    public abstract class SortAlg<T>
            where T : IComparable<T>
    {
        public string Name { get; protected set; }
        public uint Swaps { get; protected set; }
        public uint Compares { get; protected set; }

        public SortAlg(string name) {
            Name = name;
        }
        
        public void Swap(T[] arr, int i, int j){
            (arr[i], arr[j]) = (arr[j], arr[i]);
            Swaps++;
        }

        public int Compare(T a, T b){
            Compares++;
            return a.CompareTo(b);
        }

        public abstract void Sort(T[] array);

        // ToString
        public override string ToString(){
            return $"{Name}: \n\tSwaps: {Swaps}\n\tCompares: {Compares}";
        }
    }

    public enum Algorithm {
        BubbleSort,
        InsertionSort,
        SelectionSort,
        CocktailSort,
        MergeSort,
        QuickSort,
        HeapSort,
        CountingSort,
        DirectRadixSort,
        ExchangeRadixSort,
        BucketSort,
        ShellSort
    }

    public static class SortAlgfactory
    {
        public static SortAlg<T> Get<T>(Algorithm algorithm) where T : IComparable<T> {
            switch (algorithm) {
                case Algorithm.BubbleSort:
                    return new BubbleSort<T>();
                case Algorithm.InsertionSort:
                    return new InsertionSort<T>();
                case Algorithm.SelectionSort:
                    return new SelectionSort<T>();
                case Algorithm.CocktailSort:
                    return new CocktailSort<T>();
                case Algorithm.MergeSort:
                    return new MergeSort<T>();
                case Algorithm.QuickSort:
                    return new QuickSort<T>();
                case Algorithm.HeapSort:
                    return new HeapSort<T>();
                case Algorithm.ShellSort:
                    return new ShellSort<T>();
                default:
                    throw new Exception("???");
            }
        }

        public static SortAlg<int> Get(Algorithm algorithm) {
            switch (algorithm) {
                case Algorithm.CountingSort:
                    return new CountingSort();
                case Algorithm.DirectRadixSort:
                    return new DirectRadixSort();
                case Algorithm.ExchangeRadixSort:
                    return new ExchangeRadixSort();
                case Algorithm.BucketSort:
                    return new BucketSort();
                default:
                    throw new Exception("???");
            }
        }
    }
}