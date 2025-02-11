#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.empty())
            return nullptr;
        TreeNode *root = new TreeNode(postorder.back());
        int indexRoot = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        vector<int> leftIn(inorder.begin(), inorder.begin() + indexRoot);
        vector<int> rightIn(inorder.begin() + indexRoot + 1, inorder.end());
        vector<int> leftPost(postorder.begin(), postorder.begin() + indexRoot);
        vector<int> rightPost(postorder.begin() + indexRoot, postorder.end() - 1);
        root->left = buildTree(leftIn, leftPost);
        root->right = buildTree(rightIn, rightPost);
        return root;
    }
};