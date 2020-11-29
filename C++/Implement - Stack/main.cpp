#include <iostream>

using namespace std;

template <size_t N>
class Stack {
    private:
        int data[N];
        unsigned size = 0;

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
                cerr << "Error: Stack Full\n";
            }
        }

        int pop(){
            if ( !empty() ){
                size--;
                cout << "Pop -> " << data[size] << "\n";
                return data[size];
            }
            else {
                cerr << "Error: Stack Empty\n";
            }
        }

        void print(){
            cout << "Stack: ";
            for (unsigned index = 0 ; index < size ; index++){
                cout << data[index] << " ";
            }
            cout << "\n";
        }
};

int main(){
    cout << "STACK\n";
    Stack<3> s;
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
