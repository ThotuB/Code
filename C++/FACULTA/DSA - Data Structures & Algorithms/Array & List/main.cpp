#include <iostream>
#include <string>

using namespace std;

void Tab(unsigned nr){
    while ( nr != 0 ){
        cout << "\t";
        nr--;
    }
}

/// ~~~~~~~~~~~~~~~~~~~~~~~~~ PASSENGER ~~~~~~~~~~~~~~~~~~~~~~~~~

class PassNode { 
    public:
        PassNode *next;
        string name;
        unsigned age;

        PassNode():
            next(NULL)
        {}

        PassNode(string name, unsigned age):
            next(NULL),
            name(name),
            age(age)
        {}

        PassNode(string name, unsigned age, PassNode *next):
            next(next),
            name(name),
            age(age)
        {}

        // MODIFY
        void modify(){
            cout << "New Name: "; cin >> name;
            cout << "New Age: "; cin >> age;
        }

        // PRINT
        void print(bool details, unsigned tab){
            cout << "\n"; Tab(tab); cout << "PASSNODE\n";
            Tab(tab); cout << "Name: " << name << "\n";
            Tab(tab); cout << "Age: " << age << "\n";
            if ( details ) { 
                Tab(tab); cout << " * This: " << this << "\n";
                Tab(tab); cout << " * Next: " << next << "\n";
            }
        }
};

/// ~~~~~~~~~~~~~~~~~~~~~~~~~ BUS ~~~~~~~~~~~~~~~~~~~~~~~~~

class Bus {
    private:
        bool isEmpty(){
            return ( size == 0 );
        }

    public:
        PassNode *passHead;
        string name;
        unsigned weight;
        size_t size;

        // CONSTRUCTORS
        Bus():
            passHead(NULL)
        {}

        Bus(string name, unsigned weight):
            passHead(NULL),
            name(name), 
            weight(weight),
            size(0)
        {}

        ~Bus(){
            clear();
        }

        // MODIFY
        void modify(){
            cout << "New Name: "; cin >> name;
            cout << "New Weight: "; cin >> weight;
        }

        // ADD PASS
        void insert_pass(string name, unsigned age){
            cout << "INSERTING PASS: " << name << "\n";
            if ( isEmpty() ){
                passHead = new PassNode(name, age);
            }
            else {
                PassNode *prev, *curr = passHead;
                for ( ; curr != NULL ; curr = curr->next){
                    if ( curr->name.compare(name) > 0 ){
                        break;
                    }
                    prev = curr;
                }
                if ( curr == passHead ){
                    passHead = new PassNode(name, age, passHead);
                }
                else {
                    prev->next = new PassNode(name, age, curr);
                }
            }
            size++;
        }

        // SEARCH PASS
        PassNode* search_pass(size_t index){
            // ERROR
            if ( index >= size ){
                cout << "SEARCH ERROR: PASS NOT FOUND\n";
                return NULL;
            }

            // WORKING
            PassNode *curr = passHead;
            for (size_t i = 0 ; i < index ; i++){
                curr = curr->next;
            }

            return curr;
        }

        PassNode* search_pass(string name){
            // SEARCH
            PassNode *curr = passHead;
            for ( ; curr != NULL ; curr = curr->next){
                if ( curr->name.compare(name) == 0 ){
                    break;
                }
            }

            // ERROR
            if ( curr == NULL ){
                cout << "SEARCH ERROR: PASS NOT FOUND\n";
                return NULL;
            }

            // WORKING
            return curr;
        }

        // DELETE PASS
        void delete_pass(size_t index){
            // ERROR
            if ( index >= size ){
                cout << "DELETE ERROR: PASS NOT FOUND\n";
                return;
            }

            // WORKING
            if ( index == 0 ){
                PassNode *temp = passHead;
                passHead = passHead->next;

                cout << "DELETING PASS: " << temp->name << "\n";
                delete temp;
            }
            else {
                PassNode *prev, *curr = passHead;
                for (size_t i = 0 ; i < index ; i++){
                    prev = curr;
                    curr = curr->next;
                }
                prev->next = curr->next;

                cout << "DELETING PASS: " << curr->name << "\n";
                delete curr;
            }
            size--;
        }

