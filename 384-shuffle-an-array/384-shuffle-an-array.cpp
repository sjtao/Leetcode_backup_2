class Solution {
public:
    vector<int> orig, shuf;
    int n;
    Solution(vector<int>& nums) {
        orig = nums;
        shuf = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        shuf = orig;
        return shuf;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < n; i++){
            int j = rand() % n;
            swap(shuf[i], shuf[j]); 
        }
        return shuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */