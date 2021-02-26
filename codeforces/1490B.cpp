#include <iostream>

using namespace std;

int c[3];

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        int n;
        scanf("%d ", &n);

        c[0] = c[1] = c[2] = 0;
        int num_each = n / 3;

        for(int i = 0;i < n;i++) {
            int x;
            scanf("%d ", &x);

            c[x % 3] ++;
        }

        int num_moves = 0;
        for(int i = 0;i < 3;i++) {
            if(c[i] <= num_each) continue;
            for(int j = 0;j < 3;j++) {
                if(c[j] > num_each) continue;

                int num_transfer = min(c[i] - num_each, num_each - c[j]);
                int dist = (j - i + 3) % 3;

                c[i] -= num_transfer;
                c[j] += num_transfer;
                num_moves += num_transfer * dist;
            }
        }

        printf("%d\n", num_moves);
    }

    return 0;
}
