/**
Runtime: 84 ms, faster than 65.17% of C++ online submissions for Minimum Index Sum of Two Lists.
Memory Usage: 42.3 MB, less than 12.12% of C++ online submissions for Minimum Index Sum of Two Lists.
*/
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        int n1 = list1.size();
        int n2 = list2.size();
        
        unordered_map<string, int> mp, rp;
        vector<vector<string>> ans(n1+n2, vector<string>());
        
        for(int i = 0; i < n1; i++){
            mp[list1[i]] = i;
        }
        for(int i = 0; i < n2; i++){
            if(mp.find(list2[i]) != mp.end())
                rp[list2[i]] = mp[list2[i]] + i; //list2[i] shows in list1 and list2
        }
        
        int mi = n1+n2+1;
        for(auto it = rp.begin(); it!=rp.end(); it++){
            ans[it->second].push_back(it->first);
            mi = min(mi, it->second);
        }
        
        return ans[mi];
    }
};
