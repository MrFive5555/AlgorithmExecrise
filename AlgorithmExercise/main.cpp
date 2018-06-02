#include <iostream>
#include "SplayTree.h"

using namespace std;

int main() {
    SplayTree<int> tree;

    int arr[12] = { 
        1, 4, 6, 1, 
        3, 6, 5, 21, 
        5, 4, 23, 2 
    };
    for (int i = 0; i != 12; ++i) {
        tree.splay(arr[i]);
        tree.pre_traverse();
    }
}