/* Morris±éÀú */
#pragma once
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

#include <vector>
using std::vector;

vector<int> MorrisInorderTraverse(TreeNode* root);
vector<int> MorrisPreorderTraverse(TreeNode* root);
vector<int> MorrisPostorderTraverse(TreeNode* root);
