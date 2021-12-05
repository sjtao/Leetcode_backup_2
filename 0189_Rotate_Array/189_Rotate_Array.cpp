/**
Runtime: 28 ms, faster than 72.10% of C++ online submissions for Rotate Array.
Memory Usage: 26.4 MB, less than 5.56% of C++ online submissions for Rotate Array.
*/
//time O(n) space O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;
        
        vector<int> ans;
        for(int i = n-k; i < n; i++){
            ans.push_back(nums[i]);
        }
        for(int i = 0; i < n-k; i++){
            ans.push_back(nums[i]);
        }
        nums = ans;
        
        return;
    }
};

/**
Runtime: 32 ms, faster than 47.61% of C++ online submissions for Rotate Array.
Memory Usage: 25 MB, less than 77.88% of C++ online submissions for Rotate Array.
*/
//time O(N) space O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;
        
        //cyclic replacement
        int count = 0;
        for(int s = 0; count < n; s++){
            int current = s;
            int prev = nums[s];
            do{
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count ++;
            }while(s != current);
        }
        
        return;
    }
};

/**
Runtime: 32 ms, faster than 47.61% of C++ online submissions for Rotate Array.
Memory Usage: 25 MB, less than 77.88% of C++ online submissions for Rotate Array.
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
