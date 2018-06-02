#pragma once

#include <vector>
using namespace std;

/* the problem is about we should find the good chips in
* some chips; each chip can check whether another chip
* is good. But the good chip can return the correct result
* while the bad chip will return an unexpected result, maybe
* correct or false.
* If we know the good chip is more than the bad one, we
* should find all the good chip in it.
*/

class Chip {
public:
    Chip(bool good, int num) : good(good), num(num) {}
    bool check(Chip other);
    int getNum();
    bool good;
private:
    int num;

};

class FindGoodChip {
public:
    FindGoodChip(vector<Chip>&vec) : chipVec(vec) {}
    vector<int> excecute();
private:
    Chip recursive(vector<int> chipVec);
    vector<Chip> chipVec;
};