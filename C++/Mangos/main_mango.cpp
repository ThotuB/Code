#include <time.h>

#include <iostream>

using namespace std;

#define SIZE 1000000  // NR OF TRIALS

struct pick {
    char fruit;
    int bag;
};

pick trial[SIZE];
float mango = 0, banana = 0;
float bag1 = 0, bag2 = 0;
float mango_bag1 = 0, mango_bag2 = 0, banana_bag1 = 0, banana_bag2 = 0;

void print_trials() {
    for (unsigned i = 0; i < SIZE; i++) {
        cout << i + 1 << ":\tbag " << trial[i].bag << " - ";
        if (trial[i].fruit == 'm') {
            cout << "mango\n";
        } else {
            cout << "banana\n";
        }
    }
}

void value_to_probability() {
    mango *= ((float)100 / SIZE);
    banana *= ((float)100 / SIZE);

    bag1 *= ((float)100 / SIZE);
    bag2 *= ((float)100 / SIZE);

    mango_bag1 *= ((float)100 / SIZE);
    mango_bag2 *= ((float)100 / SIZE);
    banana_bag1 *= ((float)100 / SIZE);
    banana_bag2 *= ((float)100 / SIZE);
}

void calc_probs() {
    for (unsigned i = 0; i < SIZE; i++) {
        if (trial[i].bag == 1 && trial[i].fruit == 'm') {
            mango_bag1++;
            mango++;
            bag1++;
        } else if (trial[i].bag == 1 && trial[i].fruit == 'b') {
            banana_bag1++;
            banana++;
            bag1++;
        } else if (trial[i].bag == 2 && trial[i].fruit == 'm') {
            mango_bag2++;
            mango++;
            bag2++;
        } else {
            banana_bag2++;
            banana++;
            bag2++;
        }
    }
}

void print_probs() {
    cout << "Mango: " << mango << "%\n";
    cout << "Banana: " << banana << "%\n";
    cout << '\n';
    cout << "Bag 1: " << bag1 << "%\n";
    cout << "Bag 2: " << bag2 << "%\n";
    cout << '\n';
    cout << "Mango Bag 1: " << mango_bag1 << "%\n";
    cout << "Mango Bag 2: " << mango_bag2 << "%\n";
    cout << "Banana Bag 1: " << banana_bag1 << "%\n";
    cout << "Banana Bag 2: " << banana_bag2 << "%\n";
}

int main() {
    srand(time(NULL));
    int randBag, randFruit;

    for (unsigned i = 0; i < SIZE; i++) {
        randBag = rand() % 100 + 1;
        randFruit = rand() % 100 + 1;

        if (randBag <= 60) {
            trial[i].bag = 1;
            if (randFruit <= 60) {
                trial[i].fruit = 'm';
            } else {
                trial[i].fruit = 'b';
            }
        } else {
            trial[i].bag = 2;
            if (randFruit <= 50) {
                trial[i].fruit = 'm';
            } else {
                trial[i].fruit = 'b';
            }
        }
    }

    //print_trials();
    calc_probs();
    value_to_probability();
    print_probs();
}
