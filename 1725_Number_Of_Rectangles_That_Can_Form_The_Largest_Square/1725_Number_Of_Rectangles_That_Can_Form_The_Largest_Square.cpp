//Runtime: 40 ms, faster than 77.04% of C++ online submissions for Number Of Rectangles That Can Form The Largest Square.
//Memory Usage: 18.9 MB, less than 28.84% of C++ online submissions for Number Of Rectangles That Can Form The Largest Square.

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> maxlen;
        int m;
        int s = rectangles.size();
        for(int i = 0; i < s; i++){
            m = min(rectangles[i][1], rectangles[i][0]);
            maxlen.push_back(m);
        }
        
        sort(maxlen.begin(), maxlen.end());
        
        int count = 0;
        m = maxlen[s-1];
        for(int i = maxlen.size() - 1; i >= 0; i--){
            if(maxlen[i] == m){
                count ++;
            }
            else{
                break;
            }
        }
        return count;
    }
};
