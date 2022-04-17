class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        while(left < right){
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int n : nums)
                count += (n-1) / mid;
            if(count > maxOperations)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};