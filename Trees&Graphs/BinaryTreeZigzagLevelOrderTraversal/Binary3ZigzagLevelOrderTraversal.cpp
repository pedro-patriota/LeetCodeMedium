#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using namespace std;

void RecursiveInorder(TreeNode *root, map<int, vector<int>>& A, int height){
    if (root == NULL){
        return;
    }
    RecursiveInorder(root->right, A, height+1);
    RecursiveInorder(root->left, A, height+1);
    A[height].push_back(root->val);
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    map<int, vector<int>>A;
    vector<vector<int>>V;
    RecursiveInorder(root, A, 0);
    map<int, vector<int>> :: iterator it;

    int a = 0;
    for (it = A.begin(); it != A.end(); ++it){
        if (a%2 == 1){
            V.push_back(it->second);

        }else{
            reverse(it->second.begin(), it->second.end());
            V.push_back(it->second);
        }
        a++;
    }

    return V;
}

int main(){
    // Zigzag traversal = L, S, R
    TreeNode *z = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *n = new TreeNode(3, z, b);

    zigzagLevelOrder(n);
}