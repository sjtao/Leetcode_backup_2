class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        
        int n = wordsDict.size();
        int n1 = -1, n2 = -1;
        int dis = n+1;
        for(int i = 0; i < n; i++){
            if(wordsDict[i] == word1)
                n1 = i;
            else if(wordsDict[i] == word2)
                n2 = i;
            
            if(n1 != -1 && n2 != -1)
                dis = min(abs(n1 - n2), dis);
        }
        
        return dis;
    }
};