// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a, b, p;
        do{
            a = rand7();
            b = rand7();
            p = a + (b-1) * 7;
        }while(p < 40);
        return 1 + (p - 1) % 10;
    }
};