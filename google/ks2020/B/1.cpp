#include<iostream>

using namespace std;

const int N = 105;
int n, a[N], pk;

void compute() {

    pk = 0;
    for(int i = 1;i < n - 1;i++) { 
        if(a[i] > a[i - 1] && a[i] > a[i + 1])
            pk ++;
    }
}

int main() {

    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        
        cin >> n;
        for(int j = 0;j < n;j++) {
            cin >> a[j];
        }

        compute();
        printf("Case #%d: %d\n", i, pk);
    }
    return 0;
}