class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = boxes.size();
        int m = warehouse.size();
        
        sort(boxes.begin(), boxes.end());
        
        for(int i = 1; i < m; i++)
            warehouse[i] = min(warehouse[i], warehouse[i-1]);
        
        int b = 0;
        for(int i = m-1; i >= 0; i--){
            if(b < n && boxes[b] <= warehouse[i]){
                b++;
            }
        }

        return b;
    }
};