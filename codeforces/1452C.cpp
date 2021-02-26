#include <iostream>

using namespace std;

const int N = 200005;
char s[N];

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        scanf("%s", s);

        int i = 0;
        int ans = 0, numOpen1 = 0, numOpen2 = 0;
        while(s[i] != '\0') {
            if(s[i] == '(')
                numOpen1 ++;
            else if(s[i] == '[')
                numOpen2 ++;
            else if(s[i] == ')' && numOpen1 > 0) {
                ans ++;
                numOpen1 --;
            }
            else if(s[i] == ']' && numOpen2 > 0) {
                ans ++;
                numOpen2 --;
            }
            i ++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
