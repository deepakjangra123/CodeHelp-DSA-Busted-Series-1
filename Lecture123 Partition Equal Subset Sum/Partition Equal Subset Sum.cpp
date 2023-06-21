

																	//Recursion

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve(int index, int arr[], int N, int target){
        // base case
        if(index >= N)
            return 0;
        
        if(target < 0)
            return 0;
            
        if(target == 0)
            return 1;
            
        bool incl = solve(index + 1, arr, N, target - arr[index]);
        bool excl = solve(index +1, arr, N, target - 0);
        
        return incl or excl;
    }
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i=0; i<N; i++){
            total += arr[i];
        }
        if(total & 1)
            return 0;
            
        int target = total/2;
        return solve(0, arr, N, target);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends


																		//Memoization
																		
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solveMem(int index, int arr[], int N, int target, vector<vector<int>> &dp){
        // base case
        if(index >= N)
            return 0;
        
        if(target < 0)
            return 0;
            
        if(target == 0)
            return 1;
            
        if(dp[index][target] != -1)
            return dp[index][target];
            
        bool incl = solveMem(index + 1, arr, N, target - arr[index], dp);
        bool excl = solveMem(index +1, arr, N, target - 0, dp);
        
        return dp[index][target] = incl or excl;
    }
    
    
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i=0; i<N; i++){
            total += arr[i];
        }
        if(total & 1)
            return 0;
            
        int target = total/2;
        
        vector<vector<int>>dp(N, vector<int>(target+1, -1));
        return solveMem(0, arr, N, target, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends


										//Tabulation



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool solveTab(int N, int arr[], int total){
        
        vector<vector<int>>dp(N+1, vector<int>(total/2 +1, 0));
        
        for(int i = 0; i<=N; i++){
            dp[i][0] = 1;
        }
        
        for(int index = N-1; index >= 0; index--){
            for(int target = 0; target <= total/2; target++){
                bool incl = 0;
                if(target - arr[index] >= 0)
                    incl = dp[index+1][target - arr[index]];
                
                bool excl = dp[index + 1][target-0];
                
                dp[index][target] = incl or excl;
            }
        }
        
        
        return dp[0][total/2];
    }
    
    
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i=0; i<N; i++){
            total += arr[i];
        }
        if(total & 1)
            return 0;
            
        int target = total/2;
        
        return solveTab(N, arr, total);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends



												//Space Optimization
												


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool solveSO(int N, int arr[], int total){
        
        vector<int>curr(total/2 + 1, 0);
        vector<int>next(total/2 + 1, 0);
        
        curr[0] = 1;
        next[0] = 1;
        
        for(int index = N-1; index >= 0; index--){
            for(int target = 0; target <= total/2; target++){
                bool incl = 0;
                if(target - arr[index] >= 0)
                    incl = next[target - arr[index]];
                
                bool excl = next[target-0];
                curr[target] = incl or excl;
            }
            next = curr;
        }
        return next[total/2];
    }
    
    
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i=0; i<N; i++){
            total += arr[i];
        }
        if(total & 1)
            return 0;
            
        int target = total/2;
        
        return solveSO(N, arr, total);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends