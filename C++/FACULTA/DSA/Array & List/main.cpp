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

        PassList():
            head(NULL),
            tail(NULL)
        {}

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

        Bus(string name, unsigned weight):
            name(name), 
            weight(weight)
        {}

        Bus(string name, unsigned weight, PassList passengers):
            name(name), 
            weight(weight), 
            passengers(passengers)
        {}

        void print(){
            cout << "Name: " << name << "\n";
            cout << "Weight: " << weight << "\n";
        }
};

class Company { // Bus ARRAY
    public:
        bool isFull(){
            return ( size == SIZE_MAX );
        }

        bool isEmpty(){
            return ( size == 0 );
        }

    public:
        Bus *fleet;
        size_t size;
        const size_t MAX_SIZE;

        // CONSTRUCTOR
        Company(const size_t max_size):
            fleet(new Bus[max_size]),
            size(0),
            MAX_SIZE(max_size)
        {}

        // ADDING BUSSES
        void push_back(Bus newBus){
            if ( isFull() ){
                cerr << "ERROR: ARRAY FULL";
                exit(0);
            }
            fleet[size] = newBus;
            size++;
        }

        void insert_bus(Bus newBus){
            if ( isFull() ){
                cerr << "ERROR: ARRAY FULL";
                exit(0);
            }
            size_t index;
            for ( index = size ; index > 0 ; index--){
                if ( fleet[index-1].weight > newBus.weight ){
                    break;
                }
                fleet[index] = fleet[index-1];
            }
            fleet[index] = newBus;
            size++;
        }

        // PRINT
        void print(){
            for (size_t index = 0 ; index < size ; index++){
                fleet[index].print();
                cout << "\n";
            }
        }
};

int main(){
    Company c(5);

    c.insert_bus(Bus("pipi", 12));
    c.insert_bus(Bus("pupu", 18));
    c.insert_bus(Bus("hatz", 33));
    c.insert_bus(Bus("gion", 55));
    c.insert_bus(Bus("mema", 1));

    c.print();

    return 0;
}