#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "AVL_tree.h"

using namespace std;


int main() {
    AVL_tree<int> tree;
    vector<int> num;
    for (int i = 1000; i--;) {
        int temp = rand() % 50;
        tree.insert(temp);
        test(tree);
        num.push_back(temp);
    }
    for (auto x : num) {
        swap(x, num[rand() % num.size()]);
    }
    for (auto x : num) {
        tree.remove(x);
        test(tree);
    }
}

//int main() {
//    int _case;
//    for (cin >> _case; _case--;) {
//        AVL_tree<int> tree;
//        int node_count;
//        for (cin >> node_count; node_count--; ) {
//            int temp = 0;
//            cin >> temp;
//            tree.insert(temp);
//        }
//        tree.pre_traverse();
//        cout << endl;
//    }
//}