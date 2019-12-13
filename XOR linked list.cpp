/*
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field named both,
which is an XOR of the next node and the previous node. Implement an XOR linked list;
it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
*/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *npx;
};

node* createNode(int);
void insertNode(node**, int);
node* XOR(node*, node*);
void printlist(node*);

int main(void){
    node *head = nullptr;

    for(int i = 0;i < 5; i++)
        insertNode(&head, i);
    printlist(head);
    return 0;
}

node* createNode(int data){
    node *temp = nullptr;

    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->npx = nullptr;
    return temp;
}

node* XOR(node *a, node *b){
    return (node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void insertNode(node **head, int data){
    node *temp = createNode(data);

    temp->npx = XOR(nullptr, *head);
    if(*head != nullptr){
        node *next = XOR(nullptr, (*head)->npx);
        (*head)->npx = XOR(next, temp);
    }
    *head = temp;
}

void printlist(node *head){
    node *temp1 = nullptr, *temp2 = nullptr;

    if(head == nullptr){
        cout << "Empty" << endl;
        return;
    }
    while(1){
        cout << head->data << " ";
        temp2 = head;
        if(temp1 == head->npx)
            break;
        head = XOR(temp1, head->npx);
        temp1 = temp2;
    }
}
