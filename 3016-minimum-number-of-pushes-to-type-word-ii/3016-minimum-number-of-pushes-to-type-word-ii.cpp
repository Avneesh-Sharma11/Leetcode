class Solution {
public:
    int minimumPushes(string word) {

        vector<pair<char, int>> frq(26);

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            frq[ch - 'a'].first = ch;
            frq[ch - 'a'].second++;
        }
        sort(frq.begin(), frq.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second > b.second;
        });
        unordered_map<int, int> mp;
        int key = 2;
        int res = 0;
        int i = 1;
        for (auto p : frq) {
            if (key > 9) {
                key = 2;
                i++;
            }
            mp[key] += p.second * i;
            key++;
        }

        for (auto p : mp) {
            res += p.second;
        }
        return res;
    }
};