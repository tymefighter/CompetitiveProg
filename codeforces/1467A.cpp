#include <iostream>

using namespace std;

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        int n;
        scanf("%d ", &n);

        if(n == 1) printf("9");
        else if(n == 2) printf("98");
        else {
            printf("989");
            
            for(int i = 0;i < n - 3;i++)
                printf("%d", i % 10);
        }

        printf("\n");
    }

    return 0;
}
