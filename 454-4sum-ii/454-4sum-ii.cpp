class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int tu = 0;
        unordered_map<int,int> mp;
        for(int a : nums1){
            for(int b : nums2){
                mp[a+b]++;
            }
        }
        for(int a : nums3){
            for(int b : nums4){
                if(mp.find(-a-b)!=mp.end())
                    tu += mp[-a-b];
            }
        }
        
        return tu;
    }
};