#include "MaxSubArray.h"
#include <iostream>
using namespace std;

void printSubarray(int arr[], SubArray max) {
    if (max.high == max.low) {
        cout << "no max subarray" << endl;
    } else {
        cout << "the max sum is : " << max.sum << endl << "subarray : ";
        for (int i = max.low; i != max.high; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    cout << "==============================" << endl;
}

int main() {
    int arr[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
    SubArray max = MaxSubArray(arr);
    printSubarray(arr, max);

    int arr2[] = { -1,-2,-3,-4 };
    printSubarray(arr2, MaxSubArray(arr2));

    int arr3[] = { 0,0,0,0 };
    printSubarray(arr3, MaxSubArray(arr3));
}