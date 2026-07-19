class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIdx(26);
        for (int i = 0; i < s.length(); i++)
            lastIdx[s[i] - 'a'] = i;

        vector<bool> t(26, false);

        string res = "";
        res.push_back(s[0]);
        t[s[0] - 'a'] = true;
        for (int i = 1; i < s.length(); i++) {
            char ch = s[i];
            if(t[ch-'a'] == true) continue;
            
            while (!res.empty() && res.back() > ch &&
                   i < lastIdx[res.back() - 'a']) {
                   
                t[res.back() - 'a'] = false;
                res.pop_back();
            }
            if (t[ch - 'a'] == false) {
                res.push_back(ch);
                t[ch - 'a'] = true;
            }
        }
        return res;
    }
};