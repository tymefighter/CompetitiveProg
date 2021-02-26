#include<iostream>
#include<cmath>

using namespace std;

/*
    Find All submasks of the given mask
*/

void outputBinary(int x, int numBits = 32) {
    for(int i = numBits - 1;i >= 0;i--)
        cout << (x & (1 << i) ? '1' : '0');

    cout << "\n";
}

void submaskEnumeration(int mask) {
    int s = mask;
    int numBits = static_cast<int>(log2(mask)) + 1;

    while(s) {
        outputBinary(s, numBits);
        s = (s - 1) & mask;
    }
    outputBinary(s, numBits);
}

int main() {
    int mask;
    cin >> mask;

    submaskEnumeration(mask);
    return 0;
}
