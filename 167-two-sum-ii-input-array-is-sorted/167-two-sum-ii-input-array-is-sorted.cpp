class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0; i < n; ++i){
            int l = i+1;
            int r = n-1;
            while(l <= r){
                int m = l + (r-l)/2;
                if(numbers[m] == target-numbers[i])
                    return {i+1, m+1};
                else if(numbers[m] > target-numbers[i])
                    r = m-1;
                else
                    l = m+1;
            }            
        }
        return {-1,-1};
    }
};