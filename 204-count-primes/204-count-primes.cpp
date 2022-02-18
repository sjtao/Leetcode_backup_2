class Solution {
public:
 
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<int> prime(n, 0);
        int count = 1;
        for(int i = 3; i < n; i+=2){
            if(prime[i] == 0){
                count++;
                for(int j = i; j < n; j += i)
                    prime[j] = 1;
            }
        }
        
        return count;
    }
};