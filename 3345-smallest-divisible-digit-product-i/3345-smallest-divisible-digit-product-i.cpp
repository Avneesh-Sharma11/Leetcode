class Solution {
public:
    int smallestNumber(int n, int t) {

        while (n <= 100) {
            int num = n;
            int mul = 1;
            while (num > 0) {
                mul *= num % 10;
                num /= 10;
            }
            if (mul % t == 0)
                return n;
            n++;
        }
        return 0;
    }
};