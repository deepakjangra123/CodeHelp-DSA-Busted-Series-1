										//Recursion
class Solution {
public:
    int solve(vector<int>&cost, int n){
        //base case
        if(n == 0)
            return cost[0];
        if(n == 1)
            return cost[1];
            
            int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
            return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //it can be simplified more -> Homework
        int ans = min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
};
										
										//Recursion + Memoziation

class Solution {
public:
    int solveMem(vector<int>&cost, int n, vector<int>&dp){
        //base case
        if(n == 0)
            return cost[0];
        if(n == 1)
            return cost[1];

        //step 3
        if(dp[n] != -1)
            return dp[n];

        //step 2
        dp[n] = cost[n] + min(solveMem(cost, n-1, dp), solveMem(cost, n-2, dp));
        return dp[n];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        int ans = min(solveMem(cost, n-1, dp), solveMem(cost, n-2, dp));
        return ans;
    }
};

										//Tabulation
										
class Solution {
public:
    int solveTab(vector<int>&cost, int n){
        //step 1: Creation of array
        vector<int>dp(n+1);
        //step 2: Base case analyze
        dp[0] = cost[0];
        dp[1] = cost[1];

        //step 3:
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solveTab(cost, n);
    }
};


										//Space Optimization
										
class Solution {
public:
    int solveOpt(vector<int>&cost, int n){
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2; i<n; i++){
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solveOpt(cost, n);
    }
};