#include <iostream>

using namespace std;

void readAndComputeSum(int &n, int &sum) {
    cin >> n;
    
    sum = 0;
    for(int i = 0;i < n;i++) {
        int a, g;
        cin >> a >> g;
        sum += a;
    }
}

inline int ceilDiv(int x, int y) {
    return (x + y - 1) / y;
}

void getAndPrintAns(int &n, int &sum) {

    int low = sum <= 500 ? 0 : ceilDiv(sum - 500, 1000);
    int high = min(n, (sum + 500) / 1000);

    if(low > high) {
        cout << "-1\n";
        return;
    }

    for(int i = 0;i < low;i++)
        cout << "G";
    
    for(int i = low;i < n;i++)
        cout << "A";

    cout << "\n";
}

int main() {
    
    int n, sum;
        
    readAndComputeSum(n, sum);
    getAndPrintAns(n, sum);
    
    return 0;
}