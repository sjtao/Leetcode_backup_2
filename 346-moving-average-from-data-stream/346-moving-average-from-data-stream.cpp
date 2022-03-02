class MovingAverage {
public:
    list<int> number;
    int window;
    int n;
    double sum;
    double avg;
    MovingAverage(int size) {
        number.clear();
        window = size;
        n = 0;
        sum = 0;
    }
    
    double next(int val) {
        if(n < window){
            number.push_back(val);
            sum += val;
            n++;
        }
        else if(n == window){
            number.push_back(val);
            sum += val;
            sum -= number.front();
            number.pop_front();
        }
        avg = sum / n;
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */