														//Recursion

class Solution {
public:
    int numTrees(int n) {
        if( n <= 1)
            return 1;
        
        int ans = 0;
        
        //think i as root node
        for(int i = 1; i <= n; i++){
            ans += numTrees(i-1) * numTrees(n-i);
        }

        return ans;
    }
};


														//Memoization
														
class Solution {
public:

    int solveMem(int n, vector<int> &dp){

        //base case
        if(n <= 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];

        int ans = 0;

        //think i as root node
        for(int i = 1; i <= n; i++){
            ans += solveMem(i-1, dp) * solveMem(n-i, dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int>dp(n+1, -1);
        return solveMem(n, dp);
    }
};




														//Tabulation
														
class Solution {
public:

    int solveTab(int n){

        vector<int> dp(n+1, 0);

        //base case
        dp[0] = dp[1] = 1;

        // i -> number of nodes
        for(int i =2; i <= n; i++){

            //j -> root node
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j-1]* dp[i-j]; 
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        return solveTab(n);
    }
};





                                 					//	OPTIMIZATION --????
													//  CAN BE SOLVED USING CATALAN NUMBER																											