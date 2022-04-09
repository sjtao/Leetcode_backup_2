class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
        
        for(int& a : arr){
            if(mp.find(2*a) != mp.end()){
                if(a != 2*a || (a == 2*a && mp[2*a].size()>1))
                    return true;
            }
        }
        
        return false;
    }
};