class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();

        vector<int> dp(amount+1, 100000);
        dp[0] = 0;

        for(int i=1 ; i<=amount ; i++){
            for(int j=0 ; j<len ; j++){
                int leftAmount = i - coins[j];
                if(leftAmount < 0) continue;
                dp[i] = min(dp[i], 1+dp[leftAmount]);
            }
        }

        return dp[amount] < 100000 ? dp[amount] : -1;
    }
};