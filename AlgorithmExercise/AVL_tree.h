#pragma once
#include <algorithm>

template<typename T>
class AVL_tree {
public:
    AVL_tree() : root(nullptr) {}
    bool insert(T data);
    bool remove(T data);
    bool find(T data);
    void pre_traverse();

    friend void test(AVL_tree&);
private:
    typedef enum {
        lf,
        eq,
        rg
    } Balance;
    struct Node {
        T val;
        Node* left;
        Node* right;
        Balance balance;
        Node(T val, Node* left = nullptr, Node* right = nullptr)
            : val(val), left(left), right(right), balance(eq) {
        }
    };
    Node* root;
    bool _insert(Node*& root, T val, bool& taller);
    bool _remove(Node*& root, T val, bool& shorter);
    bool _find(Node* root, T val);

    void left_balance(Node* &root);
    void right_balance(Node* &root);

    void left_rotate(Node* &root);
    void right_rotate(Node* &root);

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
bool AVL_tree<T>::insert(T data) {
    bool taller = false;
    return _insert(root, data, taller);
}

template<typename T>
bool AVL_tree<T>::remove(T data) {
    bool shorter = false;
    return _remove(root, data, shorter);
}

template<typename T>
bool AVL_tree<T>::find(T data) {
    return _find(root, data);
}

template<typename T>
void AVL_tree<T>::pre_traverse() {
    pre(root);
}

template<typename T>
bool AVL_tree<T>::_insert(Node*& root, T val, bool& taller) {
    if (!root) {
        root = new Node(val);
        taller = true;
        return true;
    }
    if (val == root->val) {
        return false;
    }
    if (val < root->val) {
        if (!_insert(root->left, val, taller)) return false;
        if (taller) {
            switch (root->balance) {
            case lf:
                left_balance(root);
                taller = false;
                break;
            case eq:
                root->balance = lf;
                break;
            case rg:
                root->balance = eq;
                taller = false;
                break;
            default:
                break;
            }
        }
    } else {
        if (!_insert(root->right, val, taller)) return false;
        if (taller) {
            switch (root->balance) {
            case lf:
                root->balance = eq;
                taller = false;
                break;
            case eq:
                root->balance = rg;
                break;
            case rg:
                right_balance(root);
                taller = false;
                break;
            default:
                break;
            }
        }
    }
    return true;
}

template<typename T>
bool AVL_tree<T>::_remove(Node*& root, T val, bool& shorter) {
    if (!root) return false;
    if (val == root->val) {
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
            shorter = true;
        } else if (!root->left || !root->right) { //只有一个孩子
            Node* temp = root;
            root = root->left ? root->left : root->right;
            delete temp;
            shorter = true;
        } else { //被删除节点的孩子不止一个
            Node* cur = root->left;
            while (cur->right) {
                cur = cur->right;
            }
            swap(cur->val, root->val);
            if (!_remove(root->left, val, shorter)) return false;
            if (shorter) {
                switch (root->balance) {
                case lf:
                    root->balance = eq;
                    break;
                case eq:
                    root->balance = rg;
                    shorter = false;
                    break;
                case rg:
                    right_balance(root);
                    break;
                default:
                    break;
                }
            }
        }
    } else if (val < root->val) {
        if (!_remove(root->left, val, shorter)) return false;
        if (shorter) {
            switch (root->balance) {
            case lf:
                root->balance = eq;
                break;
            case eq:
                root->balance = rg;
                shorter = false;
                break;
            case rg:
                right_balance(root);
                break;
            default:
                break;
            }
        }
    } else { //val > root->val
        if (!_remove(root->right, val, shorter)) return false;
        if (shorter) {
            switch (root->balance) {
            case lf:
                left_balance(root);
                break;
            case eq:
                root->balance = lf;
                shorter = false;
                break;
            case rg:
                root->balance = eq;
                break;
            default:
                break;
            }
        }
    }
    return true;
}

template<typename T>
bool AVL_tree<T>::_find(Node* root, T val) {
    if (!root) return false;
    if (root->val == val) return true;
    return _find(root->left) || _find(root->right);
}

template<typename T>
void AVL_tree<T>::left_balance(Node* &root) {
    if (root->left->balance == lf) {
        root->balance = eq;
        root->left->balance = eq;
        left_rotate(root);
    } else if (root->left->balance == rg) {
        switch (root->left->right->balance) {
        case lf:
            root->balance = rg;
            root->left->balance = eq;
            root->left->right->balance = eq;
            break;
        case rg:
            root->balance = eq;
            root->left->balance = lf;
            root->left->right->balance = eq;
            break;
        case eq:
            root->balance = eq;
            root->left->balance = eq;
            root->left->right->balance = eq;
            break;
        default:
            break;
        }
        right_rotate(root->left);
        left_rotate(root);
    } else if (root->left->balance == eq) {
        switch (root->left->right->balance) {
        case lf:
            root->balance = rg;
            root->left->balance = lf;
            root->left->right->balance = lf;
            right_rotate(root->left);
            left_rotate(root);
            break;
        case rg:
            root->balance = eq;
            root->left->balance = eq;
            root->left->right->balance = eq;
            right_rotate(root->left);
            left_rotate(root);
            left_balance(root->left);//两次旋转后仍然不平衡
            break;
        case eq:
            root->balance = eq;
            root->left->balance = lf;
            root->left->right->balance = lf;
            right_rotate(root->left);
            left_rotate(root);
            break;
        default:
            break;
        }
    } else {
        throw 500;
    }
}

template<typename T>
void AVL_tree<T>::right_balance(Node* &root) {
    if (root->right->balance == rg) {
        root->balance = eq;
        root->right->balance = eq;
        right_rotate(root);
    } else if (root->right->balance == lf) {
        switch (root->right->left->balance) {
        case rg:
            root->balance = lf;
            root->right->balance = eq;
            root->right->left->balance = eq;
            break;
        case lf:
            root->balance = eq;
            root->right->balance = rg;
            root->right->left->balance = eq;
            break;
        case eq:
            root->balance = eq;
            root->right->balance = eq;
            root->right->left->balance = eq;
            break;
        default:
            break;
        }
        left_rotate(root->right);
        right_rotate(root);
    } else if (root->right->balance == eq) {
        switch (root->right->left->balance) {
        case rg:
            root->balance = lf;
            root->right->balance = rg;
            root->right->left->balance = rg;
            left_rotate(root->right);
            right_rotate(root);
            break;
        case lf:
            root->balance = eq;
            root->right->balance = eq;
            root->right->left->balance = eq;
            left_rotate(root->right);
            right_rotate(root);
            right_balance(root->right); //两次旋转后仍然不平衡
            break;
        case eq:
            root->balance = eq;
            root->right->balance = rg;
            root->right->left->balance = rg;
            left_rotate(root->right);
            right_rotate(root);
            break;
        default:
            break;
        }
    } else {
        throw 500;
    }
}

template<typename T>
void AVL_tree<T>::left_rotate(Node* &root) {
    Node* lNode = root->left;
    root->left = root->left->right;
    lNode->right = root;
    root = lNode;
}

template<typename T>
void AVL_tree<T>::right_rotate(Node* &root) {
    Node* rNode = root->right;
    root->right = root->right->left;
    rNode->left = root;
    root = rNode;
}

template<typename T>
void AVL_tree<T>::pre(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    pre(root->left);
    pre(root->right);
}