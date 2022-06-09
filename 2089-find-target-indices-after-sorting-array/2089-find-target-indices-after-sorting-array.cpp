class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        
        int eq = 0, le = 0;
        for(int a : nums){
            eq += a == target;
            le += a < target;
        }
        
        while(eq){
            ans.push_back(le++);
            eq--;
        }
        
        return ans;
    }
};