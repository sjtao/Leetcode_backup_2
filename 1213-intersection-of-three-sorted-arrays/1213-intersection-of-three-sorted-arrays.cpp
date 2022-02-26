class Solution {
public:
    unordered_map<int,int> mp;
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        for(int a : arr1)
            mp[a]++;
        for(int a : arr2)
            mp[a]++;
        for(int a : arr3)
            mp[a]++;
        
        vector<int> ans;
        for(int a : arr1){
            if(mp[a] == 3)
                ans.push_back(a);
        }
        
        return ans;
    }
};