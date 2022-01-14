class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> nm(n);

        for(int i = 0; i < n; i++)
            nm[i] = to_string(nums[i]);
        
        sort(nm.begin(), nm.end(), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        if (nm[0] == "0") return "0";
        
        string t = "";
        for(int i = 0; i< n; i++)
            t += nm[i];
        
        return t;
    }
};