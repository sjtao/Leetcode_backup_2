class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int md = pow(10, 9) + 7;
        vector<int> uniq;
        unordered_map<int, long> mp;
        for(int a : arr){
            if(mp.find(a) == mp.end())
                uniq.push_back(a);
            mp[a]++;
        }
        
        int n = uniq.size();
        sort(uniq.begin(), uniq.end());
        
        long ans = 0;
        // all different
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int s = target - (uniq[i] + uniq[j]); 
                if(s > uniq[j] && mp.find(s) != mp.end()){
                    ans += (mp[uniq[i]] * mp[uniq[j]] * mp[s]) % md;
                    ans %= md;
                }
            }
        }
        
        //all the same
        for(int i = 0; i < n; i++){
            if(target % 3 == 0 && target / 3 == uniq[i] && mp[uniq[i]] >= 3){
                ans += (mp[uniq[i]] * (mp[uniq[i]] - 1) * (mp[uniq[i]] - 2)) / 6;
                ans %= md;
            }
        }
        
        // two different xxy
        for(int i = 0; i < n; i++){
            if(mp[uniq[i]] >= 2){
                int s = target - 2 * uniq[i];
                for(int j = i+1; j < n; j++){
                    if(s == uniq[j]){
                        ans += (mp[uniq[i]] * (mp[uniq[i]] - 1)) / 2 * mp[s];
                        ans %= md;
                    }
                }  
            }
        }
        
        // two different xyy
        for(int i = 0; i < n; i++){
            int s = target - uniq[i];
            for(int j = i+1; j < n; j++){
                if(mp[uniq[j]] >= 2 && s == 2 * uniq[j]){
                    ans += (mp[uniq[j]] * (mp[uniq[j]] - 1)) / 2 * mp[uniq[i]];
                    ans %= md;
                }
            }  
        }
        
        return (int) ans;
    }
};