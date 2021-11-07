//error for case "6913259244" "71103343"
//terminate called after throwing an instance of 'std::out_of_range'
//  what():  stoi


class Solution {
public:
    
    string multiply(string num1, string num2) {
        //convert to integer
        long int n1 = stoi(num1,nullptr,10);
        long int n2 = stoi(num2,nullptr,10);
        //product
        long int prod = n1 * n2;
        //convert to string
        return to_string(prod);
    }
};


//Line 17: Char 33: runtime error: signed integer overflow: 498828660196 * 840477629533 cannot be represented in type 'long long' (solution.cpp)
//SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:26:33
class Solution {
public:
    long long int ConvertToInt(string num){
        long long int s = 0;
        for(int i = 0; i < num.length(); i++){
            s = s * 10 + (num[i] - '0');
        }
        return s;
    }
    string multiply(string num1, string num2) {
        //convert to integer
        long long int n1 = ConvertToInt(num1);
        long long int n2 = ConvertToInt(num2);
        //product
        long long int prod = n1 * n2;
        //convert to string
        return to_string(prod);
    }
};

