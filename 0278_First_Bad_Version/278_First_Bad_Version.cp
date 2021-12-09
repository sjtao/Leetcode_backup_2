/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Bad Version.
Memory Usage: 5.8 MB, less than 66.08% of C++ online submissions for First Bad Version.
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        int mid;
        bool bad;
        while(low < high){
            mid = low + (high - low) / 2;
            bad = isBadVersion(mid);
            if(isBadVersion(mid))
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};
