/**
Runtime: 276 ms, faster than 96.35% of C++ online submissions for Find Median from Data Stream.
Memory Usage: 117.1 MB, less than 64.42% of C++ online submissions for Find Median from Data Stream.
*/

//_ _ _ _ m _ _ _ _
//maxheap    minheap
class MedianFinder {
public:
    //min-heap
    priority_queue<int, vector<int>, greater<int>> minpq;
    //max-heap
    priority_queue<int> maxpq;
    double median;
    
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        if(maxpq.empty() || maxpq.top()>num){
            maxpq.push(num);
        }
        else{
            minpq.push(num);
        }
        if(maxpq.size() > minpq.size() + 1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(minpq.size() > maxpq.size() + 1){
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        if(minpq.size() == maxpq.size() && !maxpq.empty()){
            median = (minpq.top() + maxpq.top())/2.0;
        }
        else if(minpq.size() > maxpq.size()){
            median = minpq.top();
        }
        else{
            median = maxpq.top();
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
