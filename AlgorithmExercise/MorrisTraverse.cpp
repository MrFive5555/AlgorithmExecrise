#include "MorrisTraverse.h"

vector<int> MorrisInorderTraverse(TreeNode* root) {
    vector<int> ret;
    TreeNode* curNode = root;
    while (curNode) {
        TreeNode* mostRight = curNode->left;
        if (curNode->left) {
            while (mostRight->right && mostRight->right != curNode) {
                mostRight = mostRight->right;
            }
            if (!mostRight->right) {
                mostRight->right = curNode;
                curNode = curNode->left;
                continue;
            } else {
                mostRight->right = nullptr;
            }
        }
        ret.push_back(curNode->val);
        curNode = curNode->right;
    }
    return ret;
}

vector<int> MorrisPreorderTraverse(TreeNode* root) {
    vector<int> ret;
    TreeNode* curNode = root;
    while (curNode) {
        TreeNode* mostRight = curNode->left;
        if (curNode->left) {
            while (mostRight->right && mostRight->right != curNode) {
                mostRight = mostRight->right;
            }
            if (!mostRight->right) {
                ret.push_back(curNode->val);
                mostRight->right = curNode;
                curNode = curNode->left;
                continue;
            } else {
                mostRight->right = nullptr;
            }
        } else {
            ret.push_back(curNode->val);
        }
        curNode = curNode->right;
    }
    return ret;
}

vector<int> MorrisPostorderTraverse(TreeNode* root) {
    vector<int> ret;
    auto printEdge = [&ret](TreeNode* root) {
        auto reverse = [](TreeNode* head) {
            TreeNode* preNode = nullptr;
            TreeNode* curNode = head;
            while (curNode) {
                TreeNode* nextNode = curNode->right;
                curNode->right = preNode;
                preNode = curNode;
                curNode = nextNode;
            }
            return preNode;
        };
        TreeNode* lastNode = reverse(root);
        for (TreeNode* ptr = lastNode; ptr; ptr = ptr->right) {
            ret.push_back(ptr->val);
        }
        reverse(lastNode);
    };
    TreeNode* curNode = root;
    while (curNode) {
        TreeNode* mostRight = curNode->left;
        if (curNode->left) {
            while (mostRight->right && mostRight->right != curNode) {
                mostRight = mostRight->right;
            }
            if (!mostRight->right) {
                mostRight->right = curNode;
                curNode = curNode->left;
                continue;
            } else {
                mostRight->right = nullptr;
                printEdge(curNode->left);
            }
        }
        curNode = curNode->right;
    }
    printEdge(root);
    return ret;
}