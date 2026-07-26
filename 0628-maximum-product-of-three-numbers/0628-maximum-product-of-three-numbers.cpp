class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        int ans1 = 1LL * nums[n] * nums[n - 1] * nums[n - 2];
        int ans2 = 1LL * nums[0] * nums[1] * nums[n];
        return max(ans1, ans2);
    }
};