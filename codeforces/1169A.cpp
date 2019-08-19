#include<iostream>

using namespace std;

int n, a, x, b, y;

bool solve()
{

    while(a != x && b != y)
    {
        if(a == b)
            return true;
        a = (a + 1) % n;
        b = (b + n - 1) % n;
    }

    if(a == b)
        return true;
    
    return false;
}

int main()
{
    cin>>n>>a>>x>>b>>y;
    a--, x--, b--, y--;
    if(solve())
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}