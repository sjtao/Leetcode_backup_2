//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
//Memory Usage: 9.2 MB, less than 30.61% of C++ online submissions for Merge Sorted Array.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        if(m == 0) {
            nums1 = nums2;
            return;
        }
        
        for(int i = 0; i < n; i++){
            nums1[m+i] = nums2[i];
        }
        
        sort(nums1.begin(), nums1.end());
        return;
    }
};


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
//Memory Usage: 9.1 MB, less than 72.74% of C++ online submissions for Merge Sorted Array.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        int i = 0, j = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
            }
            else{
                nums3.push_back(nums2[j]);
                j++;
            } 
        }
        while(i < m){
            nums3.push_back(nums1[i]);
            i++;
        }
        while(j < n){
            nums3.push_back(nums2[j]);
            j++;
        }
        nums1 = nums3;
    }
};


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
//Memory Usage: 9.1 MB, less than 30.61% of C++ online submissions for Merge Sorted Array.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
    }
};

/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
Memory Usage: 9.2 MB, less than 27.90% of C++ online submissions for Merge Sorted Array.
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < m; i++)
            pq.push(nums1[i]);
        for(int i = 0; i < n; i++)
            pq.push(nums2[i]);
        
        for(int i = 0; i < m+n; i++){
            nums1[i] = pq.top();
            pq.pop();
        }
        
        return;
    }
};
