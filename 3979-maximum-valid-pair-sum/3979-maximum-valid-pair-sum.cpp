class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suff(n);
        suff[n - 1] = nums[n - 1];
        int idx = n - 1;
        for (int i = n - 2; i >= 0; i--) {

            suff[i] = max(suff[i + 1], nums[i]);
        }
        int maxSum = 0;

        for (int i = 0; i < n - k; i++) {

            maxSum = max(maxSum, suff[i+k] + nums[i]);
        }
        return maxSum;
    }
};