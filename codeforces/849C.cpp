#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int k;
    scanf("%d ", &k);

    if(k == 0) {
        printf("a\n");
        return 0;
    }

    char c = 'a';
    k *= 2;
    while(k) {
        int n = (1 + sqrt(1 + 4 * k)) / 2;
        k -= n * (n - 1);

        while(n --)
            printf("%c", c);

        c ++;
    }

    return 0;
}