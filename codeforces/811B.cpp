#include<iostream>

using namespace std;

int n, m;
int p[10005];

void read_solve()
{
    cin>>n>>m;
    int i, j;

    for(i = 0;i < n;i++)
        cin>>p[i];
    
    int l, r, x, pos;
    for(i = 0;i < m;i++)
    {
        cin>>l>>r>>x;
        l--, r--, x--;
        pos = l;

        for(j = l;j <= r;j++)
        {
            if(p[j] < p[x])
                pos ++;
        }
        if(pos == x)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

}

int main()
{
    read_solve();
    return 0;
}