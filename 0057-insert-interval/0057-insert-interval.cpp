class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> pre = res.back();
            int a = intervals[i][0];
            int b = intervals[i][1];

            if (pre[1] >= a) {
                res.pop_back();
                if (pre[1] < b)
                    pre[1] = b;
                res.push_back(pre);
            } else {
                res.push_back({a, b});
            }
        }
        return res;
    }
};