/* 逻辑问题：给定的若干个逻辑向量是否能通过合并产生全真向量 */

#pragma once
#include <algorithm>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template<int M, int N> class LoginProblem {
public:
    LoginProblem(bool arr[M][N]) : hasExecute(false) {
        for (int i = 0; i != M; ++i) {
            for (int j = 0; j != N; ++j) {
                array[i][j] = arr[i][j];
            }
        }
        now.push_back(bitset<N>());
    }
    bool execute() {
        hasExecute = true;
        return executeRecursive(0);
    }
    void print() {
        if (!hasExecute) {
            execute();
        }
        cout
            << "=================================" << endl
            << "the final state : ";
        for (int j = 0; j != N; ++j) {
            cout << now.back()[j] << " ";
        }
        sort(line.begin(), line.end());
        cout << endl;
        for (auto iter = line.begin(); iter != line.end(); ++iter) {
            cout << setw(3) << *iter << " : ";
            for (int j = 0; j != N; ++j) {
                cout << array[*iter][j] << " ";
            }
            cout << endl;
        }
        cout << "=================================" << endl << endl;
    }
private:
    bool executeRecursive(int begCol) {
        if (begCol == N) {
            return true;
        } else if (now.back().test(begCol)) {
            return executeRecursive(begCol + 1);
        }

        for (int i = 0; i != M; ++i) {
            if (!array[i][begCol]) { //no true
                continue;
            }

            //check conflict
            bool hasConflict = false;
            for (int j = 0; j != N; ++j) {
                if (now.back().test(j) && array[i][j]) {
                    hasConflict = true;
                }
            }
            if (hasConflict) {
                continue;
            }

            bitset<N> newState(now.back());
            for (int j = 0; j != N; ++j) {
                if (array[i][j]) {
                    newState.set(j);
                }
            }
            now.push_back(newState);
            line.push_back(i);
            if (executeRecursive(begCol + 1)) {
                return true;
            } else {
                now.pop_back();
                line.pop_back();
            }
        }
        return false;
    }
    bool array[M][N];
    vector<bitset<N>> now;
    vector<int> line;
    bool hasExecute;
};