        void delete_pass(string name){
            // SEARCH
            PassNode *prev, *curr = passHead;
            for ( ; curr != NULL ; curr = curr->next){
                if ( curr->name.compare(name) == 0 ){
                    break;
                }
                prev = curr;
            }

            // ERROR
            if ( curr == NULL ){
                cout << "DELETE ERROR: PASS NOT FOUND\n";
                return;
            }

            // WORKING
            if ( curr == passHead ){
                PassNode *temp = passHead;
                passHead = passHead->next;

                cout << "DELETING PASS: " << temp->name << "\n";
                delete temp;
            }
            else {
                prev->next = curr->next;

                cout << "DELETING PASS: " << curr->name << "\n";
                delete curr; 
            }
            size--;
        }

        // MODIFY PASS
        void modify_pass(size_t index){
            // ERROR
            if ( !search_pass(index) ){
                cout << "MODIFY ERROR: PASS NOT FOUND\n";
            }
            
            // WORKING
            cout << "MODIFYING PASS AT: " << index << "\n";
            PassNode passenger;
            passenger.modify();
            delete_pass(index);
            insert_pass(passenger.name, passenger.age);
        }

        void modify_pass(string name){
            if ( !search_pass(name) ){
                cout << "MODIFY ERROR: PASS NOT FOUND\n";
                return;
            }

            // WORKING
            cout << "MODIFYING PASS: " << name << "\n";
            PassNode passenger;
            passenger.modify();
            delete_pass(name);
            insert_pass(passenger.name, passenger.age);
        }

        // CLEAR
        void clear(){
            PassNode *temp;

            while ( passHead != NULL ){
                temp = passHead;
                passHead = passHead->next;
                delete temp;
            }
        }

        // PRINT
        void print(bool details, unsigned tab){
            cout << "\n"; Tab(tab); cout << "BUS\n";
            Tab(tab); cout << "Name: " << name << "\n";
            Tab(tab); cout << "Weight: " << weight << "\n";
            Tab(tab); cout << "Size: " << size << "\n";
            Tab(tab); cout << "Passengers:";
            if ( isEmpty() ){
                cout << " - EMPTY -\n";
            }
            else {
                for ( PassNode *curr = passHead ; curr != NULL ; curr = curr->next){
                    curr->print(details, tab+1);
                }
            }
        }
};

/// ~~~~~~~~~~~~~~~~~~~~~~~~~ COMPANY ~~~~~~~~~~~~~~~~~~~~~~~~~

class Company {
    private:
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

        ~Company(){
            delete [] fleet;
        }

        // GETTER
        Bus& get(size_t index){
            // ERROR
            if ( index >= size ){
                cerr << "ERROR: INVALID INDEX\n";
                exit(0);
            }

            // WORKING
            return fleet[index];
        }

        Bus& get(string name){
            // SEARCH
            size_t index = 0;
            for ( ; index < size ; index++){
                if ( fleet[index].name.compare(name) == 0 ){
                    break;
                }
            }

            // ERROR
            if ( index == size ){
                cout << "ERROR: BUS NOT FOUND\n";
                exit(0);
            }

            // WORKING
            return fleet[index];
        }

        // ADD BUS
        void insert_bus(string name, unsigned weight){
            // ERROR
            if ( isFull() ){
                cerr << "ERROR: ARRAY FULL\n";
                exit(0);
            }

            // WORKING
            cout << "INSERTING BUS: " << name << "\n";
            size_t index;
            for ( index = size ; index > 0 ; index--){
                if ( fleet[index-1].weight > weight ){
                    break;
                }
                fleet[index] = fleet[index-1];
            }
            fleet[index] = Bus(name, weight);
            size++;
        }

        // SEARCH BUS
        size_t search_bus(string name){
            for (size_t index = 0 ; index < size ; index++){
                if ( fleet[index].name.compare(name) == 0 ){
                    return index;
                }
            }
            cout << "BUS NOT FOUND\n";
            return MAX_SIZE;
        }

        // DELETE BUS
        void delete_bus(size_t index){
            // ERROR
            if ( index >= MAX_SIZE ){
                cout << "DELETE STOPPED: BUS NOT FOUND\n";
                return;
            }

            // WORKING
            cout << "DELETING BUS AT: " << index << "\n";

            for ( ; index < size - 1 ; index++){
                fleet[index] = fleet[index+1];
            }
            size--;
        }

        void delete_bus(string name){
            delete_bus(search_bus(name));
        }

