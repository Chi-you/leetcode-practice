// design doubly linked list

#include <iostream>
using namespace std;

class MyLinkedList {
private:
    struct Node {
        int val;
        Node *next, *prev;
        Node(int val): val(val), next(NULL), prev(NULL){}
        Node(int val, Node *ptr): val(val), next(ptr), prev(NULL){}
        Node(int val, Node *ptrp, Node *ptrn): val(val), next(ptrn), prev(ptrp){}
    };
    int size;
    Node *head = new Node(0, NULL, NULL);
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
            head->prev = newhead;
            //newhead->prev = NULL;
            head = newhead;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *current = head;
        Node *newtail = new Node(val);
        while(current -> next != NULL){
            current = current -> next;
        }
        current->next = newtail;
        newtail->prev = current;
        size++;
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
            // we must link four pointer 
            newnode -> next = current -> next;
            current -> next = newnode;
            newnode -> prev = current;
            if(newnode->next) //newnode->next != NULL
                newnode -> next ->prev = newnode;
        }
        size++;
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node *current = head;
        //Node *pre = current;
        if(index >= size) return;
        else if(index == 0){
            head = current -> next;
            delete current;
        }
        else {
            for(int i = 0; i < index; i++){
                //pre = current;
                current = current->next;
            }
            Node *del = current;
            //pre-> next = current -> next;
            if(del->prev)
                del->prev->next = current->next;
            if(del->next)
                del->next->prev = current->prev;
            delete del;
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
