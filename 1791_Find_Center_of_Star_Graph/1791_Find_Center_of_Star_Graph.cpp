//Runtime: 176 ms, faster than 82.78% of C++ online submissions for Find Center of Star Graph.
//Memory Usage: 67.4 MB, less than 53.82% of C++ online submissions for Find Center of Star Graph.

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //center node: 
        //exactly n - 1 edges 
        //connect the center node with every other node
        if((edges[0][0] == edges[1][0])|| (edges[0][0] == edges[1][1]))
            return edges[0][0];
        
        return edges[0][1];
    }
};
