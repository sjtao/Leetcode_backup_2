class Solution {
public:
    int n;
    int push(string& dominoes){
        
        if(dominoes[0] == '.' && dominoes[1] == 'L')
            dominoes[0] = 'l';
        
        if(dominoes[n-1] == '.' && dominoes[n-2] == 'R')
            dominoes[n-1] = 'r';
        
        for(int i = 1; i < n-1; i++){
            if(dominoes[i] == '.'){
                if(dominoes[i-1] == 'R' && dominoes[i+1] == 'L')
                    continue;
                else if(dominoes[i-1] == 'R' && dominoes[i+1] != 'L')
                    dominoes[i] = 'r';
                else if(dominoes[i-1] != 'R' && dominoes[i+1] == 'L')
                    dominoes[i] = 'l';
            }
        }
        
        int k = 0;
        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'l'){
                dominoes[i] = 'L';
                k++;
            }
            else if(dominoes[i] == 'r'){
                dominoes[i] = 'R';
                k++;
            }
        }
        
        return k;
    }
    
    string pushDominoes(string dominoes) {
        n = dominoes.size();
        if(n == 1)
            return dominoes;
        
        int state = 0;
        do{
            state = push(dominoes);
        }while(state > 0);
        
        return dominoes;
    }
};