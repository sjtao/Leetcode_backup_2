class Solution {
public:
    unordered_map<int, string> mp = {{1,"I"}, {4,"IV"}, {5,"V"}, {9,"IX"}, 
                                     {10,"X"}, {40,"XL"}, {50,"L"}, {90,"XC"},
                                     {100,"C"}, {400,"CD"}, {500,"D"}, {900,"CM"},
                                     {1000,"M"}};
    string digit1(int n, int k){
        string r = "";
        //n: [1,9]
        if(n == 1 || n == 4 || n == 5 || n == 9)
            r += mp[n*k]; 
        else if(n < 9 && n > 5)
            r += mp[5*k] + digit1(n-5, k);
        else if(n < 4 && n > 1)
            r += mp[1*k] + digit1(n-1, k);
        
        return r;
    }
    
    string intToRoman(int num) {
        string res = "";
        //1-10
        int k = 1;
        while(num > 0){
            res = digit1(num % 10, k) + res;
            k *= 10;
            num /= 10;
        }
        return res;
    }
};