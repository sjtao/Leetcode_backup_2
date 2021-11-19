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

//Runtime: 60 ms, faster than 39.45% of C++ online submissions for Total Hamming Distance.
//Memory Usage: 19.1 MB, less than 54.65% of C++ online submissions for Total Hamming Distance.
class Solution {
public:
    
    int totalHammingDistance(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> count(32, 0);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<32; j++)
            {
			    // storing every set bit of each number in the count array.
                if((nums[i]&(1<<j)) != 0)
                count[j] ++;
            }
        }
		// after saving all set bits in count array, we have got the count 
		// of all set bits of every number
		// like in example nums[] = {4, 14, 2}
		// count array will be like { ... 0, 1, 2, 2, 0}
		// means for every bit,
		// count[i] numbers will make pair with the n-count[i] numbers \
        // as 0 ^ 1 = 1
        int ans=0;
        for(int i=0; i<32; i++)
        {
            ans += count[i] * (n-count[i]);
        }
        return ans;
    }
};
