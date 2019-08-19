#include<iostream>
#include<algorithm>

using namespace std;

int a[10004];
int n;

void read()
{
    cin>>n;

    for(int i = 0;i < 2*n;i++)
        cin>>a[i];
}

void solve()
{
    sort(a, a + 2*n);
    int sum1, sum2;

    sum1 = sum2 = 0;
    for(int i = 0;i < n;i++)
    {
        sum1 += a[i];
        sum2 += a[i+n];
    }

    if(sum1 == sum2)
        cout<<"-1\n";
    else
    {
        for(int i = 0;i < 2*n;i++)  
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}


int main()
{
    read();
    solve();

    return 0;
}