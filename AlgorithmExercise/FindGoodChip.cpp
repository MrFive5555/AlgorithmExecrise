#include "FindGoodChip.h"
#include "Random.h"

bool Chip::check(Chip other) {
    if (this->good) {
        return other.good;
    } else {
        return Random::rand() % 2 == 1;
    }
}

int Chip::getNum() {
    return num;
}

Chip FindGoodChip::recursive(vector<int> chipNum) {
    if (chipNum.size() == 1) {
        return chipVec[chipNum.front()];
    } else if (chipNum.size() == 2) {
        size_t goodCount = 0;
        for (auto iter = chipVec.begin(); iter != chipVec.end(); ++iter) {
            if (iter->check(chipVec[chipNum[0]])) {
                ++goodCount;
            }
        }
        if (goodCount >= chipVec.size() / 2) {
            return chipVec[chipNum[0]];
        } else {
            return chipVec[chipNum[1]];
        }
    }
    if (chipNum.size() % 2 != 0) {
        Chip temp = chipVec[chipNum.back()];
        chipNum.pop_back();

        size_t goodCount = 0;
        for (auto iter = chipNum.begin(); iter != chipNum.end(); ++iter) {
            if (chipVec[*iter].check(temp)) {
                ++goodCount;
            }
        }
        if (goodCount >= chipNum.size() / 2) {
            return temp;
        }
    }
    //compare with each pair
    for (auto iter = chipNum.begin(); iter != chipNum.end(); ) {
        bool first = chipVec[*iter].check(chipVec[*(iter + 1)]);
        bool second = chipVec[*(iter + 1)].check(chipVec[*iter]);
        if (first && second) {
            iter = chipNum.erase(++iter);
        } else if (first) {
            iter = chipNum.erase(iter);
            ++iter;
        } else if (second) {
            iter = chipNum.erase(++iter);
        } else {
            iter = chipNum.erase(chipNum.erase(iter));
        }
    }
    return recursive(chipNum);
}

vector<int> FindGoodChip::excecute() {
    vector<int>recVec;
    for (int i = 0; i != chipVec.size(); ++i) {
        recVec.push_back(i);
    }
    Chip good = recursive(recVec);

    vector<int> goodVec;
    for (auto iter = chipVec.begin(); iter != chipVec.end(); ++iter) {
        if (good.check(*iter)) {
            goodVec.push_back(iter - chipVec.begin());
        }
    }
    return goodVec;
}