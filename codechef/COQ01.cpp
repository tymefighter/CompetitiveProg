#include<iostream>
#include<map>
#include<algorithm>
#include<cstdio>

using namespace std;

int n;
int a[100005], b[100005];
map<int, int> m;

void reset()
{
    m.clear();
}

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        b[i] = a[i];
        m[a[i]] = i;
    }

    sort(b, b + n);
}

void solve(int case_no)
{
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        if(m[b[i]] != i)
        {
            m[a[i]] = m[b[i]];
            a[m[b[i]]] = a[i];
            a[i] = b[i];
            m[b[i]] = i;
            ans++;
        }
    }

    printf("Case %d: %d\n", case_no, ans);
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        reset();
        read();
        solve(i);
    }

    return 0;
}