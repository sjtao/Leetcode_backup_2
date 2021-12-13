class MovingAverage {
private:
    queue<int> q;
    int s, sum = 0;
public:
    MovingAverage(int size) {
        s = size;
    }
    
    double next(int val) {
        q.push(val);
        if(q.size() > s){
            sum += val - q.front();
            q.pop();
        }
        else{
            sum += val;
        }

        return sum * 1.0 / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
