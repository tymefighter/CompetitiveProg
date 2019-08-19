#include<cstdio>
#include<iostream>

int a[] = {1, 5, 10, 25, 50};
long long int count[5][30001];

void reset(int n)
{
    int coin, i;
    for(coin = 0;coin < 5;coin++)
    {
        for(i = 0;i <= n;i++)
            count[coin][i] = -1;
    }
}

long long int solve(int coin, int n)
{
    if(n < 0 || coin >= 5)
        return 0;
    
    if(count[coin][n] != -1)
        return count[coin][n];

    if(n == 0)
    {
        count[coin][n] = 1;
        return 1;
    }
   
    long long int count_val = solve(coin, n - a[coin]) + solve(coin + 1, n);

    count[coin][n] = count_val;
    return count[coin][n];
}

int main()
{
    int n;
    long long int ans;
    while(std::cin>>n)
    {
        reset(n);
        ans = solve(0, n);
        if(ans == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", ans, n);

    }
    return 0;
}