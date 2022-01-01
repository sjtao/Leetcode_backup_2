/**
Runtime: 4 ms, faster than 78.01% of C++ online submissions for Partition Labels.
Memory Usage: 6.9 MB, less than 21.17% of C++ online submissions for Partition Labels.
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> fl(26, vector<int>(2, -1));
        int n = s.length();
        int uni = 0;
        for(int i = 0; i < n; i++){
            if(fl[s[i]-'a'][0] == -1){
                //first time showing in s
                fl[s[i]-'a'][0] = i;
                fl[s[i]-'a'][1] = i;
                uni++;
            }
            else{
                fl[s[i]-'a'][1] = i;
            }
        }
        
        sort(fl.begin(), fl.end());
        int nz = 0;
        while(fl[nz][0] == -1) nz++;
        
        vector<int> ans;
        int mn = fl[nz][0], mx = fl[nz][1];
        for(int i = nz+1; i < 26; i++){
            if(fl[i][0] > mx){
                ans.push_back(mx-mn+1);
                mn = fl[i][0];
                mx = fl[i][1];
            }else{
                mx = max(mx, fl[i][1]);
            }
            if(i == 25)
               ans.push_back(mx-mn+1);
        }
        
        return ans;
    }
};
