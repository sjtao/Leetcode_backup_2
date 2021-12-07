/**
Runtime: 740 ms, faster than 5.03% of C++ online submissions for Sort an Array.
Memory Usage: 279.1 MB, less than 5.33% of C++ online submissions for Sort an Array.
*/

class Solution {
public:
    vector<int> sortHelper(vector<int>& nums){
        int n = nums.size();
        if(n <= 1) return nums;
        
        int h = n / 2;
        vector<int> left, right, l, r;
        copy(nums.begin(), nums.begin()+h, back_inserter(left));
        copy(nums.begin()+h, nums.end(), back_inserter(right));
        l = sortHelper(left);
        r = sortHelper(right);
        return merge(l, r);
    }
    
    vector<int> merge(vector<int>& left, vector<int>& right){
        int l = left.size();
        int r = right.size();
        vector<int> ans;
        int li = 0, ri = 0;
        while(li < l && ri < r){
            if(left[li] < right[ri]){
                ans.push_back(left[li++]);
            }
            else{
                ans.push_back(right[ri++]);
            }
        }
        while(li < l){
            ans.push_back(left[li++]);
        }
        while(ri < r){
            ans.push_back(right[ri++]);
        }
        return ans;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        return sortHelper(nums);
    }
};
