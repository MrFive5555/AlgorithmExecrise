#include <vector>
#include <iostream>
#include "Random.h"
#include "allPermutation.h"

using namespace std;

int main() {
    Random ran;
    vector<vector<int>> vec = allPermutaion<5>().execute();
    for (auto vecIter = vec.begin(); vecIter != vec.end(); ++vecIter) {
        if (vecIter->front() != 4)continue;
        if (ran.rand() % 10 < 4) continue;
        for (auto iter = vecIter->begin(); iter != vecIter->end(); ++iter) {
            cout << *iter << " ";
        }
        cout << endl;
    }
}