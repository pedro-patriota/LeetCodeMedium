#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
}

int main()
{
}
