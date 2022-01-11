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
        if(reader.get(0) == target) return 0;
        
        int left = 0, right = 1, mid;
        while(reader.get(right) < target){
            left = right;
            right *= 2;
        }
        
        int number;
        while(left <= right){
            mid = left + (right - left) / 2;
            number = reader.get(mid);
            
            if(number == target) return mid;
            else if(number > target) right = mid-1;
            else                     left  = mid+1;
        }
        
        return -1;
    }
};