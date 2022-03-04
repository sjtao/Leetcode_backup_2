class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        //Sieve of Eratosthenes
        vector<int> p(n, 1);
        for(int i = 2; i < sqrt(n)+1; ++i){
            if(p[i] == 1){
                for(int j = i*i; j < n; j+=i){
                    p[j] = 0;
                }  
            }
        }
        int ans = 0;
        for(int i = 2; i < n; ++i)
            ans += p[i];
        return ans;
    }
};