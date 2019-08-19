#include<iostream>

using namespace std;

int nC2(int n)
{
    return (n * (n - 1)) / 2;
}

int main()
{
    int n, m, kmn, kmx;
    cin>>n>>m;

    if(n % m)
        kmn = (m - 1) * nC2(n / m + 1) + nC2(n - ((m - 1) * (n / m + 1)));
    else
        kmn = m * nC2(n / m);
    
    if(n != m)
        kmx = nC2(n + 1 - m);
    else
        kmx = n;

    cout<<kmn<<" "<<kmx<<"\n";
    return 0;
}