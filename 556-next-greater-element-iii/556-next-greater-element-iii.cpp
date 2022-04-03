class Solution {
private:
     void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i >= 0 && nums[i] >= nums[i+1])
            i--;
        if(i >= 0){
            int j = nums.size() - 1;
            while(j >= 0 && nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
public:
    int nextGreaterElement(int n) {
        if(n < 10) return -1;

        vector<int> val;
        int num = n;
        for( ; num > 0; num /= 10)
            val.push_back(num % 10);
        
        reverse(val.begin(), val.end());
        nextPermutation(val);
        int a = 0;
        for(int i : val){
            if(a > INT_MAX / 10 || (a == INT_MAX / 10 && i > INT_MAX % 10)){
                a = -1;
                break;
            }
            a = a * 10 + i;
        }
            
        return a <= n ? -1 : a;
    }
};