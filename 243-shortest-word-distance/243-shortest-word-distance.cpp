class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> w1, w2;
        int n = wordsDict.size();
        for(int i = 0; i < n; i++){
            if(wordsDict[i] == word1)
                w1.push_back(i);
            else if(wordsDict[i] == word2)
                w2.push_back(i);
        }
        
        int n1 = w1.size();
        int n2 = w2.size();
        int dis = n+1;
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                int d = abs(w1[i] - w2[j]);
                dis = min(d, dis);
            }
        }
        
        return dis;
    }
};