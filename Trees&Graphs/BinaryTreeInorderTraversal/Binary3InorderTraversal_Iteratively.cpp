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

vector<int> inorderTraversal(TreeNode *root)
{ //  2 <- 3 -< 4* -> 3
    if (root == nullptr)
    {
        return {};
    }
    TreeNode *curr = root;
    TreeNode *temp;
    stack<TreeNode *> s;
    s.push(NULL);
    vector<int> counter;
    while (!s.empty())
    {
        if (curr->left)
        {
            if (curr->left->val != -101)
            {
                s.push(curr);
                curr = curr->left;
                continue;
            }
            else
            {
                counter.push_back(curr->val);
            }
        }
        else
        {
            counter.push_back(curr->val);
        }

        if (curr->right)
        {
            if (curr->right->val != -101)
            {
                temp = curr->right;
                curr->val = -101;
                curr = temp;
                continue;
            }
            else
            {
                curr->val = -101;
                curr = s.top();
                s.pop();
            }
        }
        else
        {   
            curr->val = -101;
            curr = s.top();
            s.pop();
        }
    }
    return counter;
}

int main()
{
    // Inorder traversal = L, S, R
    TreeNode *z = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *n = new TreeNode(3, z, b);

    inorderTraversal(n);
}