#include<iostream>

using namespace std;

long long int A[13], fac[13];

void generate()
{
    A[1] = 0;
    A[2] = 1;
    fac[1] = 1;
    fac[2] = 2;
    for(int i = 3;i <= 12;i++)
    {
        A[i] = (i - 1) * (A[i - 2] + A[i - 1]);
        fac[i] = fac[i - 1] * i;
    }
}

int main()
{
    generate();
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<A[n]<<"/"<<fac[n]<<"\n";
    }
    return 0;
}