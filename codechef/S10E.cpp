#include<iostream>

using namespace std;

int n;
int a[105];

void read_solve()
{
    cin>>n;
    int i, j;
    int ans = 0;
    bool flag;

    for(i = 0;i < n;i++)
    {
        cin>>a[i];
        flag = true;
        for(j = i - 5;j < i;j++)
        {
            if(j >= 0 && a[i] >= a[j])
            {
                flag = false;
                break;
            }
        }

        if(!flag)
            continue;

        ans ++;
    }

    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        read_solve();

    return 0;
}