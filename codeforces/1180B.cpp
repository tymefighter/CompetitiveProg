#include<iostream>
#include<algorithm>
#include<utility>
#include<cassert>

using namespace std;

int n;
int a[100005];

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        a[i] = i;
        cin>>a[i];
        if(a[i] < 0)
            a[i]= - a[i] - 1;
    }
}

float abs2(float x)
{
    if(x < 0)
        x = -x;
    return x;
}

void solve()
{
    if(n % 2 == 0)
    {
        for(int i = 0;i < n;i++)
            a[i] = - a[i] - 1;
        return;
    }
    
    float min_val = 100., val;
    int i, id = -1, n_zeros = 0;

    for(i = 0;i < n;i++)
    {
        if(a[i] == 0)
        {
            n_zeros++;
            continue;
        }

        val = abs2((float) (-a[i] - 1) / a[i]);
        if(val < min_val)
        {
            min_val = val;
            id = i;
        }
    }

    if(n_zeros == n)
    {
        a[0] = 0;
        return;
    }

    for(i = 0;i < n;i++)
    {
        if(i == id)
            continue;
        a[i] = -a[i] - 1;
    }
}

int main()
{
    read();
    solve();
    for(int i = 0;i < n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}