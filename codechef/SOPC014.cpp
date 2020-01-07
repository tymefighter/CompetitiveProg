#include<iostream>

using namespace std;

int n;

void solve()
{
    if(n % 2)
        cout<<"4\n";
    else
        cout<<"5\n";
    printf("0 0\n0 %d\n%d 0\n%d %d\n", n, n, n, n);
    if(!(n % 2))
        printf("%d %d\n", n / 2, n / 2);
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        solve();
    }
    return 0;
}