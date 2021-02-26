#include <iostream>

using namespace std;

const int LCM_ALL = 720720;

inline bool is_odd(int n) {return (n & 1) != 0;}

inline int pow_4(int n) {return n * n * n * n;}

int main() {

    int n, m;
    scanf("%d %d ", &n, &m);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            int x;
            scanf("%d ", &x);

            if(is_odd(i + j)) printf("%d ", LCM_ALL + pow_4(x));
            else printf("%d ", LCM_ALL);
        }

        printf("\n");
    }

    return 0;
}

