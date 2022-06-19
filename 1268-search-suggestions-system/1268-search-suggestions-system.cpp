class Solution {
public:
    int compare(string a, string b){
        int n = min(a.length(), b.length());
        int i = 0;
        while(i < n && a[i] == b[i]) i++;
        return i;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = searchWord.length();
        vector<vector<string>> ans(n);
        sort(products.begin(), products.end());
        int M = 3;
        for(string p : products){
            int k = compare(p, searchWord);
            for(int i = 0; i < k; i++){
                if(ans[i].size() < M)
                    ans[i].push_back(p);
            }
        }
        return ans;
    }
};