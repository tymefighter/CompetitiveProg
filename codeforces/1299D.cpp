#include <iostream>
#include <stack>

using namespace std;

const int N = 200005;
int n, ans[N];
char a[N];

void readInput() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++)
        scanf("%c ", &a[i]);
}

void solve() {
    int numSeq = 0;
    stack<int> oneEndIdx, zeroEndIdx;

    for(int i = 0;i < n;i++) {
        if(a[i] == '1') {
            if(zeroEndIdx.size() > 0) {
                ans[i] = ans[zeroEndIdx.top()];
                zeroEndIdx.pop();
            }
            else
                ans[i] = numSeq ++;

            oneEndIdx.push(i);
        }
        else {
            if(oneEndIdx.size() > 0){
                ans[i] = ans[oneEndIdx.top()];
                oneEndIdx.pop();
            }
            else
                ans[i] = numSeq ++;
            
            zeroEndIdx.push(i);
        } 
    }

    printf("%d\n", numSeq);
    for(int i = 0;i < n;i++) printf("%d ", ans[i] + 1);
    printf("\n");
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        readInput();
        solve();
    }

    return 0;
}

