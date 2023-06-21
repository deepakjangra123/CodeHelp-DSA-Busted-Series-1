														//recursion

class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){
        //base case
        if(index == nums1.size()){
            return 0;
        }

        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        //catch
        if(swapped == 1)
            swap(prev1, prev2);

        //no swap
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index+1, 0);
        

        //swap
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1+solve(nums1, nums2, index+1, 1));

        return ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        //it means that the previous indexes were swapped
        bool swapped = 0;
        return solve(nums1, nums2, 1, swapped);
    }


};


													//Memoization
													

class Solution {
public:

    int solveMem(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>> &dp){
        //base case
        if(index == nums1.size()){
            return 0;
        }

        if(dp[index][swapped] != -1)
            return dp[index][swapped];

        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        //catch
        if(swapped == 1)
            swap(prev1, prev2);

        //no swap
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solveMem(nums1, nums2, index+1, 0, dp);
        

        //swap
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1+solveMem(nums1, nums2, index+1, 1, dp));

        return dp[index][swapped] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        //it means that the previous indexes were swapped
        bool swapped = 0;
        int n = nums1.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return solveMem(nums1, nums2, 1, swapped, dp);
    }


};


															//Tabulation


class Solution {
public:

    int solveTab(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        vector<vector<int>>dp(n+1, vector<int>(2,0));

        for(int index = n-1; index >= 1; index--){
            for(int swapped = 1; swapped >= 0; swapped--){
                int ans = INT_MAX;
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                //catch
                if(swapped == 1)
                    swap(prev1, prev2);

                //no swap
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index+1][0];
                
                //swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1+dp[index+1][1]);

                dp[index][swapped] = ans;
            }
        }

        return dp[1][0];

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        return solveTab(nums1, nums2);
    }


};



															//Space Optimization
															
class Solution {
public:

    int solveSO(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int swap = 0;
        int noswap = 0;
        int currswap = 0;
        int currnoswap = 0;

        for(int index = n-1; index >= 1; index--){
            for(int swapped = 1; swapped >= 0; swapped--){
                int ans = INT_MAX;
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                //catch
                if(swapped == 1){
                    int temp = prev2;
                    prev2 = prev1;
                    prev1 = temp;
                }

                //no swap
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = noswap;
                
                //swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1+swap);

                if(swapped)
                    currswap = ans;
                
                else{
                    currnoswap = ans;
                }
            }
                swap = currswap;
                noswap = currnoswap;
        }

        return min(swap, noswap);

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        return solveSO(nums1, nums2);
    }


};
															