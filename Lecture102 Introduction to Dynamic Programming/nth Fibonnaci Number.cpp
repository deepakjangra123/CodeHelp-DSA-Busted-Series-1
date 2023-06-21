										//Recursion
#include<bits/stdc++.h>
using namespace std;

int fib(int n){
        //base case
        if(n<=1)
                return n;

        int ans = fib(n-1) + fib(n-2);
        return ans;
}
int main()
{
        int n;
        cin>>n;

        cout<<fib(n)<<endl;

}

										//Recursion + Memoization

#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>&dp){
        //base case
        if(n<=1)
                return n;
        if(dp[n] != -1)
                return dp[n];
        
        dp[n] = fib(n-1, dp) + fib(n-2, dp);
        return dp[n];
}
int main()
{
        int n;
        cin>>n;
        vector<int>dp(n+1);
        for(int i=0; i<=n; i++){
                dp[i] = -1;
        }
        cout<<fib(n, dp)<<endl;

}

									//Tabulation
#include<bits/stdc++.h>
using namespace std;


int main()
{
        int n;
        cin>>n;

        //step 1
        vector<int>dp(n+1);
 
        //step 2
        dp[1] = 1;
        dp[0] = 0;

        //step 3
        for(int i=2; i<=n; i++)
                dp[i] = dp[i-1] + dp[i-2];
        cout<<dp[n]<<endl;

}

										//Space optimization
	#include<bits/stdc++.h>
using namespace std;


int main()
{
        int n;
        cin>>n;

        int prev1 = 1;
        int prev2 = 0;
        if(n == 0)
                return prev2;

        for (int i = 2; i <= n; i++) {
          int curr = prev1 + prev2;

          // shift logic
          prev2 = prev1;
          prev1 = curr;
        }
        cout<<prev1<<endl;
        return 0;
}