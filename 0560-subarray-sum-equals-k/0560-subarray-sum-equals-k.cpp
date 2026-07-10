class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int currSum = 0;
        int res = 0;
        mp.insert({0, 1});
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            if (mp.find(currSum - k) != mp.end()) {
                res += mp[currSum-k];
            }

            mp[currSum]++;
        }
        return res;
    }
};