#include <memory>
#include <vector>
#include "KMP.h"

int KMP(string str, string pattern) {
    if (pattern.empty()) {
        return 0;
    }
    vector<int> next(pattern.length());
    int i = 0, j = 0;

    //get next
    next[0] = -1;
    for (i = 0, j = -1; i != pattern.length() - 1; ) {
        while (j != -1 && pattern[i] != pattern[j]) {
            j = next[j];
        }
        ++i;
        ++j;
        if (pattern[i] == pattern[j]) {
            next[i] = next[j];
        } else {
            next[i] = j;
        }
    }

    for (i = j = 0; i != str.length() && j != pattern.length();) {
        if (j == -1 || str[i] == pattern[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == pattern.length()) {
        return i - j;
    } else {
        return str.length();
    }
}