class Solution {
public:
    int maxProduct(int n) {
        int D1 = 0;
        int D2 = 0;

        while (n > 0) {
            int r = n % 10;
            n /= 10;
            if (D1 <= r) {
                D2 = D1;
                D1 = r;
            }
            if(r < D1 && D2 < r){
                D2 = r;
            }
        }
        return D1 * D2;
    }
};