#include <iostream>

using namespace std;

const int N = 200000;
int ct[N];

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {

        int n;
        scanf("%d ", &n);

        for(int i = 0;i < n;i++) ct[i] = 0;

        for(int i = 0;i < n;i++) {
            int x;
            scanf("%d ", &x);

            if(i < n - 1) ct[i + 1] += -1;
            ct[max(i - x + 1, 0)] += 1;
        }

        printf("%d ", ct[0] > 0);
        for(int i = 1;i < n;i++) {
            ct[i] += ct[i - 1];
            printf("%d ", ct[i] > 0);
        }

        printf("\n");

    }
    
    return 0;
}