/**
Runtime: 108 ms, faster than 42.70% of C++ online submissions for Furthest Building You Can Reach.
Memory Usage: 53.6 MB, less than 76.31% of C++ online submissions for Furthest Building You Can Reach.
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        int hd;
        for(int i = 0; i < n-1; i++){
            hd = heights[i+1] - heights[i];
            //need ladder or bricks
            if(hd > 0){
                pq.push(hd);
                //largest difference building --> use ladder
                if(pq.size()<=ladders)
                    continue;
                
                bricks -= pq.top();
                pq.pop();
                
                if(bricks < 0)
                    return i;
            }
        }
        return n-1;
    }
};
