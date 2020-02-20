Node* sortedMerge(Node*, Node*);

Node* mergeKLists(Node *arr[], int N){
    int i, j, last = N - 1;

    while(last != 0){
        i = 0;
        j = last;
        while(1){
            arr[i] = sortedMerge(arr[i], arr[j]);
            i++;
            j--;
            if(i >= j){
                last = j;
                break;
            }
        }
    }
    return arr[0];
}

Node* sortedMerge(Node *a, Node *b){
    if(a == nullptr)
        return b;
    if(b == nullptr)
        return a;

    if(a->data < b->data){
        a->next = sortedMerge(a->next, b);
        return a;
    }
    else{
        b->next = sortedMerge(a, b->next);
        return b;
    }
}

////////////////////////////////////////////////
struct comp{
    bool operator()(Node *a, Node *b){
        return a->data > b->data;
    }
};

Node* mergeKLists(Node *arr[], int n){
    priority_queue<Node*, vector<Node*>, comp> pq;
    Node *head = nullptr, *last = nullptr;

    for(int i = 0; i < n; i++)
        pq.push(arr[i]);
    while(!pq.empty()){
        Node *temp = pq.top();
        pq.pop();
        if(head == nullptr){
            head = temp;
            last = temp;
        }
        else{
            last->next = temp;
            last = temp;
        }
        if(temp->next)
            pq.push(temp->next);
    }
    return head;
}


