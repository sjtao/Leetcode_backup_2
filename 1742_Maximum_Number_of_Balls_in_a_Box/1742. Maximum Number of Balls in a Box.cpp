//Runtime: 20 ms, faster than 64.50% of C++ online submissions for Maximum Number of Balls in a Box.
//Memory Usage: 6.1 MB, less than 72.87% of C++ online submissions for Maximum Number of Balls in a Box.

class Solution {
public:
    
    int sumnumber(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> number;
        int sum;
        for(int i = lowLimit; i <= highLimit; i++){
            number[sumnumber(i)]++;
        }
        
        int ans = -1;
        for(auto itr : number){
            ans = max(ans, itr.second);
        }
             
        return ans;
    }
};


//Runtime: 8 ms, faster than 90.54% of C++ online submissions for Maximum Number of Balls in a Box.
//Memory Usage: 6.1 MB, less than 72.87% of C++ online submissions for Maximum Number of Balls in a Box.
class Solution {
public:
    
    int sumnumber(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
    int countBalls(int lowLimit, int highLimit) {
        //hightlimit <= 10^5, 99999 = 45
        vector<int> number(46,0);
       
        for(int i = lowLimit; i <= highLimit; i++){
            number[sumnumber(i)]++;
        }
        
        int ans = -1;
        for(auto itr : number){
            ans = max(ans, itr);
        }
             
        return ans;
    }
};
