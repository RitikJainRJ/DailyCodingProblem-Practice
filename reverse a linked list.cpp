Node* reverseList(Node *head){
    Node *p = nullptr, *q = head->next;

    if(head->next == nullptr)
        return head;
    while(q){
        q = head->next;
        head->next = p;
        p = head;
        head = q;
    }
    return p;
}
