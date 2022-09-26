class Solution {
public:
    //graph -- connect
    vector<int> root, rank;
    
    int find(int x){
        while(x != root[x])
            x = root[x];
        return x;
    }
    
    void unionset(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            if(rank[rootx] > rank[rooty])
                root[rooty] = rootx;
            else if(rank[rootx] < rank[rooty])
                root[rootx] = rooty;
            else{
                root[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }
    
    bool connected(int x, int y){
        return find(x) == find(y);
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        root = vector<int>(26);
        rank = vector<int>(26);
        
        for(int i = 0; i < 26; i++){
            root[i] = i;
            rank[i] = 1;
        }
        for(string s : equations){
            if(s[1] == '='){
                unionset(s[0]-'a', s[3]-'a');
            }
        }
        
        for(string s : equations){
            if(s[1] == '!'){
                if(connected(s[0]-'a', s[3]-'a'))
                    return false;
            }
        }
        
        return true;
    }
    
};