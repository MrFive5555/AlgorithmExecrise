#pragma once

#include <iostream>
using namespace std;
template<int SIZE, int CHOOSE>
class Combination {
public:
    void execute() {
        for (int i = 0; i != SIZE; ++i) {
            arr[i] = false;
        }
        helper(arr, SIZE, CHOOSE);
    }
private:
    bool arr[SIZE];
    void helper(bool arr[], int size, int choose) {
        if (size < choose) {
            return;
        }
        if (size == 1) {
            arr[0] = choose == 1 ? true : false;
            output();
        } else if (choose == 0) {
            output();
        } else {
            arr[0] = true;
            helper(arr + 1, size - 1, choose - 1);
            arr[0] = false;
            helper(arr + 1, size - 1, choose);
            arr[0] = false;
        }
    }
    void output() {
        for (int i = 0; i != SIZE; ++i) {
            if (arr[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
};