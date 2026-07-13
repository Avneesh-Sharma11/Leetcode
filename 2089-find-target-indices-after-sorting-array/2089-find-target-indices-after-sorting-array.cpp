class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0;
        int count = 0;

        for (int num : nums) {
            if (num < target)
                less++;
            else if (num == target)
                count++;
        }
        vector<int> ans;

        for (int i = 0; i < count; i++) {
            ans.push_back(less + i);
        }
        return ans;
    }
};