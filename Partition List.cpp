class Solution {
public:
    ListNode* partition(ListNode* head1, int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode *head2 = nullptr, *t1 = nullptr, *t2 = nullptr;

        if(head1 == nullptr || head1->next == nullptr)
            return head1;
        while(head1 && head1->val >= x){
            if(head2 == nullptr){
                head2 = head1;
                t2 = head2;
            }
            else{
                t2->next = head1;
                t2 = t2->next;
            }
            head1 = head1->next;
        }
        if(head1 == nullptr){
            t2->next = nullptr;
            return head2;
        }
        t1 = head1;
        while(t1->next){
            if(t1->next->val >= x){
                if(head2 == nullptr){
                    head2 = t1->next;
                    t2 = head2;
                }
                else{
                    t2->next = t1->next;
                    t2 = t2->next;
                }
                t1->next = t1->next->next;
            }
            else
                t1 = t1->next;
        }
        t1->next = head2;
        if(t2)
            t2->next = nullptr;
        return head1;
    }
};
