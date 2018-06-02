#include <cmath>
#include <iostream>
#include "calculateParse.h"

#define ERROR 10e-10
using namespace std;

void test_parse(const char* str, double result) {
    double cal;
    try {
        Calculate parse;
        cal = parse.execute(str);
        if (!(fabs(cal - result) < ERROR)) {
            cout << "=======================================================" << endl
                << "[error]" << endl
                << "[expression] " << str << endl
                << "[ your answer  ] " << cal << endl
                << "[correct answer] " << result << endl << endl;
        }
    } catch (FormatErr) {
        cout << "=======================================================" << endl
            << "[Format Error]" << endl
            << "[expression] " << str << endl << endl;
    }
}

void test_format(const char* str) {
    bool format = false;
    try {
        Calculate parse;
        parse.execute(str);
    } catch (FormatErr) {
        format = true;
    }
    if (!format) {
        cout << "=======================================================" << endl
            << "[Format Error But Not Test]" << endl
            << "[expression] " << str << endl << endl;
    }
}

int main() {
    test_parse("3+4", 7);
    test_parse("3-4", -1);
    test_parse("3*4", 12);
    test_parse("3/4", 0.75);
    test_parse("1+2+3+4+5+6+7", 28);
    test_parse("15-1-2-3-4-5", 0);
    test_parse("1-2+3-4+5", 3);
    test_parse("9*8*7*4", 2016);
    test_parse("60/2/3", 10);
    test_parse("5/8*8/7*7", 5);
    test_parse("3*4+4*5", 32);
    test_parse("3/5+7/5", 2);
    test_parse("-3+4", 1);
    test_parse("-3*4", -12);
    test_parse("-60/5", -12);
    test_parse("10000", 1e4);

    test_parse("(1+2)", 3);
    test_parse("(3-4)-(2+1)", -4);
    test_parse("(1-1)*(1+3)", 0);
    test_parse("(3-1)*(1+3)", 8);
    test_parse("(3/4)*(4/3)", 1);
    test_parse("(-1+2)", 1);

    test_format("(3+11)1+1");
    test_format("3+(3))");
    test_format("*23");
    test_format("1++1");
    test_format("1-+1");
    test_format("(3+1+1+1");
    cout << "[finish]" << endl;
}