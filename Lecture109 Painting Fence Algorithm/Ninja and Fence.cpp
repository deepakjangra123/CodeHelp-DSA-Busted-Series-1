														//Recursion

#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return((a%MOD) * (b%MOD))%MOD;
}
int solveRec(int n, int k){
    //base case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return add(k, mul(k, k-1));
    }   
    int ans = add(mul(solveRec(n-2, k), k-1), mul(solveRec(n-1, k), k-1));
    return ans;

}
int numberOfWays(int n, int k) {
    return solveRec(n, k);
}

													//Recursion + Memoization

#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return(((a%MOD)*1LL) * ((b%MOD)*1LL))%MOD;
}
int solveMem(int n, int k, vector<int>&dp){
    //base case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return add(k, mul(k, k-1));
    }   
    if(dp[n] != -1)
        return dp[n];
    
    dp[n] =  add((mul(solveMem(n-2, k, dp), k-1)), ((mul(solveMem(n-1, k, dp), k-1))));
    return dp[n];

}
int numberOfWays(int n, int k) {
    vector<int>dp(n+1, -1);
    return solveMem(n, k, dp);
}

													//Tabulation
													
#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return(((a%MOD)*1LL) * ((b%MOD)*1LL))%MOD;
}
int solveTab(int n, int k){
    vector<int>dp(n+1, -1);
    dp[1] = k; 
    dp[2] = add(k, mul(k, k-1));

    for (int i=3; i<=n; i++){
        dp[i] = add( (mul(dp[i-2], k-1)), (mul(dp[i-1], k-1)) );
    }
    return dp[n];

}
int numberOfWays(int n, int k) {
    return solveTab(n, k);
}


											//space optimization
											
#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return(((a%MOD)*1LL) * ((b%MOD)*1LL))%MOD;
}
int solveSO(int n, int k){
    int prev2 = k; 
    int prev1= add(k, mul(k, k-1));

    for (int i=3; i<=n; i++){
        int ans = add( (mul(prev2, k-1)), (mul(prev1, k-1)) );
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;

}
int numberOfWays(int n, int k) {
    return solveSO(n, k);
}

