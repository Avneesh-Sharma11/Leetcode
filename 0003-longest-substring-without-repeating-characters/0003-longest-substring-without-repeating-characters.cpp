class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            vector<int> hash(256, 0);
            for (int j = i; j < s.length(); j++) {
                if (hash[s[j]] == 1)
                    break;
                ans = max(ans, j - i + 1);
                hash[s[j]] = 1;
            }
        }
        return ans;
    }
};