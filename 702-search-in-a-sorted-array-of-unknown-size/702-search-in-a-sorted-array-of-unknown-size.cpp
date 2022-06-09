/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = target - reader.get(0);;
        
        while(l <= r){
            int m = l + (r-l) / 2;
            int nm = reader.get(m);
            if(nm == target)
                return m;
            else if(nm > target)
                r = m-1;
            else
                l = m+1;
        }
        return -1;
    }
};