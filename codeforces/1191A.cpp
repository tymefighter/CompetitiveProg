#include<iostream>

using namespace std;


int pts(int x)
{
    if(x % 4 == 0)
        return 1;
    else if(x % 4 == 1)
        return 4;
    else if(x % 4 == 2)
        return 2;
    else
        return 3;   
}

void solve(int x)
{
    int ans, idx, val;
    ans = -1, idx = -1;
    for(int i = 0;i <= 2;i++)
    {
        val = pts(x + i);
        if(ans < val)
        {
            ans = val;
            idx = i; 
        }
    }
    x += idx;
    if(x % 4 == 0)
        cout<<idx<<" D";
    else if(x % 4 == 1)
        cout<<idx<<" A";
    else if(x % 4 == 2)
        cout<<idx<<" C";
    else if(x % 4 == 3)
        cout<<idx<<" B";

    cout<<"\n";
}

int main()
{
    int x;
    cin>>x;
    solve(x);
    return 0;
}