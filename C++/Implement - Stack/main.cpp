#include <iostream>

using namespace std;

class Stack {
    private:
        size_t _size;
        const size_t MAX_SIZE;
        int *data;

    public:
        // CONSTRUCTOR
        Stack(const size_t max_size)
            : _size(0), MAX_SIZE(max_size), data(new int[max_size])
        {}

        // DESTRUCTOR
        ~Stack(){
            delete [] data;
        }

        // FULL & EMPTY
        bool full(){
            return ( _size == MAX_SIZE );
        }

        bool empty(){
            return ( _size == 0 );
        }

        // PUSH & POP
        void push(int nr){
            if ( full() ) {
                cerr << "Error: Stack Full\n";
                exit(0);
            }

            data[_size] = nr;
            _size++;
        }

        int pop(){
            if ( empty() ) {
                cerr << "ERROR: STACK EMPTY\n";
                exit(0);
            }

            _size--;
            return data[_size];
        }

        // SIZES
        size_t size(){
            return _size;
        }

        const size_t max_size(){
            return MAX_SIZE;
        }

        // PRINT
        void print(){
            cout << "Stack: ";
            for (size_t index = 0 ; index < _size ; index++){
                cout << data[index] << " ";
            }
            cout << "\n";
        }
};

int main(){
    cout << "STACK\n";
    Stack s(3);
    s.push(5);
    s.push(7);
    s.push(3);
    s.print();
    s.pop();
    s.print();
    s.push(2);
    s.print();

    return 0;
}
