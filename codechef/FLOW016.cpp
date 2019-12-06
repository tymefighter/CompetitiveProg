#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

long long int lcm(int a, int b, int d)
{
    return (a / d) * (b * 1ll);
}

int A, B, D;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>A>>B;
        D = gcd(A, B);
        printf("%d %lld\n", D, lcm(A, B, D));
    }
    return 0;
}