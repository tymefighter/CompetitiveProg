#include <iostream>
 
using namespace std;
 
const int N = 105;
char s[N];
 
int main() {
 
    int t;
    scanf("%d ", &t);
 
    while(t --) {
        int n, k;
        scanf("%d %d ", &n, &k);
        scanf("%s ", s);
 
        int start = 0, end = n - 1;

        while(k > 0 && start < end) {
            if(s[start ++] != s[end --]) break;
            k --;
        }

        if(k || start > end) printf("NO\n");
        else printf("YES\n");
    }
 
    return 0;
}