class Solution {
private:
    unordered_map<int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"},
                                     {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
public:
    vector<string> ans;
    int n;
    void permute(int idx, string digits, string& combi){
        if(idx == n){
            ans.push_back(combi);
            return;
        }
        string sd = mp[digits[idx]-'0'];
        for(int i = 0; i < sd.size(); i++){
            combi += sd[i];
            permute(idx+1, digits, combi);
            combi.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if(n == 0) return ans;
        
        string combi = "";
        permute(0, digits, combi);
        return ans;
    }
};