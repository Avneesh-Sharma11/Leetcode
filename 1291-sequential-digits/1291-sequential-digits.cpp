class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        deque<int> q;

        for (int i = 1; i < 9; i++)
            q.push_back(i);

        vector<int> res;

        while (!q.empty()) {
            int x = q.front();
            q.pop_front();
            if (x >= low && x <= high)
                res.push_back(x);

            int ld = x % 10;
            if (ld + 1 < 10) {
                int num = x * 10 + ld + 1;
                q.push_back(num);
            }
        }

        return res;
    }
};