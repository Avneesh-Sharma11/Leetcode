class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int>& output, int idx) {
        if (idx == nums.size()) {
            res.push_back(output);
            return;
        }
        output.push_back(nums[idx]);
        solve(nums, res, output, idx + 1);
        output.pop_back();
        solve(nums, res, output, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        solve(nums, res, output, 0);
        return res;
    }
};