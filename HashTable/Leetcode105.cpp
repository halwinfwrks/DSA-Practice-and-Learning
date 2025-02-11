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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
            return nullptr;
        int rootVal = preorder[0];
        TreeNode *root = new TreeNode(rootVal);
        int rootIndex = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + rootIndex + 1);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightPreorder(preorder.begin() + rootIndex + 1, preorder.end());
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
    void printTree(TreeNode *root){
        if(root == nullptr){
            return;
        }
        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }
};



int main(int argc, char const *argv[])
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution solution;
    TreeNode *root = solution.buildTree(preorder, inorder);
    solution.printTree(root);
    return 0;
}
