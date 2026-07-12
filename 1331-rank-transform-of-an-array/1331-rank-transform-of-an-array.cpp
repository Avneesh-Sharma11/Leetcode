class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;

        for (auto it : arr)
            mp[it]++;

        int rank = 1;
        for (auto& it : mp) {
            it.second = rank;
            rank++;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};