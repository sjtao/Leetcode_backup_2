class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int one = 0;
        vector<int> count(32,0);
        for(int& num : nums){
            int i = 0;
            while(num > 0){
                count[i] += (num & 1);
                num >>= 1;
                i++;
            }
        }
        
        for(int& i : count){
            one += (n-i)*i;
        }
        
        return one;
    }
};