/**
Runtime: 8 ms, faster than 78.80% of C++ online submissions for Flood Fill.
Memory Usage: 13.8 MB, less than 90.77% of C++ online submissions for Flood Fill.
*/
class Solution {
public:
    void FillHelper(vector<vector<int>>& image, int sr, int sc, int color, int newColor){
        //change start pixel
        //change 4 connected pixels with the same color to the start pixel
        //change connectin pixels with the same color to the connected pixels
        if(image[sr][sc] == color){
            image[sr][sc] = newColor;
            if(sr > 0) FillHelper(image, sr-1, sc, color, newColor);
            if(sr < image.size()-1) FillHelper(image, sr+1, sc, color, newColor);
            if(sc > 0) FillHelper(image, sr, sc-1, color, newColor);
            if(sc < image[0].size()-1) FillHelper(image, sr, sc+1, color, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(color != newColor)
            FillHelper(image, sr, sc, color, newColor);
        return image; 
    }
};
