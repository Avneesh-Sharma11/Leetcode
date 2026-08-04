class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 1; i < nums.size(); i++) {
            int s = nums[i - 1];
            int e = nums[i];

            if (e - s > 1) {
                s += 1;
                while (s < e) {
                    res.push_back(s);
                    s++;
                }
            }
        }
        return res;
    }
};