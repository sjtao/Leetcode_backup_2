/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Two Sum II - Input Array Is Sorted.
Memory Usage: 9.6 MB, less than 43.18% of C++ online submissions for Two Sum II - Input Array Is Sorted.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n-1, t;
        vector<int> ans;
        while(i < j){
            t = numbers[i] + numbers[j];
            if(t > target){
                j--;
            }
            else if(t < target){
                i++;
            }
            else{
                ans.push_back(1+i);
                ans.push_back(1+j);
                break;
            }
        }
        return ans;
    }
};
