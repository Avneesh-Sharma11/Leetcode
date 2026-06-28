class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> res;
        res.push_back(occupiedIntervals[0]);

        for (int i = 1; i < occupiedIntervals.size(); i++) {
            int a = occupiedIntervals[i][0];
            int b = occupiedIntervals[i][1];

            vector<int> pre = res.back();

            if (pre[1] >= a || pre[1] + 1 >= a) {
                res.pop_back();
                if (pre[1] < b)
                    pre[1] = b;
                res.push_back(pre);
            } else {
                res.push_back({a, b});
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < res.size(); i++) {
            int a = res[i][0];
            int b = res[i][1];

            if (b < freeStart || a > freeEnd) {
                ans.push_back(res[i]);
            } else {

                if (a < freeStart) {
                    ans.push_back({a, freeStart - 1});
                }
                if (b > freeEnd) {
                    ans.push_back({freeEnd + 1, b});
                }
            }
        }

        return ans;
    }
};