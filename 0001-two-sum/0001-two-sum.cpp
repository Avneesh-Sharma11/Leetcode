class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int b = target - nums[i];

            if (mp.find(b) != mp.end()) {
                return {mp[b], i};
            }
            mp[a] = i;
        }
        return {};
    }
};