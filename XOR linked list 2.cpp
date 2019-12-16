/*
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the
next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the
element to the end or start, and a get(index) which returns the node at index.
*/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *npx;
};

node* XOR(node*, node*);
void insertLast(node**, int);
void insertFirst(node**, int);
void printList(node*);
void getIndex(node*, int);

int main(void){
    node* head = nullptr;

    for(int i = 0; i < 5; i++)
        insertLast(&head, i);
    for(int i = 5;i < 10; i++)
        insertFirst(&head, i);
    getIndex(head, 2);
    printList(head);
    return 0;
}

node* XOR(node *a, node *b){
    return (node*)(uintptr_t(a) ^ uintptr_t(b));
}

void insertFirst(node **head, int data){
    node *t = nullptr;

    t = (node*)malloc(sizeof(node));
    t->data = data;
    t->npx = nullptr;

    if(*head == nullptr)
        *head = t;
    else{
        node *next = nullptr;

        next = XOR(nullptr, (*head)->npx);
        t->npx = XOR(nullptr, *head);
        (*head)->npx = XOR(t, next);
        *head = t;
    }
}

void insertLast(node **head, int data){
    node* t = nullptr;

    t = (node*)malloc(sizeof(node));
    t->data = data;
    t->npx = nullptr;
    if(*head == nullptr){
        *head = t;
    }
    else{
        node *prev = nullptr, *next = nullptr, *curr = *head;

        while(1){
            next = XOR(prev, curr->npx);
            if(next == nullptr)
                break;
            prev = curr;
            curr = next;
        }
        t->npx = XOR(nullptr, curr);
        curr->npx = XOR(prev, t);
    }
}

void getIndex(node *head, int index){
    node *prev = nullptr, *next = nullptr, *curr = head;

    while(index--){
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    cout << curr->data << endl;
}

void printList(node *head){
    if(head == nullptr){
        cout << "Empty" << endl;
    }
    else{
        node *curr = head, *prev = nullptr, *next = nullptr;

        while(1){
            cout << curr->data << " ";
            next = XOR(curr->npx, prev);
            if(!next)
                break;
            prev = curr;
            curr = next;
        }
        cout << endl;
    }
}
