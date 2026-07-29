class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int a = 0, b = 1, c = 2;
        // a=3 b= 2 c=

        while (n - 2 > 0) {

            a = b + c;
            b = c;
            c = a;
            n--;
        }
        return c;
    }
};