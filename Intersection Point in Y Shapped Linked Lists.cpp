/*
There are two singly linked lists of size N and M in a system. But, due to some programming error the
end node of one of the linked list got linked into one of the node of second list, forming a inverted
Y shaped list. Write a program to get the point where two linked lists intersect each other.
*/
int intersectPoint(Node* head1, Node* head2){
    int n, m, d;
    Node *temp = nullptr, *p = nullptr, *q = nullptr;

    n = 0;
    m = 0;
    temp = head1;
    while(temp){
        n++;
        temp = temp->next;
    }
    temp = head2;
    while(temp){
        m++;
        temp = temp->next;
    }
    if(n < m)
        swap(head1, head2);
    d = abs(n - m);
    p = head1;
    q = head2;
    while(d--)
        p = p->next;
    while(p && q){
        p = p->next;
        q = q->next;
        if(p == q)
            return p->data;
    }
    return -1;
}

