#include <algorithm>
#include <iostream>

#include "FindGoodChip.h"
#include "Random.h"

void test() {
    const int SIZE = 100;
    vector<Chip> chipVec;
    vector<int> checkVec;
    for (int i = 0; i != SIZE; ++i) {
        if (i <= 2 * SIZE / 3) {
            chipVec.push_back(Chip(true, i));
            checkVec.push_back(i);
        } else {
            chipVec.push_back(Chip(false, i));
        }

    }

    for (int i = 0; i != SIZE; ++i) {
        swap(chipVec[i], chipVec[Random::rand() % 10]);
    }

    FindGoodChip Class_findGoodChip(chipVec);
    vector<int> findVec = Class_findGoodChip.excecute();
    vector<int> num;
    for (auto iter = findVec.begin(); iter != findVec.end(); ++iter) {
        num.push_back(chipVec[*iter].getNum());
    }
    sort(num.begin(), num.end());
    if (num != checkVec) {
        cout << "[begin]" << endl;
        for (auto iter = chipVec.begin(); iter != chipVec.end(); ++iter) {
            cout << iter->getNum() << " ";
        }
        cout << endl;
        for (auto iter = num.begin(); iter != num.end(); ++iter) {
            cout << *iter << " ";
        }
        cout << endl << "[end]" << endl;
    }
}

int main() {
    int time = 10000;
    while (time--) {
        test();
    }
}