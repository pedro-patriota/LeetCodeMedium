#include <iostream>
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
using namespace std;

void RecursiveInorder(TreeNode *root, vector<int>& A)
{
    if (root == NULL)
    {
        return;
    }
    RecursiveInorder(root->left, A);
    A.push_back(root->val);
    RecursiveInorder(root->right, A);
}

vector<int> inorderTraversal(TreeNode *root)
{ //  2 <- 3 -< 4* -> 3
    vector<int> ans;
    RecursiveInorder(root, ans);
    return ans;
}

int main()
{
    // Inorder traversal = L, S, R
    TreeNode *z = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *n = new TreeNode(3, z, b);

    inorderTraversal(n);
}