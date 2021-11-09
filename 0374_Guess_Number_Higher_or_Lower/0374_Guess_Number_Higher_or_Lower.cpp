

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the guess number
 *			      1 if num is lower than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Guess Number Higher or Lower.
//Memory Usage: 6 MB, less than 23.04% of C++ online submissions for Guess Number Higher or Lower.

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        int num, res;
        while(low <= high){
            num = low + (high - low) / 2;
            res = guess(num);
            if(res == -1){
                high = num-1; //higher than the guess number
            }
            else if(res == 1){
                low = num+1; //lower than the guess number
            }
            else if(res == 0){
                return num;
            }
        }
        return -1;
    }
};
