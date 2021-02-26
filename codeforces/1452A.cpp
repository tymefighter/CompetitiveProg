#include <iostream>

using namespace std;

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        int x, y;
        scanf("%d %d ", &x, &y);

        if(x > y) swap(x, y);
        printf("%d\n", 2 * y - (x == y ? 0 : 1));
    }

    return 0;
}
