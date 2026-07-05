class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)return true;
        if(n % 2 != 1)return false;
        int mid = nums[n / 2];

        int cnt = 0;
        for(int i = 0; i < n; i++){
            
            if(mid == nums[i]){
                   cnt++;
            }
            if(cnt > 1)return false;
        }
        return true;
    }
};