class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if ((totalSum + target) % 2 != 0 
                || abs(target) > totalSum) {
                    return 0;
        }
        
        int reqSum = (totalSum + target) / 2;
        
        if (reqSum < 0) {
            return 0;
        }

        vector<int> dp(reqSum + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int j = reqSum; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }

        return dp[reqSum];
    }
};
