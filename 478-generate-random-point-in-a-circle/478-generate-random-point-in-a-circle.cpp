class Solution {
public:
    double R, R2, X, Y;
    Solution(double radius, double x_center, double y_center) {
        R = radius;
        X = x_center;
        Y = y_center;
    }
    
    vector<double> randPoint() {
        double a, b, ang, r;
        ang = (double)rand()/RAND_MAX * 2 * M_PI;
        r = sqrt((double)rand()/RAND_MAX) * R;
            
        a = sin(ang) * r + X;
        b = cos(ang) * r + Y;
        return {a, b};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */