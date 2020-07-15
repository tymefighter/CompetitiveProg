#include<iostream>
#include<cstring>

using namespace std;

const int N = 105;
int n;
char s[N];

bool solve() {
    int numOne = 0;
    for(int i = 0;i < n;i++)
        numOne += (s[i] == '1' ? 1 : 0);

    int minVal = min(numOne, n - numOne);
    return minVal % 2 == 1;
}

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        scanf("%s ", s);
        n = strlen(s);
        if(solve())
            printf("DA\n");
        else
            printf("NET\n");
    }
    return 0;
}