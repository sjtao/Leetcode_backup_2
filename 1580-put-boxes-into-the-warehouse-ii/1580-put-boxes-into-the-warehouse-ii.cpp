class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int m = warehouse.size();
        int n = boxes.size();
        
        sort(boxes.begin(), boxes.end());
        
        int b = 0;
        int left = 0, right = m-1;
        for(int i = n-1; i >= 0 && left <= right; i--){
            if(boxes[i] <= warehouse[left]){
                b++;
                left++;
            }
            else if(boxes[i] <= warehouse[right]){
                b++;
                right--;
            }
        }
        
        return b;
    }
};