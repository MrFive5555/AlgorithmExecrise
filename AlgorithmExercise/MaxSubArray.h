/* 寻找和最大的子数组 */

#pragma once
class SubArray {
public:
    SubArray(int sum, int low, int high)
        : sum(sum), low(low), high(high) {
    }
    int sum;
    int low;
    int high;
};

template<int L>
SubArray MaxSubArray(const int(&a)[L]) {
    int max = 0, maxLow = 0, maxHigh = 0;
    int sum = 0, low = 0, high = 0;

    for (int j = 0; j != L; ++j) {
        if (a[j] >= 0) {
            sum += a[j];
            ++high;
            if (sum > max) {
                max = sum;
                maxLow = low;
                maxHigh = high;
            }
        } else if (sum + a[j] <= 0) {
            low = high = j + 1;
            sum = 0;
        } else {
            ++high;
            sum += a[j];
        }
    }
    return SubArray(max, maxLow, maxHigh);
}