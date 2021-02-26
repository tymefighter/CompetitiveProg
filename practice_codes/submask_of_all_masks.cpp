#include<iostream>
#include<cmath>

using namespace std;

/*
    Find All submasks of the all masks
    of n bits (i.e. 1111...111 total n times)
*/

void outputBinary(int x, int numBits = 32) {
    for(int i = numBits - 1;i >= 0;i--)
        cout << (x & (1 << i) ? '1' : '0');

    cout << "\n";
}

void submask_of_all_masks(const int n) {
    for(int mask = 0;mask < (1 << n);mask++) {
        cout << "mask: " << mask << "\n";
        int submask = mask;
        while(submask) {
            outputBinary(submask, n);
            submask = (submask - 1) & mask;
        }
        outputBinary(submask, n);
    }
}

int main() {

    int n;
    cin >> n;
    submask_of_all_masks(n);

    return 0;
}
