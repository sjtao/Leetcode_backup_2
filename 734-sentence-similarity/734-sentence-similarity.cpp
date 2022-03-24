class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int n1 = sentence1.size();
        int n2 = sentence2.size();
        if(n1 != n2) return false;
        
        unordered_map<string,set<string>> mp;
        for(auto p : similarPairs){
            mp[p[0]].insert(p[1]);
        }
        
        for(int i = 0; i < n1; ++i){
            if(sentence1[i] != sentence2[i] && mp[sentence1[i]].count(sentence2[i]) == 0 \
              && mp[sentence2[i]].count(sentence1[i]) == 0)
                return false;
        }
        
        return true;
    }
};