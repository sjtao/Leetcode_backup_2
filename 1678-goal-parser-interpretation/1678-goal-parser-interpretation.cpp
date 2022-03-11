class Solution {
public:
    string interpret(string command) {
        stack<char> st;
        int s = command.length();
        string a;
        for(int i = 0; i < s; i++){
            if(command[i] == '(')
                continue;
            else if(command[i] == ')'){
                if(command[i-1] == '('){        
                    a += 'o';
                }
            }
            else{
                a += command[i];
            }
        }
       return a;
    }
};