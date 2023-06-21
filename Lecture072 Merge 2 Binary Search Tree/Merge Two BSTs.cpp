											Optimised Approach

#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void convertIntoSortedDLL(TreeNode<int> *root, TreeNode<int>* &head){
    //base case
    if(root == NULL){
        return;
    }

    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;
    convertIntoSortedDLL(root->left, head);
}
// Merging two doubly sorting linked list
TreeNode<int>* mergeLinkedList(TreeNode<int>* head1, TreeNode<int>* head2){
    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = NULL;
 // merging two dobuly linked list 
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
// checking weither the head NULL or not
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
 // checking weither the head NULL or not
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;                
            }
        }
    }
// confirming weither the head1 NULL or not, if not then merge into final linked list
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
 // confirming weither the head2 NULL or not, if not then merge into final linked list
    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2= head2->right;
    }
    return head;
}
// finding the length of SortedDLL
int countNodes(TreeNode<int>* head){
    int cnt = 0;
    TreeNode<int>* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
// converting SortedLLToBST
TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int  n){
    //base case
    if(n <= 0 || head == NULL){
        return NULL;
    }
    TreeNode<int>* left = sortedLLToBST(head, n/2);
    TreeNode<int>* root = head;
    root->left = left;
    head = head->right;
    root->right = sortedLLToBST(head, n-n/2-1);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    //step1 : Convert BST into sorted DLL IN-Place
    TreeNode<int>* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode<int>* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    //step2 : Merge sorted LL
    TreeNode<int>* head = mergeLinkedList(head1, head2);

    //step3 : convert SLL into BST
    return sortedLLToBST(head, countNodes(head));
}


											Approach 1
#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL){
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> &in){
    // base case
    if(s>e){
        return NULL;
    }

    int mid = (e-s)/2 + s;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST(mid+1, e, in);
    return root;

}

vector<int> mergeArrays(vector<int> &a, vector<int> &b){
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            ans[k] = a[i];
            i++;
            k++;
        }
        else{
            ans[k] = b[j];
            j++;
            k++;
        }
    }
    while(i < a.size()){
        ans[k] = a[i];
        i++;
        k++;
    }
    while(j < b.size()){
        ans[k] = b[j];
        j++;
        k++;
    }
    return ans;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
   //step 1 store inorder
   vector<int> bst1;
   vector<int> bst2;
   inorder(root1, bst1);
   inorder(root2, bst2);

   //step 2  : Merge Both sorted Array
   vector<int> mergeArray = mergeArrays(bst1, bst2);
    
    // step 3 : use merged inorder array to buil BST
    int s = 0, e = mergeArray.size()-1;
    return inorderToBST(s, e, mergeArray);
}