class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        set<int> st1(arr1.begin(), arr1.end()), st2(arr2.begin(), arr2.end());
        for(int a : arr3){
            if(st1.count(a) && st2.count(a))
                ans.push_back(a);
        }
        return ans;
    }
};