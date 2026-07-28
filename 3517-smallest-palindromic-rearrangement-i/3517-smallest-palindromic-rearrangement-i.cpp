class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> frq(26, 0);
        for (char ch : s)
            frq[ch - 'a']++;

        int i = 0, j = 0;

        while (j < 26) {
            if (frq[j] != 0) {
                char ch = j + 'a';
                while (frq[j] > 1) {
                    s[i] = ch;
                    s[n - i - 1] = ch;
                    frq[j] -= 2;
                    i++;
                }
            }
            j++;
        }
        for (int p = 0; p < 26; p++) {
            if (frq[p] == 1) {
                s[i] = p + 'a';
            }
        }
        return s;
    }
};