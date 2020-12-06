#include <iostream>
#include <exception>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode(int val){
            this->val = val;
            next = NULL;
        }

        void print(){
            cout << val;
        }
};

class List {
    public:
        ListNode *head;
        ListNode *tail;
        int size;

        List(int val){
            head = new ListNode(val);
            tail = head;
            size = 1;
        }

        void push_back(int val){
            tail->next = new ListNode(val);
            tail = tail->next;

            size++;
        }

        int pop_back(){
            if ( size == 0 ){
                exit(0);
            }

            ListNode *curr = head;
            while ( curr->next != tail ){
                curr = curr->next;
            }
            int val = tail->val;
            delete tail;
            tail = curr;
            tail->next = NULL;

            size--;

            return val;
        }

        void print(){
            for (ListNode *curr = head ; curr != NULL ; curr = curr->next){
                curr->print();
                cout << " ";
            }
            cout << "\n";
        }
};

int main(){
    List myList(3);

    myList.push_back(4);
    myList.push_back(5);
    myList.pop_back();

    myList.print();

    return 0;
}