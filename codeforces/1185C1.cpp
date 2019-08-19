#include<iostream>
#include<algorithm>

using namespace std;

int n, M, m;
int t[105], a[105];

void read()
{
    cin>>n>>M;

    for(int i = 0;i < n;i++)
        cin>>t[i];
}

int get_ans(int tm, int i)
{
    sort(a, a + m);
    reverse(a, a + m);
    int ans = 0;

    while(tm + t[i] > M)
    {
        tm -= a[ans];
        ans ++;
    }

    return ans;
}

void solve()
{
    int i, j;
    int tm;

    for(i = 0;i < n;i++)
    {
        m = i;
        tm = 0;
        for(j = 0;j < i;j++)
        {
            a[j] = t[j];
            tm += t[j];
        }

        if(tm + t[i] <= M)
        {
            cout<<"0 ";
            continue;
        }

        cout<<get_ans(tm, i)<<" ";
    }
}

int main()
{
    read();
    solve();


    return 0;
}