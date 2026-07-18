class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        map<int, int> mp;
        for (int num : nums)
            mp[num] = 1;

        int pre = INT_MIN;
        int cnt = 1;
        int maxC = INT_MIN;
        for (auto p : mp) {
            int n = p.first;

            if (pre == INT_MIN) {
                pre = n;
            } else {
                if (abs(n - pre) == 1) {
                    cnt++;
                } else {
                    maxC = max(cnt, maxC);
                    cnt = 1;
                }
                pre = n;
            }
        }
        maxC = max(cnt, maxC);
        return maxC;
    }
};