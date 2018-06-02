#include "MorrisTraverse.h"

int main() {
    TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(6, new TreeNode(5), new TreeNode(7)));
    MorrisInorderTraverse(root);
    MorrisPreorderTraverse(root);
    MorrisPostorderTraverse(root);
}