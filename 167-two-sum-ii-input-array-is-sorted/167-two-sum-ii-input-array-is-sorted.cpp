class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n-1;
        while(left < right){
            int s = numbers[left] + numbers[right];
            if(s > target)
                right--;
            else if(s < target)
                left++;
            else
                return {left+1, right+1};
        }
        return {};
    }
};