int getNthFromLast(Node *head, int n)
{
    Node *temp1 = nullptr, *temp2 = nullptr;

    temp1 = head;
    while(n--){
        if(temp1 == nullptr)
            return -1;
        temp1 = temp1->next;
    }
    temp2 = head;
    while(temp1 != nullptr){
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    return temp2->data;
}
