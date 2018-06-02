#include <iostream>

#include "KMP.h"

void test_KMP(string str, string pattern) {
    cout << "string : " << str << endl
        << "pattern : " << pattern << endl
        << "result : " << endl;
    int pos = KMP(str, pattern);
    for (int i = 0; i != str.length(); ++i) {
        if (i == pos) {
            cout << "( ";
        }
        cout << str[i] << " ";
        if (i == pos + pattern.length() - 1) {
            cout << ") ";
        }
    }
    cout << endl << "============================" << endl;
}

int main() {
    test_KMP("abcabcasfdsf", "cabc");
    test_KMP("abcabcasfdsf", "asf");
    test_KMP("abcabcasfdsf", "sss");
    test_KMP("abcabcasfdsf", "abcabca");
    test_KMP("abcabcasfdsf", "b");
}