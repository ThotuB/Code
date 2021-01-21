#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <math.h>
#include <vector>

#define PRNT 1

using namespace std;

template <class classT>
class Array {
private:
    classT *data;
    size_t _size;

public:
    Array(size_t size):
        data(new classT[size]),
        _size(size)
    {}

    Array(size_t size, ifstream &stream):
        data(new classT[size]),
        _size(size)
    {
        for (size_t i = 0 ; i < size ; i++){
            stream >> data[i];
        }
    }

    Array(size_t size, bool random_worst):
        data(new int[size]),
        _size(size)
    {
        if ( random_worst ){
            srand(time(NULL));

            for (size_t i = 0 ; i < size ; i++){
                data[i] = rand() % size + 1;
            }
        }
        else{
            for (size_t i = 0 ; i < size ; i++){
                data[i] = size - i;
            }
        } 
    }

    classT& operator[](size_t index) { 
        if (index >= _size) { 
            cerr << "ERROR: INDEX >= SIZE"; 
            exit(0); 
        } 
        return data[index]; 
    } 

    size_t size(){
        return _size;
    }

    void print(){
        if (!PRNT) return;
        for (size_t i = 0 ; i < _size ; i++){
            cout << data[i] << " ";
        }
        cout << "\n";
    }

    void print(size_t left, size_t right){
        if (!PRNT) return;
        for (size_t i = 0 ; i < left ; i++){
            for (size_t j = 1 ; j <= data[i] ; j *= 10){
                cout << " ";
            }
            cout << " ";
        }
        for (size_t i = left ; i <= right ; i++){
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};

class SortAlg {
protected:
    static unsigned swaps;
    static unsigned comparisons;
    static unsigned steps;

    static int compare(int a, int b){
        comparisons++;
        return a - b;
    }

    static void swap(int &a, int &b){
        int aux = a;
        a = b;
        b = aux;
        swaps++;
    }

    static void reset(){
        swaps = 0;
        comparisons = 0;
        steps = 0;
    }

    static void print_bucket(Array< vector <int> > bucket){
        for (size_t index = 0 ; index < bucket.size() ; index++){
            cout << "Bucket " << index << ": ";
            for (size_t i = 0 ; i < bucket[index].size() ; i++){
                cout << bucket[index][i] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    static void print(){
        if ( PRNT ) cout << "\n"; 
        cout << "Swaps: " << swaps << "\n";
        cout << "Comparisons: " << comparisons << "\n\n";
    }

public:
    static void sort(Array<int> Arr);
};

unsigned SortAlg::swaps = 0;
unsigned SortAlg::comparisons = 0;
unsigned SortAlg::steps = 0;

class BubbleSort1 : public SortAlg {
private:
    static string name;
public:
    static void sort(Array<int> Arr){
        reset();
        cout << name << "\n";
        Arr.print();
        algorithm(Arr);
        print();
    }

    static void algorithm(Array<int> Arr){
        bool flag;

        do{
            flag = false;
            for (unsigned i = 0 ; i < Arr.size() - 1 ; i++){
                if ( compare(Arr[i], Arr[i+1]) > 0 ){
                    swap(Arr[i], Arr[i+1]);
                    flag = true;
                }
            }
            Arr.print();
        }while(flag);
    }
};
string BubbleSort1::name = "BUBBLE SORT 1";

class BubbleSort2 : public SortAlg {
private:
    static string name;
public:
    static void sort(Array<int> Arr){
        reset();
        cout << name << "\n";
        Arr.print();
        algorithm(Arr);
        print();
    }

    static void algorithm(Array<int> Arr){
        size_t stopIndex = Arr.size() - 1;

        while ( stopIndex ){
            for (unsigned i = 0 ; i < stopIndex ; i++){
                if ( compare(Arr[i], Arr[i+1]) > 0 ){
                    swap(Arr[i], Arr[i+1]);
                }
            }
            Arr.print();
            stopIndex--;
        }
    }
};
string BubbleSort2::name = "BUBBLE SORT 2";

class CocktailShakerSort : public SortAlg {
private:
    static string name;
public:
    static void sort(Array<int> Arr){
        reset();
        cout << name << "\n";
        Arr.print();
        algorithm(Arr);
        print();
    }

    static void algorithm(Array<int> Arr){
        size_t left = 0;
        size_t right = Arr.size() - 1;

        while ( left < right ){
            for (unsigned i = left ; i < right ; i++){
                if ( compare(Arr[i], Arr[i+1]) > 0 ){
                    swap(Arr[i], Arr[i+1]);
                }
            }
            right--;

            for (unsigned i = right ; i > left ; i--){
                if ( compare(Arr[i-1], Arr[i]) ){
                    swap(Arr[i-1], Arr[i]);
                }
            }
            left++;
            Arr.print();
        }
    }
};
string CocktailShakerSort::name = "COCKTAIL SHAKER SORT";

class InsterionSort : public SortAlg {
private:
    static string name;
public:
    static void sort(Array<int> Arr){
        reset();
        cout << name << "\n";
        Arr.print();
        algorithm(Arr);
        print();
    }

    static void algorithm(Array<int> Arr){
        size_t i;
        for (size_t index = 1 ; index < Arr.size() ; index++){
            int temp = Arr[index];
            for (i = index ; i > 0 ; i--){
                if ( compare(Arr[i-1], temp) <= 0 ){
                    break;
                }
                swap(Arr[i], Arr[i-1]);
            }
            Arr.print();
        }
    }
};
string InsterionSort::name = "INSERTION SORT";

class SelectionSort : public SortAlg {
private:
    static string name;
public:
    static void sort(Array<int> Arr){
        reset();
        cout << name << "\n";
        Arr.print();
        algorithm(Arr);
        print();
    }

    static void algorithm(Array<int> Arr){
        int min;
        size_t mindex;
        for (size_t index = 0 ; index < Arr.size() - 1 ; index++){
            min = Arr[index];
            mindex = index;

            for (size_t i = index + 1 ; i < Arr.size() ; i++){
                if ( compare(min, Arr[i]) > 0 ){
                    min = Arr[i];
                    mindex = i;
                }
            }
            swap(Arr[index], Arr[mindex]);
            Arr.print();
        }
    }
};
string SelectionSort::name = "SELECTION SORT";

class ShellSort : public SortAlg {
private:
    static string name;
public:
    static void sort(Array<int> Arr){
        reset();
        cout << name << "\n";
        Arr.print();
        algorithm(Arr);
        print();
    }

    static void algorithm(Array<int> Arr){
        static unsigned stepArr[] = {7, 4, 3, 2, 1};

        for (size_t stepIndex = 0 ; stepIndex < 5 ; stepIndex++){
            unsigned step = stepArr[stepIndex];
            size_t i;
            for (size_t index = step ; index < Arr.size() ; index++){
                int temp = Arr[index];
                for (i = index ; i >= step && i < Arr.size() ; i -= step){
                    if ( compare(Arr[i-step], temp) <= 0 ){
                        break;
                    }
                    swap(Arr[i], Arr[i-step]);
                }
            }
            cout << "Step " << step << ": "; Arr.print();
        }
    }
};
string ShellSort::name = "SHELL SORT";

class QuickSort : public SortAlg {
private:
    static string name;
public:
    static void sort(Array<int> Arr){
        reset();
        cout << name << "\n";
        Arr.print();
        algorithm(Arr, 0, Arr.size()-1);
        print();
    }

    static void algorithm(Array<int> Arr, size_t left, size_t right){
        size_t index = left;
        int pivot = Arr[right];

        for (size_t i = left ; i < right ; i++){
            if ( compare(pivot, Arr[i]) > 0 ){
                swap(Arr[i], Arr[index]);
                index++;
            }
        }
        swap(Arr[index], Arr[right]);

        Arr.print(left, right);
        Arr.print();

        if (index > left+1) algorithm(Arr, left, index - 1);
        if (index < right-1) algorithm(Arr, index + 1, right);
    }
};
string QuickSort::name = "QUICK SORT";

class DirectRadixSort : public SortAlg {
private:
    static string name;

    static unsigned get_bits(unsigned nr, int bitNr, unsigned nrOfBits){
        return (nr >> bitNr) & (~(~0 << nrOfBits));
    }
public:
    static void sort(Array<int> Arr){
        reset();
        cout << name << "\n";
        Arr.print();
        algorithm(Arr, 2);
        print();
    }

    static void algorithm(Array<int> Arr, size_t mask){
        int bits = (int)ceil(log2(Arr.size()));
        const size_t radixArrSize = pow(2, mask);
        Array < vector <int> > radixArr(radixArrSize);

        size_t passMax = ceil((float)bits/mask);
        for (unsigned pass = 0 ; pass < passMax ; pass++){
            for (unsigned i = 0 ; i < Arr.size() ; i++){
                size_t index = get_bits(Arr[i], pass*mask, mask);
                radixArr[index].push_back(Arr[i]);
            }
            print_bucket(radixArr);

            unsigned k = 0;
            for (size_t index = 0 ; index < radixArrSize ; index++){
                for (int elem : radixArr[index]){
                    Arr[k] = elem;
                    k++;
                }
                radixArr[index].clear();
            }
            Arr.print();
        }
    }
};
string DirectRadixSort::name = "DIRECT RADIX SORT";

class ExchangeRadixSort : public SortAlg {
private:
    static string name;

    static unsigned get_bit(unsigned nr, int bitNr){
        return (nr & (1<<bitNr)) ? 1 : 0;
    }
public:
    static void sort(Array<int> Arr){
        reset();
        cout << name << "\n";
        Arr.print();
        algorithm(Arr, 0, Arr.size()-1, 3 );
        print();
    }

    static void algorithm(Array<int> Arr, size_t left, size_t right, int bit){
        int i = left;
        int j = right;

        if ( left < right && bit >= 0 ){
            do {
                for ( ; i <= j ; i++ ) {
                    if ( compare(get_bit(Arr[i], bit), 1) == 0 ){
                        break;
                    }
                }
                for ( ; i <= j ; j-- ) {
                    if ( compare(get_bit(Arr[j], bit), 0) == 0 ){
                        break;
                    }
                }

                if ( i < j ) swap(Arr[i], Arr[j]);
            }while (i <= j);

            Arr.print(left, right);
            Arr.print();

            if ( j > 0 )            algorithm(Arr, left, j, bit-1);
            if ( i < Arr.size() )   algorithm(Arr, i, right, bit-1);
        }
    }
};
string ExchangeRadixSort::name = "EXCHANGE RADIX SORT";

class BinSort : public SortAlg {
private:
    static string name;

    static unsigned get_bit(unsigned nr, int bitNr){
        return (nr & (1<<bitNr)) ? 1 : 0;
    }
public:
    static void sort(Array<int> Arr){
        reset();
        cout << name << "\n";
        Arr.print();
        algorithm(Arr);
        print();
    }

    static void algorithm(Array<int> Arr){
        unsigned i = 0;

        while ( i < Arr.size() ){
            if ( compare(Arr[i], i+1) == 0 ){
                i++;
            }
            else{
                swap(Arr[i], Arr[Arr[i]-1]);
                Arr.print();
            }
        }
    }
};
string BinSort::name = "BIN SORT";

class BucketSort : public SortAlg {
private:
    static string name;

    static unsigned get_digit(unsigned nr, int digitNr){
        for (size_t i = 0 ; i < digitNr ; i++){
            nr /= 10;
        }
        return nr%10;
    }
public:
    static void sort(Array<int> Arr){
        reset();
        cout << name << "\n";
        Arr.print();
        algorithm(Arr);
        print();
    }

    static void algorithm(Array<int> Arr){
        unsigned digitMax = floor(log(Arr.size())/log(10));
        Array < vector <int> > bucketArr(10);

        for (size_t index = 0 ; index < Arr.size() ; index++){
            unsigned digit = get_digit(Arr[index], digitMax);
            size_t i = 0;
            for ( ; i < bucketArr[digit].size() ; i++ ){
                if ( compare(Arr[index], bucketArr[digit][i]) <= 0 ){
                    break;
                }
            }
            bucketArr[digit].insert(bucketArr[digit].begin() + i, Arr[index]);
        }
        print_bucket(bucketArr);

        size_t k = 0;
        for (unsigned digit = 0 ; digit < 10 ; digit++){
            for (size_t i = 0 ; i < bucketArr[digit].size() ; i++){
                swap(Arr[k], bucketArr[digit][i]);
                k++;
            }
            bucketArr[digit].clear();
        }
        Arr.print();
    }
};
string BucketSort::name = "BUCKET SORT";

int main(){
    ifstream file("arr.txt");
    unsigned size = 20;
    bool choice = false;

    // BubbleSort1::sort(Array<int>(size, choice));
    // BubbleSort2::sort(Array<int>(size, choice));
    // CocktailShakerSort::sort(Array<int>(size, choice));
    // InsterionSort::sort(Array<int>(size, choice));
    // SelectionSort::sort(Array<int>(size, choice));
    ShellSort::sort(Array<int>(size, choice));
    // QuickSort::sort(Array<int>(size, choice));
    // DirectRadixSort::sort(Array<int>(size, choice));
    // ExchangeRadixSort::sort(Array<int>(size, choice));
    //BinSort::sort(Array<int>(size, choice));
    // BucketSort::sort(Array<int>(size, choice));

    return 0;
}
