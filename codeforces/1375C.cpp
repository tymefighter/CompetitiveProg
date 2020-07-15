#include<iostream>

using namespace std;

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        int n;
        int first, last;
        scanf("%d ", &n);
        scanf("%d ", &first);
        for(int i = 1;i < n - 1;i++)
            scanf("%*d ");
        
        scanf("%d ", &last);
        if(first < last)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}