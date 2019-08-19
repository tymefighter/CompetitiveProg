#include<iostream>

using namespace std;

int n;
int indeg[100005];

bool read_solve()
{
    cin>>n;
    int x, y;

    for(int i = 0;i < n;i++)
        indeg[i] = 0;

    for(int i = 0;i < n - 1;i++)
    {
        cin>>x>>y;
        x--, y--;
        indeg[x]++;
        indeg[y]++;
    }

    for(int i = 0;i < n;i++)
    {
        if(indeg[i] == 2)
            return false;
    }

    return true;
}

int main()
{
    if(read_solve())
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}