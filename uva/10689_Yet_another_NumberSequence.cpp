#include<iostream>

using namespace std;

/*
    Pisano Period
    last 1: 60
    last 2: 300
    last 3: 1500
    last 4: 15000
*/


int a, b, n, m;
int f[15001];

void generate()
{
    int val = 1;
    for(int i = 0;i < m;i++)
        val *= 10;

    f[0] = a % val, f[1] = b % val;
    for(int i = 2;i <= n;i++)
        f[i] = (f[i - 1] + f[i - 2]) % val;
}

void read_solve()
{
    cin>>a>>b>>n>>m;

    if(m == 1)
        n %= 60;
    else if(m == 2)
        n %= 300;
    else if(m == 3)
        n %= 1500;
    else if(m == 4)
        n %= 15000; 

    generate();
    cout<<f[n]<<"\n";
}

int main()
{
    int t;
    cin>>t;

    while(t--)
        read_solve();
    return 0;
}