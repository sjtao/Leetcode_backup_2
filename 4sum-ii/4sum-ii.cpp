class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> s;
        for(int a : nums1){
            for(int b : nums2)
                s[a+b]++;
        }
        int cnt = 0;
        for(int a : nums3){
            for(int b : nums4){
                int c = -(a+b);
                if(s.find(c) != s.end())
                    cnt += s[c];
            }
        }
        return cnt;        
    }
};