#include <iostream>

using namespace std;


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
    cout << "QUEUE\n";
    Queue q(3);
    q.push(5);
    q.push(7);
    q.push(3);
    q.print();
    q.pop();
    q.print();
    q.push(2);
    q.print();

    return 0;
}