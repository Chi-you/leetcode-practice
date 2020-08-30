#include <iostream>
using namespace std;


class MyLinkedList {
private:
    struct Node {
        int val;
        Node *next;
        Node(int val): val(val), next(NULL){}
    };
    int size;
    Node *head;
    //Node *tail;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size || index < 0) // edge cases
            return -1;
        Node *current = head;
        for(int i = 0 ; i < index; i++){
            current = current->next;
        }
        return current->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *newhead = new Node(val);
        if(size == 0){
            head = newhead;
        }
        else{
            newhead->next = head;
            head = newhead;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *current = head;
        Node *newtail = new Node(val);
        //newtail->val = val;
        while(current -> next != NULL){
            current = current -> next;
        }
        current->next = newtail;
        size++;
        //tail = newtail;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node *current = head;
        Node *newnode = new Node(val);
        if(index > size) return;
        else if(index == 0) addAtHead(val);
        else{
            for(int i = 0; i < index-1; i++){
                current = current->next;
            }
            newnode -> next = current -> next;
            current -> next = newnode;
        }
        size++;
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node *current = head;
        Node *prev = current;
        if(index >= size) return;
        else if(index == 0){
            head = current -> next;
            delete current;
        }
        else {
            for(int i = 0; i < index; i++){
                prev = current;
                current = current->next;
            }
            Node *temp = current;
            prev-> next = current -> next;
            delete temp;
        }
        size--;
    }
    void printlinkedlist(){
        Node *current = head;
        while(current != NULL){
            cout<<current->val<<" ";
            current = current -> next;
        }
    }
};


 //Your MyLinkedList object will be instantiated and called as such:
int main(){ 
    // MyLinkedList* obj = new MyLinkedList();
    // obj->addAtHead(1);
    // obj->printlinkedlist();
    // obj->deleteAtIndex(0);
    // obj->printlinkedlist();
    /*["MyLinkedList","addAtIndex","addAtIndex","addAtIndex","get"]
[[],[0,10],[0,20],[1,30],[0]]
*/
    MyLinkedList *linkedList = new MyLinkedList(); // Initialize empty LinkedList
    linkedList->addAtIndex(0,10);  
    linkedList->printlinkedlist();
    cout<<endl;
    linkedList->addAtIndex(0,20);  
    linkedList->printlinkedlist();
    cout<<endl;
    linkedList->addAtIndex(1,30);  
    linkedList->printlinkedlist();
    cout<<endl;
    int a = linkedList->get(0);  
    cout<<a<<endl;
    // linkedList->deleteAtIndex(0);  
    // linkedList->printlinkedlist();
    // cout<<endl;
    // int b = linkedList->get(0);  
    // cout<<b<<endl;
    // linkedList->addAtHead(6);
    // linkedList->printlinkedlist();
    // cout<<endl;
    // linkedList->addAtHead(4);
    // linkedList->printlinkedlist();
    // cout<<endl;          // returns 2
    // linkedList->addAtIndex(5,0);  // linked list becomes 1->2->3
    // linkedList->printlinkedlist();
    // cout<<endl;
    // linkedList->addAtHead(6);
    // linkedList->printlinkedlist();
    // cout<<endl;

}
