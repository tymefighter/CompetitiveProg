#include<iostream>

using namespace std;

int c[200005], cu[200005];
int n, k, q;

void reset()
{
    for(int i = 0;i < 200005;i++)
        c[i] = 0;
}

void read()
{
    cin>>n>>k>>q;
    int i, l, r;
    for(i = 0;i < n;i++)
    {
        cin>>l>>r;
        c[l]++;
        c[r + 1]--;
    }

    int sum = 0;
    for(i = 0;i <= 200000;i++)
    {
        sum += c[i];
        cu[i] = sum;

        if(cu[i] >= k)
            cu[i] = 1;
        else
            cu[i] = 0; 
    }

    for(i = 1;i <= 200000;i++)
        cu[i] += cu[i - 1];
}

void solve()
{
    int a, b;
    for(int i = 0;i < q;i++)
    {
        cin>>a>>b;
        cout<<cu[b] - cu[a - 1]<<"\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    reset();
    read();
    solve();
    return 0;
}