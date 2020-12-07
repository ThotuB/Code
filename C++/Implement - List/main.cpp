#include <iostream>
#include <exception>

using namespace std;

template <class class_t>
class ListNode {
    public:
        class_t data;
        ListNode *next;

        ListNode(int data):
            data(data),
            next(NULL)
        {}

        friend ostream& operator<<(ostream &out, const ListNode <class_t> &obj){
            out << obj.data;

            return out;
        }
};

template <class class_t>
class List {
    public:
        ListNode <class_t> *head;
        ListNode <class_t> *tail;
        int size;

        // CONSTRUCTOR
        List():
            head(NULL),
            tail(NULL),
            size(0)
        {}

        // EMPTY
        bool empty(){
            return ( size == 0 );
        }

        // PUSH
        void push_back(class_t data){
            if ( empty() ){
                head = new ListNode <class_t>(data);
                tail = head;
            }
            else {
                tail->next = new ListNode <class_t>(data);
                tail = tail->next;
            }
            size++;
        }

        void push_front(class_t data){
            if ( empty() ){
                head = new ListNode <class_t>(data);
                tail = head;
            }
            else {
                data.next = head;
                head = new ListNode <class_t>(data);
            }
            size++;
        }

        // POP
        class_t pop_back(){
            if ( empty() ){
                cerr << "LIST EMPTY";
                exit(0);
            }

            ListNode <class_t> *curr = head;
            while ( curr->next != tail ){
                curr = curr->next;
            }
            class_t data = tail->data;
            tail = curr;
            tail->next = NULL;

            size--;

            return data;
        }

        // COUT
        friend ostream& operator<<(ostream &out, const List <class_t> &obj){
            for (ListNode <class_t> *curr = obj.head ; curr != NULL ; curr = curr->next){
                out << *curr << "\n";
            }
            out << "\n";

            return out;
        }
};

int main(){
    List <unsigned> myList;

    myList.push_back(4);
    myList.push_back(5);
    myList.push_back(6);
    myList.pop_back();

    cout << myList;

    return 0;
}