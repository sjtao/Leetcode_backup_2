class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        stack<int> st;
        int n = nums.size();
        int s = nums[0];
        int i = 0;
        while(s <= nums[n-1] && st.size() < k){
            if(s == nums[i])
                i++;
            else
                st.push(s);
            s++;
        }
        
        int ans;
        if(st.size() == k) ans = st.top();
        if(st.size() < k)  ans = s + k - st.size()-1;
        
        return ans;
        
    }
};