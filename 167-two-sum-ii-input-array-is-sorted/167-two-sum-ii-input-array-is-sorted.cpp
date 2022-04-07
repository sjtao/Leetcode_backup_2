class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while(l < r){
            int a = numbers[l] + numbers[r];
            if(a > target)
                r--;
            else if(a < target)
                l++;
            else
                return {l+1, r+1};
        }
        return {-1,-1};
    }
};