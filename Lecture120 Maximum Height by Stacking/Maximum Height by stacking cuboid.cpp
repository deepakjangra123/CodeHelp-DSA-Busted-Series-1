class Solution {
public:

    bool check(vector<int>base, vector<int>newBase){
        if(newBase[0] <= base[0] && newBase[1] <= base[1] && newBase[2] <= base[2])
            return true;
        else 
            return false; 
    }
    int solve(int n, vector<vector<int>>& cuboids){
        
        vector<int>currRow(n+1, 0);
        vector<int>nextRow(n+1, 0);
        
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){

                //include
                int take = 0;
                if(prev ==  -1 || check(cuboids[curr], cuboids[prev]))
                    take = cuboids[curr][2] + nextRow[curr+1];
                    
                //exclude
                int notTake = 0 + nextRow[prev+1];
                currRow[prev+1] = max(take, notTake); 
                
            }
            nextRow= currRow;
        }
        return nextRow[0];


    }
    int maxHeight(vector<vector<int>>& cuboids) {
        //step 1 : sort all dimensions for every cuboid
        for(auto &a : cuboids){
            sort(a.begin(), a.end());
        }

        //step 2 : sort all cuboids basis on w or l
        sort(cuboids.begin(), cuboids.end());

        //step 3 : use LIS logic
        return solve(cuboids.size(), cuboids);
    }
};