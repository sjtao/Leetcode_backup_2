class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n3 = arr3.size();
        int p1 = 0, p2 = 0, p3 = 0;
        for(int a : arr1){
            while(p2 < n2 && arr2[p2] < a)
                p2++;
            while(p3 < n3 && arr3[p3] < a)
                p3++;
            int b = p2 == n2 ? 0 : arr2[p2];
            int c = p3 == n3 ? 0 : arr3[p3];
            if(a == b && a == c)
                ans.push_back(a);
        }
        return ans;
    }
};