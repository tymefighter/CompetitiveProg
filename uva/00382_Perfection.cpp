#include<iostream>
#include<cstdio>

using namespace std;

int n;

void solve()
{
    int sum = 0;

    for(int i = 1;i < n;i++)
    {
        if(n % i == 0)
            sum += i;
    }

    if(sum == n)
        printf("%5d  PERFECT\n", n);
    else if(sum > n)
        printf("%5d  ABUNDANT\n", n);
    else
        printf("%5d  DEFICIENT\n", n);
}

int main()
{
    printf("PERFECTION OUTPUT\n");
    while(cin>>n)
    {
        if(!n)
            break;
        solve();
    }

    printf("END OF OUTPUT\n");

    return 0;
}