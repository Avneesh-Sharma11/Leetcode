class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> dg(nums.size());
        int maxD = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            int L = INT_MIN;
            int S = INT_MAX;
            for (int i = 0; i < s.length(); i++) {
                L = max(L, s[i] - '0');
                S = min(S, s[i] - '0');
            }
            dg[i] = L - S;
            maxD = max(maxD, L - S);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maxD == dg[i]) {
                ans += nums[i];
            }
        }
        return ans;
    }
};