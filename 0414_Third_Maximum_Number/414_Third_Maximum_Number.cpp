/**
Runtime: 12 ms, faster than 27.80% of C++ online submissions for Third Maximum Number.
Memory Usage: 10.7 MB, less than 17.74% of C++ online submissions for Third Maximum Number.
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> mx3; //in set, increasing  order (by default)
        for(int n : nums){
            mx3.insert(n);
            if(mx3.size() > 3){
                mx3.erase(mx3.begin());
            }
        }
        
        return mx3.size() < 3 ? *mx3.rbegin() : *mx3.begin();
    }
};
