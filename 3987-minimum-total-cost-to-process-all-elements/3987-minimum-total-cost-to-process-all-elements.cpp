class Solution {
public:
    long long m = 1e9 + 7;
    int minimumCost(vector<int>& nums, int k) {
        long long cnt = 0;
        long long x = k;
        for (int i = 0; i < nums.size(); i++) {
            if (x < nums[i]) {
                long long diff = nums[i] - x;
                long long need = ceil((double)diff / k);
                x += k * need;
                cnt += need;
            }
            x -= nums[i];
        }
        long long a = (cnt % 2 == 0) ? cnt / 2 : cnt;
        cnt += 1;
        long long b = (cnt % 2 == 0) ? cnt / 2 : cnt;

        long long ans = ((a % m) * (b % m)) % m;

        return ans;
    }
};