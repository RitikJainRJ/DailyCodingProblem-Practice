Node* addTwoLists(Node* first, Node* second){
    Node *temp1 = first, *temp2 = second, *temp3 = nullptr;
    Node *res = nullptr;
    int c = 0;

    while(temp1 && temp2){
        int temp = temp1->data + temp2->data + c;
        c = temp / 10;
        temp = temp % 10;
        if(res == nullptr){
            res = new Node(temp);
            temp3 = res;
        }
        else{
            temp3->next = new Node(temp);
            temp3 = temp3->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while(temp1){
        int temp = temp1->data + c;
        c = temp / 10;
        temp = temp % 10;
        temp3->next = new Node(temp);
        temp3 = temp3->next;
        temp1 = temp1->next;
    }
    while(temp2){
        int temp = temp2->data + c;
        c = temp / 10;
        temp = temp % 10;
        temp3->next = new Node(temp);
        temp3 = temp3->next;
        temp2 = temp2->next;
    }
    while(c){
        int temp = c % 10;
        c = c / 10;
        temp3->next = new Node(temp);
        temp3 = temp3->next;
    }
    return res;
}
