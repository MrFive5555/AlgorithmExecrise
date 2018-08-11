#include <iostream>

using namespace std;

#define Length 18
int arr[Length] = {
    57, 71, 87, 97, 99, 101,
    103, 113, 114, 115, 128, 129,
    131, 137, 147, 156, 163, 168
};
int result[Length] = { 0 };

void getComb(int beg, int num) {
    if (beg == Length - 1) {
        if (num % arr[beg] == 0) {
            for (int i = 0; i != Length; ++i) {
                cout << result[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int c = 0; c * arr[beg] <= num; ++c) {
        result[beg] = c;
        getComb(beg + 1, num - c * arr[beg]);
    }
    result[beg] = 0;
}

int main(int argc, char const *argv[]) {
    int x;
    cin >> x;
    getComb(0, x);
    return 0;
}
