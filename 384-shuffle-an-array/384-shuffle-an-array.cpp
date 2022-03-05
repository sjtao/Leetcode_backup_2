class Solution {
    vector<int> orig, vec;
    int n;
public:
    Solution(vector<int>& nums) {
        vec = nums;
        orig = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        vec = orig;
        return vec;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < n; ++i){
            int a = rand() % n;
            swap(vec[a], vec[i]);
        }
        return vec;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */