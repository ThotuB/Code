#include <iostream>
#include <exception>
#include <string>

using namespace std;

class PassNode { // Passenger
    public:
        string name;
        unsigned age;
        PassNode *next;

        PassNode(string name, unsigned age){
            this->name = name;
            this->age = age;
            next = NULL;
        }

        void print(){
            cout << "Name: " << name << "\n";
            cout << "Age: " << age << "\n";
        }

        void print_details(){
            print();
            cout << "This: " << this << "\n";
            cout << "Next: " << next << "\n";
        }
};

class PassList { // PassNode LIST
    private:
        bool isEmpty(){
            return ( size == 0 );
        }

    public:
        PassNode *head;
        PassNode *tail;
        size_t size = 0;

        PassList(){
            head = NULL;
            tail = NULL;
        }

        void push_back(PassNode newPassNode){
            if ( isEmpty() ){
                head = new PassNode(newPassNode);
                tail = head;
            }
            else {
                tail->next = new PassNode(newPassNode);
                tail = tail->next;
            }
            size++;
        }

        void push_front(PassNode newPassNode){
            if ( isEmpty() ){
                head = new PassNode(newPassNode);
                tail = head;
            }
            else {
                newPassNode.next = head;
                head = new PassNode(newPassNode);
            }
            size++;
        }

        void insert(PassNode newPassNode, size_t index){
            if ( index > size ){
                cerr << "INVALID INSERT INDEX";
                exit(0);
            }

            if ( index == size ){
                push_back(newPassNode);
            }
            else if ( index == 0 ){
                push_front(newPassNode);
            }
            else {
                PassNode *curr = head;
                for (size_t i = 1 ; i < index ; i++){
                    curr = curr->next;
                }

                newPassNode.next = curr->next;
                curr->next = new PassNode(newPassNode);
                size++;
            }
        }

        PassNode* pop_back(){
            if ( isEmpty() ){
                cerr << "LIST EMPTY";
                exit(0);
            }

            PassNode *curr = head;
            while ( curr->next != tail ){
                curr = curr->next;
            }
            PassNode *passenger = tail;
            tail = curr;
            tail->next = NULL;

            size--;

            return passenger;
        }

        void print(){
            for (PassNode *curr = head ; curr != NULL ; curr = curr->next){
                curr->print();
                cout << "\n";
            }
        }

        void print_details(){
            for (PassNode *curr = head ; curr != NULL ; curr = curr->next){
                curr->print_details();
                cout << "\n";
            }
        }
};

class Bus { // Bus
    public:
        string name;
        unsigned weight;
        PassList passengers;

        // CONSTRUCTORS
        Bus(){}

        Bus(string name, unsigned weight){
            this->name = name;
            this->weight = weight;
        }

        Bus(string name, unsigned weight, PassList passengers){
            this->name = name;
            this->weight = weight;
            this->passengers = passengers;
        }
};

class Company { // Bus ARRAY
    private:
        bool isFull(){
            return ( size == SIZE_MAX );
        }

        bool isEmpty(){
            return ( size == 0 );
        }

    public:
        Bus *fleet;
        size_t size = 0;
        size_t MAX_SIZE;

        Company(size_t size){
            fleet = new Bus[size];
            MAX_SIZE = size;
        }

        void push_back(Bus newBus){
            if ( isFull() ){
                cerr << "ERROR: ARRAY FULL";
                exit(0);
            }
            fleet[size] = newBus;
            size++;
        }

        void insert(Bus newBus){
            if ( isFull() ){
                cerr << "ERROR: ARRAY FULL";
                exit(0);
            }
            for (size_t index = size - 1 ; index > 0 ; index--){
                if ( fleet[index].weight > newBus.weight ){

                }
            }
        }
};

int main(){
    PassList myList;

    // myList.push_back(PassNode("Gion", 4));
    // myList.push_back(PassNode("Gion", 4));
    // myList.push_back(PassNode("Gion", 4));
    myList.insert(PassNode("Gion", 4), 0);
    myList.print_details();
    cout << "```````````````````````````\n";
    myList.insert(PassNode("Dan", 6), 1);
    myList.print_details();
    cout << "```````````````````````````\n";
    myList.insert(PassNode("Yoo", 16), 1);
    myList.print_details();
    cout << "```````````````````````````\n";
    myList.insert(PassNode("Pupu", 4), 2);
    myList.print_details();
    cout << "```````````````````````````\n";
    myList.insert(PassNode("Pipi", 12), 0);
    myList.print_details();
    cout << "```````````````````````````\n";
    myList.insert(PassNode("Hatz", 33), 2);
    myList.print_details();
    cout << "```````````````````````````";

    return 0;
}