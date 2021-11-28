/**
Runtime: 4 ms
Memory Usage: 9.9 MB
Your runtime beats 90.15 % of cpp submissions
*/

class Solution {
public:
    bool EvenDigitsHelper(int num){
        if (num < 10) return false;
        int digit = 0;
        while(num > 0){
            num /= 10;
            digit ++;
        }
        return (digit % 2 == 0);
    }
    
    int findNumbers(vector<int>& nums) {
        int even = 0;
        for(int n : nums){
            even += EvenDigitsHelper(n);
        }
        return even;
    }
};
