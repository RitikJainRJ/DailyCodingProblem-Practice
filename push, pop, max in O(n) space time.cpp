#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int n;
        vector<int> arr;
        int max_ele;
    public:
        Stack(int n){
            this->n = n;
            max_ele = 0;
        }

        void push(int x){
            if(arr.empty()){
                max_ele = x;
                arr.push_back(x);
                return;
            }
            if(max_ele >= x){
                arr.push_back(x);
            }
            else{
                arr.push_back(max_ele - x);
                max_ele = x;
            }
        }

        void pop(){
            if(arr.empty()){
                cout << "Empty" << endl;
                return;
            }
            if(arr.back() >= 0){
                cout << arr.back() << endl;
                arr.pop_back();
            }
            else{
                cout << max_ele << endl;
                max_ele = max_ele + arr.back();
                arr.pop_back();
            }
        }

        void getMax(){
            cout << max_ele << endl;
        }

        void peek(){
            if(arr.back() >= 0)
                cout << arr.back() << endl;
            else
                cout << max_ele << endl;
        }
};

int main(){
    Stack s(10);

    s.push(3);
    s.push(5);
    s.getMax();
    s.push(7);
    s.push(19);
    s.getMax();
    s.pop();
    s.getMax();
    s.pop();
    s.peek();
    return 0;
}
