#include<iostream>
#include<cmath>

using namespace std;

long long int n;

long long int sumDig(long long int x)
{
    long long int sum = 0;
    while(x)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

bool is_prime(long long int x)
{
    for(int i = 2;i <= sqrt(x);i++)
    {
        if(x % i == 0)
            return false;
    }

    return true;
}

bool checkSmith(long long int x)
{
    if(is_prime(x))
        return false;

    long long int sum1 = sumDig(x), sum2 = 0;

    while(x % 2 == 0)
    {
        x /= 2;
        sum2 += 2;
    }

    long long int xsq = sqrt(x);
    for(int i = 3;i <= xsq;i += 2)
    {
        while(x % i == 0)
        {
            x /= i;
            sum2 += sumDig(i);
        }
    }


    if(x != 1)
        sum2 += sumDig(x);

    return sum1 == sum2;
}

void solve()
{
    long long int x = n + 1;
    bool found = false;
    while(!found)
    {
        if(checkSmith(x))
            found = true;
        else
            x++;
    }

    cout<<x<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        solve();
    }
    
    return 0;
}