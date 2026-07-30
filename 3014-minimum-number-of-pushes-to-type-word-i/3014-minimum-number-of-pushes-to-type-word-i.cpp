class Solution {
public:
    int minimumPushes(string word) {
        int result = 0;
        unordered_map<int, int> mp;
        int key = 2;
        for (char ch : word) {
            if (key > 9)
                key = 2;
            mp[key]++;
            result += mp[key];
            key++;
        }
        return result;
    }
};