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
