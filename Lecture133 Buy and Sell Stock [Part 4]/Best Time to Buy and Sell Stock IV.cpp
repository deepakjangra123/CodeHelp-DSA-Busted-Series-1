														// Optimized Solution with previous approach

class Solution {
public:
        int solveSO(vector<int> &prices, int k){
        int n = prices.size();
        vector<vector<int>>curr(2, vector<int>(k+1, 0));
        vector<vector<int>>next(2, vector<int>(k+1, 0));

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <= k; limit++){
                                
                    int profit = 0;
                    if(buy){
                        int buyKaro = -prices[index] + next[0][limit];
                        int skipKaro = 0 + next[1][limit];
                        profit = max(buyKaro, skipKaro);
                    }
                    else{
                        int sellKaro = prices[index] + next[1][limit -1];
                        int skipKaro = 0 + next[0][limit];
                        profit = max(sellKaro, skipKaro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solveSO(prices, k);
    }
};



								// Recursive Solution for second approach (Transaction Approach) -- TLE
								
class Solution {
public :
    int solve(int index, int operationNo, int k, vector<int>& prices){
        if(index == prices.size())
            return 0;
        
        if(operationNo == 2*k)
            return 0;
        
        int profit = 0;
        if(operationNo % 2 == 0){
            //buy allowed
            int buyKaro = -prices[index] + solve(index+1, operationNo+1, k, prices);
            int skipKaro = 0 + solve(index+1, operationNo, k, prices);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[index] + solve(index+1, operationNo+1, k ,prices);
            int skipKaro = 0 + solve(index+1, operationNo, k, prices);
            profit = max(sellKaro , skipKaro);
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(0, 0, k, prices);
    }
};


											//Memoization

class Solution {
public :
    int solveMem(int index, int operationNo, int k, vector<int>& prices, vector<vector<int>>&dp){
        if(index == prices.size())
            return 0;
        
        if(operationNo == 2*k)
            return 0;
        
        if(dp[index][operationNo] != -1)
            return dp[index][operationNo];
        
        int profit = 0;
        if(operationNo % 2 == 0){
            //buy allowed
            int buyKaro = -prices[index] + solveMem(index+1, operationNo+1, k, prices, dp);
            int skipKaro = 0 + solveMem(index+1, operationNo, k, prices, dp);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[index] + solveMem(index+1, operationNo+1, k ,prices, dp);
            int skipKaro = 0 + solveMem(index+1, operationNo, k, prices, dp);
            profit = max(sellKaro , skipKaro);
        }
        return dp[index][operationNo] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n, vector<int>(2*k, -1));
        return solveMem(0, 0, k, prices, dp);
    }
};


													//Tabulation

class Solution {
public :
    int solveTab(int k, vector<int>& prices){
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));

        for(int index = n-1; index >= 0; index--){
            for(int operationNo = 0; operationNo < 2*k; operationNo++){
                int profit = 0;
                if(operationNo % 2 == 0){
                    //buy allowed
                    int buyKaro = -prices[index] + dp[index+1][operationNo+1];
                    int skipKaro = 0 + dp[index+1][operationNo];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[index] + dp[index+1][operationNo+1];
                    int skipKaro = 0 + dp[index+1][operationNo];
                    profit = max(sellKaro , skipKaro);
                }
                dp[index][operationNo] = profit;
            }
        }
        return dp[0][0];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solveTab(k, prices);
    }
};


 															//Space Optimization


class Solution {
public :
    int solveSO(int k, vector<int>& prices){
        int n = prices.size();
        vector<int>curr(2*k+1, 0);
        vector<int>next(2*k+1, 0);

        for(int index = n-1; index >= 0; index--){
            for(int operationNo = 0; operationNo < 2*k; operationNo++){
                int profit = 0;
                if(operationNo % 2 == 0){
                    //buy allowed
                    int buyKaro = -prices[index] + next[operationNo+1];
                    int skipKaro = 0 + next[operationNo];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[index] + next[operationNo+1];
                    int skipKaro = 0 + next[operationNo];
                    profit = max(sellKaro , skipKaro);
                }
                curr[operationNo] = profit;
            }
            next = curr;
        }
        return next[0];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solveSO(k, prices);
    }
};

															 																								