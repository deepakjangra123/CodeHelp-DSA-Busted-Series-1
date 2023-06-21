														//Recursion -- TLE


class Solution {
public:
    int solve(int index, int buy, vector<int>& prices){
        if(index == prices.size())
            return 0;
        
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solve(index+1, 0, prices);
            int skipKaro = 0 + solve(index+1, 1, prices);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[index] + solve(index+1, 1, prices);
            int skipKaro = 0 + solve(index+1, 0, prices);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0, 1, prices);
    }
};

																//Memoization

class Solution {
public:
    int solveMem(int index, int buy, vector<int>& prices, vector<vector<int>>&dp){
        if(index == prices.size())
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];
        
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveMem(index+1, 0, prices, dp);
            int skipKaro = 0 + solveMem(index+1, 1, prices, dp);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[index] + solveMem(index+1, 1, prices, dp);
            int skipKaro = 0 + solveMem(index+1, 0, prices, dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return solveMem(0, 1, prices, dp);
    }
};


												//Tabulation

class Solution {
public:
    int solveTab(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));

        for(int index = n-1; index >= 0; index-- ){
            for(int buy = 0; buy <= 1; buy++){

                int profit = 0;
                if(buy){
                    int buyKaro = -prices[index] + dp[index+1][0];
                    int skipKaro = 0 + dp[index+1][1];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[index] + dp[index+1][1];
                    int skipKaro = 0 + dp[index+1][0];
                    profit = max(sellKaro, skipKaro);
                }
                dp[index][buy] = profit;
            }
        }
        
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        return solveTab(prices);
    }
};

														//Space Optimization
														
class Solution {
public:
    int solveTab(vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int index = n-1; index >= 0; index-- ){
            for(int buy = 0; buy <= 1; buy++){

                int profit = 0;
                if(buy){
                    int buyKaro = -prices[index] + next[0];
                    int skipKaro = 0 + next[1];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[index] + next[1];
                    int skipKaro = 0 + next[0];
                    profit = max(sellKaro, skipKaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        return solveTab(prices);
    }
};																																										