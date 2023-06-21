#include<limits.h>
#include<queue>

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
      bool operator()(node* a, node* b) { 
          return a->data > b->data;
          }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<node*, vector<node*>, compare>minHeap;

    //step 1: Create a min Heap for starting element of each list and tracking mini/maxi value
    for(int i=0; i<k; i++){
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);

        minHeap.push(new node(element,i,0));
    }

    int start = mini, end = maxi;

    //process ranges
    while(!minHeap.empty()){
        //min Fetch
        node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;

        //range of answer updation
        if(maxi-mini < end - start){
            start = mini;
            end = maxi;
        }

        //next element exists
        if(temp->col+1 < n){
            maxi = max(maxi, a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1], temp->row, temp->col+1));
        }

        else { // next element does not exist
          break;
        }
    }
        //returning the difference of range value 
        return (end - start + 1);
}