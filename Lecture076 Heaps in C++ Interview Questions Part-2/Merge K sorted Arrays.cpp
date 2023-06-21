#include <bits/stdc++.h> 
class node{
    public:
    int data;
    int row;
    int col;

    node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare{
    public:
    bool operator()(node*a, node*b){
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare>minHeap;

    //step1: saare arrays k first element insert kro
    for(int i=0; i<k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }
    vector<int> ans;

    //step 2
    while(minHeap.size()>0){

        node* top = minHeap.top();
        ans.push_back(top->data);
        minHeap.pop();

        int i = top->row;
        int j = top->col;

        if(j+1<kArrays[i].size()){
            node* next = new node(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    return ans;
}
