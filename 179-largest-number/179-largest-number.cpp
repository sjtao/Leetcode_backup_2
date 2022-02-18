class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        int n = nums.size();
        vector<string> s;
        for(int a : nums)
            s.push_back(to_string(a));
        
        sort(s.begin(), s.end(), [](string &s1, string &s2){ return s1+s2>s2+s1; });

        for(string c : s){
            ans += c;
        }
        
        while(ans[0] == '0' && ans.length() > 1)
            ans.erase(0,1);
        
        return ans;
    }
};