/*
You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure
to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.

You should be as efficient with time and space as possible.
*/
#include<bits/stdc++.h>
using namespace std;

class circularBuffer{
    private:
        deque<int> dq;
        int n;
    public:
        circularBuffer(int n){
            this->n = n;
        }

        void record(int order_id){
            if(dq.size() < n)
                dq.push_back(order_id);
            else{
                dq.pop_front();
                dq.push_back(order_id);
            }
        }

        int get_last(int i){
            return dq[n - i];
        }
};

int main(void){
    circularBuffer cb(5);
    for(int i = 0; i < 10; i++)
        cb.record(i);
    cout << cb.get_last(5);
    return 0;
}
