#include<iostream>

using namespace std;

int n;
int a[2002], lis[2002], lds[2002];

void read()
{
    for(int i = 0;i < n;i++)
        cin>>a[i];
}

int solve()
{
    int i, j;
    int max_val_lis, max_val_lds;
    for(i = n-1;i >= 0;i--)
    {
        lis[i] = 0;
        lds[i] = 0;
        max_val_lis = max_val_lds = 0;
        for(j = n-1;j > i;j--)
        {
            if(a[j] > a[i])
                max_val_lis = max(max_val_lis, lis[j]);
            if(a[j] < a[i])
                max_val_lds = max(max_val_lds, lds[j]);
        }

        lis[i] = 1 + max_val_lis;
        lds[i] = 1 + max_val_lds;
    }

    int ans = 0, val;
    for(i = 0;i < n;i++)
    {
        val = lis[i] + lds[i] - 1;
        if(val > ans)
            ans = val;
    }

    return ans;
}


int main()
{
    int t;

    cin>>t;
    while(t--)
    {
        cin>>n;
        read();
        cout<<solve()<<"\n";
    }

    return 0;
}