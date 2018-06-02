/* È«ÅÅÐòËã·¨ */

#pragma once

#include <algorithm>
#include <vector>

using std::vector;

template <int size>
class allPermutaion {
public:
    vector<vector<int>> execute() {
        for (int i = 0; i != size; ++i) {
            num[i] = i + 1;
        }
        helper(num, size);
        return ret;
    }
private:
    int num[size];
    vector<vector<int>> ret;

    void helper(int subArr[], const int arrSize) {
        if (arrSize == 1) {
            ret.push_back(vector<int>(num, num + size));
        } else {

            //each loop will print a array with the same head element 
            for (int i = 1; i<arrSize; i++) {
                helper(subArr + 1, arrSize - 1);
                std::swap(subArr[0], subArr[i]);
            }
            helper(subArr + 1, arrSize - 1);

            //restore
            int temp = subArr[0];
            for (int i = 0; i<(arrSize - 1); i++) {
                subArr[i] = subArr[i + 1];
            }
            subArr[arrSize - 1] = temp;
        }
    }

};
