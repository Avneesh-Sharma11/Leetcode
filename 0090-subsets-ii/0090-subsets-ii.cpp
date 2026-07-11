class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int>& output,
               int idx) {

        res.push_back(output);

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            output.push_back(nums[i]);
            solve(nums, res, output, i + 1);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> output;
        solve(nums, res, output, 0);
        return res;
    }
};