        // MODIFY BUS
        void modify_bus(size_t index){
            // ERROR
            if ( index >= MAX_SIZE ){
                cout << "MODIFY ERROR: BUS NOT FOUND\n";
                return;
            }

            // WORKING
            cout << "MODIFYING BUS AT: " << index << "\n";

            Bus newBus = fleet[index];
            delete_bus(index);
            newBus.modify();
            insert_bus(newBus.name, newBus.weight);
        }

        void modify_bus(string name){
            modify_bus(search_bus(name));
        }

        // INSERT PASS TO BUS
        void add_pass_to_bus(string name, unsigned age, size_t busIndex){
            // ERROR
            if ( busIndex >= MAX_SIZE ){
                cout << "MOVE ERROR: BUS NOT FOUND\n";
                return;
            }
            
            // WORKING
            fleet[busIndex].insert_pass(name, age);
        }
        
        void add_pass_to_bus(string name, unsigned age, string bus){
            add_pass_to_bus(name, age, search_bus(bus));
        }

        // MOVE PASS FROM BUS TO BUS
        void move_pass(size_t passIndex, size_t busFromIndex, size_t busToIndex){
            // ERROR 1
            if ( busFromIndex >= MAX_SIZE || busToIndex >= MAX_SIZE ){
                cout << "MOVE ERROR: BUS NOT FOUND\n";
                return;
            }
            PassNode *passenger = fleet[busFromIndex].search_pass(passIndex);

            // ERROR 2
            if ( !passenger ){
                cout << "MOVE ERROR: PASS NOT FOUND\n";
                return;
            }

            // WORKING
            fleet[busToIndex].insert_pass(passenger->name, passenger->age);
            fleet[busFromIndex].delete_pass(passIndex);
        }

        void move_pass(size_t passIndex, string busFrom, string busTo){
            move_pass(passIndex, search_bus(busFrom), search_bus(busTo));
        }

        void move_pass(string pass, size_t busFromIndex, size_t busToIndex){
            // ERROR 1
            if ( busFromIndex >= MAX_SIZE || busToIndex >= MAX_SIZE ){
                cout << "MOVE ERROR: BUS NOT FOUND\n";
                return;
            }
            PassNode *passenger = fleet[busFromIndex].search_pass(pass);
            
            // ERROR 2
            if ( !passenger ){
                cout << "MOVE ERROR: PASS NOT FOUND\n";
                return;
            }

            // WORKING
            fleet[busToIndex].insert_pass(passenger->name, passenger->age);
            fleet[busFromIndex].delete_pass(pass);
        }

        void move_pass(string pass, string busFrom, string busTo){
            move_pass(pass, search_bus(busFrom), search_bus(busTo));
        }

        // PRINT
        void print(bool details, unsigned tab){
            Tab(tab); cout << "\nCOMPANY\n";
            Tab(tab); cout << "SIZE: " << size << "/" << MAX_SIZE << "\n";
            Tab(tab); cout << " * Fleet: " << fleet << "\n";
            Tab(tab); cout << "Busses:";
            for (size_t index = 0 ; index < size ; index++){
                fleet[index].print(details,tab+1);
            }
            cout << "\n";
        }
};

int main(){
    Company c(5);
    c.insert_bus("BUS B1", 55);
    c.insert_bus("BUS B2", 79);
    c.insert_bus("BUS B3", 21);
 
    // adding to BUS B1
    c.add_pass_to_bus("gion", 23, 1);
    c.add_pass_to_bus("alex", 12, "BUS B1");
    c.add_pass_to_bus("xion", 3, "BUS B1");
    c.add_pass_to_bus("bob", 565, "BUS B1");

    // adding to BUS B2
    c.add_pass_to_bus("sos usturoi", 0, "BUS B2");
    c.add_pass_to_bus("mustar", 12, 0);
    c.add_pass_to_bus("ketchup", 56, "BUS B2");

    c.print(true, 0);

    // moving passangers
    c.move_pass(0, 0, 2);
    c.move_pass(1, "BUS B2", "BUS B3");
    c.move_pass("bob", 1, 0);
    c.move_pass("gion", "BUS B1", "BUS B2");

    c.print(true, 0);
    
    // deleting bus
    c.delete_bus("BUS B3");

    c.print(true, 0);
    
    // adding pass at index
    c.get("BUS B1").insert_pass("alt bob", 33);
    c.get(0).insert_pass("nu stiu", 12);

    c.print(true, 0);

    // deleting pass at index
    c.get(0).delete_pass("nu stiu");

    c.print(true, 0);

    return 0;
}