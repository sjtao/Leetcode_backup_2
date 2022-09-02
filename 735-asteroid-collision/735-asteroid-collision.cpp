class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int a : asteroids){
            if(st.empty()) //first or same direction
                st.push(a);
            else{
                while(!st.empty()){
                    if(a * st.top() > 0 || (a > 0 && st.top() < 0)){
                        st.push(a);
                        break;
                    }
                    else if(a < 0 && st.top() > 0){
                        if (a == -1 * st.top()){
                            st.pop();
                            break;
                        }
                        if(abs(a) > abs(st.top())){
                            st.pop();
                            if(st.empty()){
                                st.push(a);
                                break;
                            }
                        }
                        else
                            break;
                    }
                }   
            }
        }
        
        if(st.empty())
            return {};
        
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};