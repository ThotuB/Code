#include <iostream>

using namespace std;

template <size_t N>
class Queue {
    private:
        int data[N];
        unsigned size = 0;

        void reorder(){
            for (int index = 0 ; index < size ; index++){
                data[index] = data[index+1];
            }
        }

    public:
        bool full(){
            return ( size == N );
        }

        bool empty(){
            return ( size == 0 );
        }

        void push(int nr){
            if ( !full() ){
                cout << "Push -> " << nr << "\n";
                data[size] = nr;
                size++;
            }
            else {
                cerr << "Error: Queue Full\n";
            }
        }

        int pop(){
            if ( !empty() ){
                int nr = data[0];
                size--;
                reorder();
                cout << "Pop -> " << nr << "\n";
                return nr;
            }
            else {
                cerr << "Error: Queue Full\n";
            }
        }

        void print(){
            cout << "Queue: ";
            for (unsigned index = size ; index > 0 ; index--){
                cout << data[index-1] << " ";
            }
            cout << "\n";
        }
};

int main(){
    cout << "QUEUE\n";
    Queue<3> q;
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