class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b){
    if (a[0] == b[0]){
        return a[1] > b[1];
        }
        return a[0] < b[0];
        }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> ans;
        for (int i = 0; i < n; i++){
            int val = envelopes[i][1];
            int index = lower_bound(ans.begin(), ans.end(), val) - ans.begin();

            if (index >= ans.size()){
                ans.push_back(val);
            }
            else
            {
                ans[index] = val;
            }
        }
        return ans.size();
    }
};