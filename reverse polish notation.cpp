int evalRPN(vector<string>& tokens) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<string> s;

    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
            int a = stoi(s.top());
            s.pop();
            int b = stoi(s.top());
            s.pop();
            int c;
            if(tokens[i] == "+")
                c = b + a;
            else if(tokens[i] == "-")
                c = b - a;
            else if(tokens[i] == "*")
                c = b * a;
            else if(tokens[i] == "/")
                c = b / a;
            s.push(to_string(c));
        }
        else{
            s.push(tokens[i]);
        }
    }
    return stoi(s.top());
}
