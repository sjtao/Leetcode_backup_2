//TLE

class Solution {
public:
    int countSetBits(int n)
    {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    
    int totalHammingDistance(vector<int>& nums) {
        int Distance = 0;
        for(int i = 0; i < nums.size()-1; i++){
            for(int j = i+1; j < nums.size(); j++){
                Distance += countSetBits(nums[i] ^ nums[j]);
            }
        }
        return Distance;
    }
};

