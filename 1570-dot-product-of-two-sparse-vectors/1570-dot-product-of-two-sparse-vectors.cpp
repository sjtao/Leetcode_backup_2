class SparseVector {
public:
    vector<pair<int,int>> nzro;
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nzro.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        int p = 0, q = 0;
        while(p < nzro.size() && q < vec.nzro.size()){
            if(nzro[p].first == vec.nzro[q].first){
                sum += nzro[p++].second * vec.nzro[q++].second;
            }
            else if(nzro[p].first > vec.nzro[q].first)
                q++;
            else
                p++;
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);