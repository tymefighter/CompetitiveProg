#include<iostream>
#include<cmath>

using namespace std;

int n;
float x, f, c;

void read_solve()
{
    cin>>n;

    for(int i = 0;i < n;i++)
    {
        cin>>x;
        f = floor(x), c = ceil(x);

        if(abs(x - f) < abs(x - c))
            cout<<(int)f<<" ";
        else
            cout<<(int)c<<" ";
    }
    cout<<"\n";
}

int main()
{
    read_solve();

    return 0;
}