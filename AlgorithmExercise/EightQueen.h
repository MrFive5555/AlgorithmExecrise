#pragma once
#include <iostream>

using namespace std;

template<int SIZE>
class EightQueen {
public:
    void execute() {
        helper(0);
    }
private:
    bool board[SIZE][SIZE];
    int count[SIZE][SIZE];
    void output() {
        for (int i = 0; i != SIZE; ++i) {
            for (int j = 0; j != SIZE; ++j) {
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << "================================================" << endl;
    }
    void put(int pos_i, int pos_j) {
        board[pos_i][pos_j] = true;
        for (int i = 0; i != SIZE; ++i) {
            for (int j = 0; j != SIZE; ++j) {
                if (i == pos_i && j == pos_j) {
                    continue;
                } else if (i == pos_i || j == pos_j) {
                    ++count[i][j];
                } else if ((i - pos_i) == (j - pos_j) || (i - pos_i) == -(j - pos_j)) {
                    ++count[i][j];
                }
            }
        }
    }
    void take(int pos_i, int pos_j) {
        board[pos_i][pos_j] = false;
        for (int i = 0; i != SIZE; ++i) {
            for (int j = 0; j != SIZE; ++j) {
                if (i == pos_i && j == pos_j) {
                    continue;
                } else if (i == pos_i || j == pos_j) {
                    --count[i][j];
                } else if ((i - pos_i) == (j - pos_j) || (i - pos_i) == -(j - pos_j)) {
                    --count[i][j];
                }
            }
        }
    }
    void helper(int pos) {
        if (pos == SIZE) {
            output();
            return;
        }
        for (int i = 0; i != SIZE; ++i) {
            if (count[pos][i] != 0) {
                continue;
            } else {
                put(pos, i);
                helper(pos + 1);
                take(pos, i);
            }
        }
    }
};