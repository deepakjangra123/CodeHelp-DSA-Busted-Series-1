												//Recursion
class Solution {
public:

    int solve(int index, int endIndex, vector<int> & slices, int n){
        //base case
        if(n == 0 || index> endIndex){
            return 0;
        }

        int take = slices[index] + solve(index + 2, endIndex, slices, n-1);
        int notTake = 0 + solve(index + 1, endIndex, slices, n);
        return max(take, notTake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int case1 = solve(0, k-2, slices, k/3);
        int case2 = solve(1, k-1, slices, k/3);
        return max(case1, case2);
    }
};


											//Memoization
											
class Solution {
public:

    int solveMem(int index, int endIndex, vector<int> & slices, int n, vector<vector<int>> &dp){
        //base case
        if(n == 0 || index> endIndex){
            return 0;
        }

        if(dp[index][n] != -1)
            return dp[index][n];

        int take = slices[index] + solveMem(index + 2, endIndex, slices, n-1, dp);
        int notTake = 0 + solveMem(index + 1, endIndex, slices, n, dp);
        return dp[index][n] = max(take, notTake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();

        vector<vector<int>>dp1(k, vector<int>(k, -1));
        vector<vector<int>>dp2(k, vector<int>(k, -1));

        int case1 = solveMem(0, k-2, slices, k/3, dp1);
        int case2 = solveMem(1, k-1, slices, k/3, dp2);
        return max(case1, case2);
    }
};

														//Tabulation
														
class Solution {
public:

    int solveTab(vector<int>& slices){
        int k = slices.size();
        vector<vector<int>>dp1(k+2, vector<int>(k, 0));
        vector<vector<int>>dp2(k+2, vector<int>(k, 0));

        for(int index = k-2; index >= 0; index--){
            for(int n = 1; n <= k/3; n++){
                int take = slices[index] + dp1[index + 2][n - 1];
                int notTake = 0 + dp1[index + 1][n];
                dp1[index][n] = max(take, notTake);
            }
        }
        
        int case1 = dp1[0][k/3];

        for(int index = k-1; index >= 1; index--){
            for(int n = 1; n <= k/3; n++){
                int take = slices[index] + dp2[index + 2][n - 1];
                int notTake = 0 + dp2[index + 1][n];
                dp2[index][n] = max(take, notTake);
            }
        }
        int case2 = dp2[1][k/3];

        return max(case1, case2);
    }
    int maxSizeSlices(vector<int>& slices) {

        return solveTab(slices);
    }
};



														//Space Optimization
class Solution {
public:

    int solveTab(vector<int>& slices){
        int k = slices.size();
        vector<int>prev1(k+2, 0);
        vector<int>curr1(k+2, 0);
        vector<int>next1(k+2, 0);

        vector<int>prev2(k+2, 0);
        vector<int>curr2(k+2, 0);
        vector<int>next2(k+2, 0);


        for(int index = k-2; index >= 0; index--){
            for(int n = 1; n <= k/3; n++){
                int take = slices[index] + next1[n - 1];
                int notTake = 0 + curr1[n];
                prev1[n] = max(take, notTake);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        
        int case1 = curr1[k/3];

        for(int index = k-1; index >= 1; index--){
            for(int n = 1; n <= k/3; n++){
                int take = slices[index] + next2[n - 1];
                int notTake = 0 + curr2[n];
                prev2[n] = max(take, notTake);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[k/3];

        return max(case1, case2);
    }
    int maxSizeSlices(vector<int>& slices) {

        return solveTab(slices);
    }
};													