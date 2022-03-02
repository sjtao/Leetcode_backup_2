class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        int dis = n;
        int a = -1;
        int b = -1;
        for(int i = 0; i < n; ++i){
            if(wordsDict[i] == word1)
                a = i;
            else if(wordsDict[i] == word2)
                b = i;
            if(a != -1 && b != -1){
                dis = min(dis, abs(a-b));
            }
        }
        return dis;
    }
};