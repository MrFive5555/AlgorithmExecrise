#include <stdlib.h>
#include "calculateParse.h"

double Calculate::execute(const char* str) throw (FormatErr, std::invalid_argument) {
    allowSign = true;
    double firTerm = getTerm(str);
    while (*str != 0) {
        if (*str == '+') {
            allowSign = false;
            firTerm += getTerm(++str);
        } else if (*str == '-') {
            allowSign = false;
            firTerm -= getTerm(++str);
        } else {
            throw FormatErr(str);
        }
    }
    return firTerm;
}

double Calculate::parseBrackt(const char*& str) throw (FormatErr, std::invalid_argument) {
    allowSign = true;
    double firTerm = getTerm(str);
    while (*str != ')') {
        if (*str == '+') {
            allowSign = false;
            firTerm += getTerm(++str);
        } else if (*str == '-') {
            allowSign = false;
            firTerm -= getTerm(++str);
        } else {
            throw FormatErr(str);
        }
    }
    ++str;
    return firTerm;
}

double Calculate::getTerm(const char*& str) throw (FormatErr, std::invalid_argument) {
    double first = getNumber(str);
    if (*str == 0 || *str == ')') {
        return first;
    }
    while (*str != '+' && *str != '-' && *str != 0) {
        if (*str == '*') {
            allowSign = false;
            first *= getNumber(++str);
        } else if (*str == '/') {
            allowSign = false;
            double div = getNumber(++str);
            if (div == 0) {
                throw std::invalid_argument("the divisor can't be zero");
            }
            first /= div;
        } else if (*str == ')') {
            return first;
        } else {
            throw FormatErr(str);
        }
    }
    return first;
}

double Calculate::getNumber(const char*& str) throw (FormatErr, std::invalid_argument) {
    if (*str == '(') {
        return parseBrackt(++str);
    }
    if (*str == '*' || *str == '/') {
        throw FormatErr(str);
    }
    if (!allowSign && (*str == '+' || *str == '-')) {
        throw FormatErr(str);
    }
    char* end = nullptr;
    double num = strtod(str, &end);
    str = end;
    return num;
}
