#include<iostream>

using namespace std;

int n;

bool check()
{
    int sum = 0, x = n;

    while(x != 0)
    {
        sum += x % 10;
        x /= 10;
    }
    if(sum % 4 == 0)
        return true;
    else
        return false;
}

void solve()
{
    while(!check())
        n++;
    cout<<n<<"\n";
}

int main()
{
    cin>>n;
    solve();
    return 0;
}