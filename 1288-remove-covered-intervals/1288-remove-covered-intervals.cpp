class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1]; // same start -> larger end first
        return a[0] < b[0];     // otherwise smaller start first
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int n = intervals.size();
        int l = intervals[0][0];
        int h = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (h >= intervals[i][1]) {
                n--;
            } else {
                l = intervals[i][0];
                h = intervals[i][1];
            }
        }

        return n;
    }
};