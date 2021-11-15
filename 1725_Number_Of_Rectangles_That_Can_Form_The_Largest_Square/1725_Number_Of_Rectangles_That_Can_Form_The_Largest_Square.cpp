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

//Runtime: 40 ms, faster than 77.04% of C++ online submissions for Number Of Rectangles That Can Form The Largest Square.
//Memory Usage: 18.4 MB, less than 55.09% of C++ online submissions for Number Of Rectangles That Can Form The Largest Square.
    
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        
        int m, t;
        int s = rectangles.size();
        //find the max(min(l,w))
        for(int i = 0; i < s; i++){
            t = min(rectangles[i][1], rectangles[i][0]);
            m = (m > t) ? m : t;
        }
        
        int count = 0;
        
        for(int i = 0; i < s; i++){
            t = min(rectangles[i][1], rectangles[i][0]);
            if(t == m)
            {
                count ++;
            }
        }
        
        return count;
    }
};
