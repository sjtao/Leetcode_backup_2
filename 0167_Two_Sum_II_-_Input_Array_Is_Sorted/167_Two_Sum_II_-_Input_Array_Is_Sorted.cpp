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

/**
Runtime: 11 ms, faster than 9.54% of C++ online submissions for Two Sum II - Input Array Is Sorted.
Memory Usage: 9.9 MB, less than 5.24% of C++ online submissions for Two Sum II - Input Array Is Sorted.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        
        int n = numbers.size();
        for(int i = 0; i < n; i++){
            mp[numbers[i]] = i;
        }
        
        int r;
        vector<int> ans(2);
        for(int i = 0; i < n; i++){
            r = target - numbers[i];
            if(mp.find(r) != mp.end()){
                if(mp[r] != i){
                    ans[0] = i+1;//1-indexed array
                    ans[1] = mp[r]+1;
                    break;
                }
            }
        }
        
        return ans;
    }
};
