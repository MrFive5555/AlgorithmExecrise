#pragma once

#pragma once
#include <algorithm>

template<typename T>
class SplayTree {
public:
    SplayTree() : root(nullptr) {}
    T splay(T target);
    void pre_traverse();
private:
    struct Node {
        T val;
        Node* left;
        Node* right;
        Node(T val, Node* left = nullptr, Node* right = nullptr)
            : val(val), left(left), right(right) {
        }
    };
    Node* root;

    void left_rotate(Node* &root);
    void right_rotate(Node* &root);

    void link_right(Node* &current, Node* &first_large);
    void link_left(Node* &current, Node* &last_small);

    void pre(Node* root);

    int depth(Node* root) {
        if (!root) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        if (abs(left - right) > 1) {
            throw 111;
        }
        if (root->left && root->left->val >= root->val) {
            throw 1;
        }
        if (root->right && root->right->val <= root->val) {
            throw 2;
        }
        return max(left, right) + 1;
    }
};

template<typename T>
T SplayTree<T>::splay(T target) {
    Node dummyNode(target);
    Node* dummy = &dummyNode;
    Node* current = root;
    Node* last_small = dummy;
    Node* first_large = dummy;

    while (current != nullptr && current->val != target) {
        if (target < current->val) {
            Node* child = current->left;
            if (!child || child->val == target) {
                link_right(current, first_large);
            } else if (target < child->val) {
                right_rotate(current);
                link_right(current, first_large);
            } else {
                link_right(current, first_large);
                link_left(current, last_small);
            }
        } else {
            Node* child = current->right;
            if (!child || child->val == target) {
                link_left(current, last_small);
            } else if (target > child->val) {
                left_rotate(current);
                link_left(current, last_small);
            } else {
                link_left(current, last_small);
                link_right(current, first_large);
            }
        }

    }
    if (!current) {
        current = new Node(target);
    }
    last_small->right = current->left;
    first_large->left = current->right;
    current->right = dummy->left;
    current->left = dummy->right;
    root = current;
    return root->val;
}

template<typename T>
void SplayTree<T>::pre_traverse() {
    pre(root);
    cout << endl;
}

template<typename T>
void SplayTree<T>::right_rotate(Node* &root) {
    Node* lNode = root->left;
    root->left = root->left->right;
    lNode->right = root;
    root = lNode;
}

template<typename T>
void SplayTree<T>::left_rotate(Node* &root) {
    Node* rNode = root->right;
    root->right = root->right->left;
    rNode->left = root;
    root = rNode;
}

template<typename T>
void SplayTree<T>::link_left(Node* &current, Node* &last_small) {
    last_small->right = current;
    last_small = current;
    current = current->right;
}

template<typename T>
void SplayTree<T>::link_right(Node* &current, Node* &first_large) {
    first_large->left = current;
    first_large = current;
    current = current->left;
}

template<typename T>
void SplayTree<T>::pre(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    pre(root->left);
    pre(root->right);
}