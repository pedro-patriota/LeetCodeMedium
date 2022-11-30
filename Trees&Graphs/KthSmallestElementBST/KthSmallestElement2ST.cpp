#include <iostream>
using namespace std;
#include <vector>
#include <stack>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int kthSmallest(TreeNode* root, int k) {
  
    stack<TreeNode*> counter;
    int j = 0;
    
    while (true){
        while (root != NULL){
            counter.push(root);
            root= root->left;
        }
        root = counter.top();
        counter.pop();
        if (--k == 0){
            return root->val;
        }
        root = root->right;
    }

    
    
}

int main(){
    TreeNode* a = new TreeNode(2);
    a->left= new TreeNode(1);
    //a->right = new TreeNode(2);
    cout << kthSmallest(a, 1);

    return 0;
}