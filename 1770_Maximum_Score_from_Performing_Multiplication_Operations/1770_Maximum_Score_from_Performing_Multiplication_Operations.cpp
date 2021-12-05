/**
Runtime: 547 ms, faster than 29.81% of C++ online submissions for Maximum Score from Performing Multiplication Operations.
Memory Usage: 91.2 MB, less than 56.60% of C++ online submissions for Maximum Score from Performing Multiplication Operations.
*/
class Solution {
private: 
    int n, m;
    vector<int> nms, mul;
    int score[1001][1001] = {0};
public:
    int ScoreDPHelper(int i, int left){
        if(i == m) return 0;
        
        int mult = mul[i];
        int right = n - 1 - (i - left);
        if (score[i][left] == 0)
            score[i][left] = max(nms[left] * mult + ScoreDPHelper(i+1, left+1), 
                                 nms[right] * mult + ScoreDPHelper(i+1, left));
        
        return score[i][left];
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        m = multipliers.size();
        nms = nums;
        mul = multipliers;
        
        return  ScoreDPHelper(0,0);
    }
};
