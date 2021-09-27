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
public static class SortFactory<T> 
        where T : IComparable<T>
{
    public static void Sort(Algorithm sortAlg, T[] array){
        ISortAlg<T> alg = null;
        switch(sortAlg){
            case Algorithm.BubbleSort:
                alg = new BubbleSort<T>();
                break;
            case Algorithm.SelectionSort:
                alg = new SelectionSort<T>();
                break;
            default:
                throw new ArgumentException("Invalid Sort Algorithm");
        }
        alg.Sort(array);
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
        SortFactory<int>.Sort(Algorithm.SelectionSort, arr);
        PrintArr(arr);
    }
}

Program.Main(null);