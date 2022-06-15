class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int m = warehouse.size();
        
        vector<int> copy_ware(m);
        
        int mn = INT_MAX;
        for(int i = 0; i < m; i++){
            mn = min(mn, warehouse[i]);
            copy_ware[i] = mn;
        }
        
        mn = INT_MAX;
        for(int i = m-1; i >= 0; i--){
            mn = min(mn, warehouse[i]);
            copy_ware[i] = max(copy_ware[i], mn);
        }
        
        int n = boxes.size();
        sort(boxes.begin(), boxes.end());
        sort(copy_ware.begin(), copy_ware.end());
        
        int b = 0;
        for(int i = 0; i < m; i++){
            if(b < n && boxes[b] <= copy_ware[i])
                b++;
        }
        
        return b;
    }
};