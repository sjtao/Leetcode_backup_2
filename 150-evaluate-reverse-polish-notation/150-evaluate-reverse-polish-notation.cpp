class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a, b, c;
        for(int i = 0; i < tokens.size(); ++i){
            if(tokens[i] == "+"){
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                c = b + a;
                s.push(c);
            }
            else if(tokens[i] == "-"){
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                c = b - a;
                s.push(c);
            }
            else if(tokens[i] == "*"){
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                c = b * a;
                s.push(c);
            }
            else if(tokens[i] == "/"){
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                c = b / a;
                s.push(c);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};