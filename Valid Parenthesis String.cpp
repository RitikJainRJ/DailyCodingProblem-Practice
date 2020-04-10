class Solution {
public:
    bool checkValidString(string str) {
        int low = 0, high = 0;

        for(int i = 0; i < str.length(); i++){
            char x = str[i];
            low += (x == '(') ? 1 : -1;
            high += (x != ')') ? 1 : -1;
            if(high < 0)
                break;
            low = max(low, 0);
        }
        return (low == 0);
    }
};
