class Solution {
public:
    vector<int> copy1, copy2;
    int n;
    void swap(vector<int>& v, int a, int b){
        int t = v[a];
        v[a] = v[b];
        v[b] = t;
        return;
    }
    
    Solution(vector<int>& nums) {
        copy1 = nums;
        copy2 = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        copy1 = copy2;
        return copy1;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < n; i++)
            swap(copy1, i, (i + rand() % n) % n);
        return copy1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */