class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        vector<int> prifixGcd(n);
        prifixGcd[0] = mx;
        for (int i = 1; i < n; i++) {
            mx = max(nums[i], mx);
            prifixGcd[i] = gcd(nums[i], mx);
        }
        sort(prifixGcd.begin(), prifixGcd.end());

        int i = 0, j = n - 1;
        long long ans = 0;
        while (i < j) {
            ans += gcd(prifixGcd[i], prifixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};