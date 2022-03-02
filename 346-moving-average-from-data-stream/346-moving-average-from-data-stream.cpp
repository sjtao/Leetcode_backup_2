class MovingAverage {
public:
    vector<int> number;
    int window;
    int n;
    double sum;
    double avg;
    int cnt;
    MovingAverage(int size) {
        number = vector<int>(size, 0);
        sum = 0;
        window = size;
        n = -1;
        cnt = 0;
    }
    
    double next(int val) {
        cnt++;
        n = (n+1) % window;
        sum = sum - number[n] + val;
        number[n] = val;
        return sum / min(window, cnt);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */