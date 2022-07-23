class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        st.push(asteroids[0]);
        for(int i = 1; i < n; i++){
            if(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                int a = asteroids[i];
                while(!st.empty() && st.top() > 0 && a < 0){
                    int t = st.top();
                    st.pop();
                    if(abs(t) > abs(a))
                        a = t;
                    else if(abs(t) == abs(a)){
                        a = 0;
                        break;
                    }
                }
                if(a != 0)
                    st.push(a);
            }
            else
                st.push(asteroids[i]); //never meet
        }
        
        if(st.empty()) return {};
        
        int s = st.size();
        vector<int> ans(s);
        s--;
        while(!st.empty()){
            ans[s--] = st.top();
            st.pop();
        }
        
        return ans;
    }
};