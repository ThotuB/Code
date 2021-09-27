using System;
using System.Collections.Generic;

// Sort Algorithm Interface
public interface ISortAlg<T> 
        where T : IComparable<T>
{
    void Sort(T[] array);
}

public abstract class SortAlg<T>
        where T : IComparable<T>
{
    protected static void Swap(T[] arr, int i, int j) {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Sort Algorithms
public enum Algorithm {
    BubbleSort,
    SelectionSort
}

public class BubbleSort<T> : SortAlg<T>, ISortAlg<T>
    where T : IComparable<T>
{
    public void Sort(T[] array){
        for (int i = 0; i < array.Length; i++){
            for (int j = i + 1; j < array.Length - 1; j++){
                if (array[i].CompareTo(array[j]) > 0){
                    SortAlg<T>.Swap(array, i, j);
                }
            }
        }
    }
}

public class SelectionSort<T> : SortAlg<T>, ISortAlg<T>
    where T : IComparable<T>
{
    public void Sort(T[] array){
        for (int i = 0; i < array.Length - 1; i++){
            int min = i;
            for (int j = i + 1; j < array.Length; j++){
                if (array[j].CompareTo(array[min]) < 0){
                    min = j;
                }
            }
            SortAlg<T>.Swap(array, i, min);
        }
    }
}

// Sort Algorithm Factory
public class SortBuilder<T> 
        where T : IComparable<T>
{
    private Algorithm _algorithm;
    private ISortAlg<T> _sortAlg;
    private T[] _array;

    public SortBuilder(){
        _algorithm = Algorithm.BubbleSort;
        _sortAlg = new BubbleSort<T>();
    }

    public SortBuilder<T> SetAlgorithm(Algorithm alg){
        _algorithm = alg;
        switch (alg){
            case Algorithm.BubbleSort:
                _sortAlg = new BubbleSort<T>();
                break;
            case Algorithm.SelectionSort:
                _sortAlg = new SelectionSort<T>();
                break;
        }
        return this;
    }

    public SortBuilder<T> SetArray(T[] array){
        _array = array;
        return this;
    }

    public void Sort(){
        _sortAlg.Sort(_array);
    }
}


// Main
public class Program
{
    public static void PrintArr(int[] arr){
        foreach (int i in arr){
            Console.Write(i + " ");
        }
        Console.WriteLine();
    }

    public static void Main(string[] args)
    {
        var arr = new int[]{2, 9, 1, 5, 3, 7, 4, 6, 8, 10};
        PrintArr(arr);
        new SortBuilder<int>()
            .SetAlgorithm(Algorithm.BubbleSort)
            .SetArray(arr)
            .Sort();
        PrintArr(arr);
    }
}

Program.Main(null);