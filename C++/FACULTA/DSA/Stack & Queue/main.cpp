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

            cout << "Push -> " << nr << "\n";
            data[_size] = nr;
            _size++;
        }

        int pop(){
            if ( empty() ) {
                cerr << "ERROR: STACK EMPTY\n";
                exit(0);
            }

            _size--;
            cout << "Pop -> " << data[_size] << "\n";
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

class Queue {
    private:
        size_t _size;
        const size_t MAX_SIZE;
        int *data;

        // REORDER after POP
        void reorder(){
            for (size_t index = 0 ; index < _size ; index++){
                data[index] = data[index+1];
            }
        }

    public:
        // CONSTRUCTOR
        Queue(const size_t max_size)
            : _size(0), MAX_SIZE(max_size), data(new int[max_size])
        {}

        // DESTRUCTOR
        ~Queue(){
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
                cerr << "ERROR: QUEUE FULL\n";
                exit(0);
            }
            
            cout << "Push -> " << nr << "\n";
            data[_size] = nr;
            _size++;
        }

        int pop(){
            if ( empty() ) {
                cerr << "ERROR: QUEUE EMPTY\n";
                exit(0);
            }

            int nr = data[0];
            _size--;
            reorder();
            cout << "Pop -> " << nr << "\n";
            
            return nr;
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
            cout << "Queue: ";
            for (size_t index = _size ; index > 0 ; index--){
                cout << data[index-1] << " ";
            }
            cout << "\n";
        }
};

int main(){
    cout << "STACK\n";
    Stack myStack(3);
    myStack.push(5);  // Size: 1/3
    myStack.push(7);  // Size: 2/3
    myStack.push(3);  // Size: 3/3
    myStack.print();
    myStack.pop();    // Size: 2/3
    myStack.print();
    myStack.push(2);  // Size: 3/3
    myStack.print();

    cout << "\nQUEUE\n";
    Queue myQueue(4);
    myQueue.push(5);  // Size: 1/4
    myQueue.push(7);  // Size: 2/4
    myQueue.push(3);  // Size: 3/4
    myQueue.print();
    myQueue.pop();    // Size: 2/4
    myQueue.print();
    myQueue.push(2);  // Size: 3/4
    myQueue.push(3);  // Size: 4/4
    myQueue.print();
    myQueue.push(3); // Queue should be full -> ERROR

    cout << "THIS SHOULD NOT BE PRINTED";

    return 0;
}
