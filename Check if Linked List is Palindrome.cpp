bool _isPalindrome(Node**, Node*);

bool isPalindrome(Node *head){
    return _isPalindrome(&head, head);
}

bool _isPalindrome(Node **head_ref, Node *head){
    bool res = true;

    if(head->next != nullptr)
        res = _isPalindrome(head_ref, head->next);
    if(res == true && (*head_ref)->data == head->data){
        (*head_ref) = (*head_ref)->next;
        return true;
    }
    return false;
}
