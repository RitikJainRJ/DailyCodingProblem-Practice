Node *copyList(Node *head) {
    Node *p = nullptr, *c = nullptr, *q = nullptr;

    c = head;
    while(c){
        q = c->next;
        c->next = new Node(c->data);
        c->next->next = q;
        c = c->next->next;
    }
    c = head;
    while(c){
        if(c->arb)
            c->next->arb = c->arb->next;
        c = c->next->next;
    }
    c = head;
    p = c->next;
    q = c->next;
    while(c){
        c->next = c->next->next;
        if(q->next)
            q->next = q->next->next;
        c = c->next;
        q = q->next;
    }
    return p;
}
