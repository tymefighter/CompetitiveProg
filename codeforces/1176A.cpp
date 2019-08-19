#include<iostream>

using namespace std;

long long int n;

long long int solve()
{
    long long int a, b, c;
    a = b = c = 0;
    while(n % 2 == 0)
    {
        a ++;
        n = n / 2;
    }

    while(n % 3 == 0)
    {
        b ++;
        n = n / 3;
    }

    while (n % 5 == 0)
    {
        c ++;
        n = n / 5;
    }

    if(n != 1)
        return -1;
    else
        return a + 2 * b + 3 * c;
    
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        cin>>n;
        cout<<solve()<<"\n";
    }
    return 0;   
}