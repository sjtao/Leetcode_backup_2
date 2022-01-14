class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> nm(n);

        for(int i = 0; i < n; i++)
            nm[i] = to_string(nums[i]);
        
        sort(nm.begin(), nm.end(), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        
        string t = "";
        for(int i = 0; i< n; i++)
            t += nm[i];
        
        while(t[0] == '0' && t.length() > 1)
            t.erase(0,1);
        
        return t;
    }
};