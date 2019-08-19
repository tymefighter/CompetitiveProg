#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int n;
vector<int> ht, wd, lis, lds;

void clearAll()
{
    ht.clear();
    wd.clear();
    lis.clear();
    lds.clear();
}

void read()
{
    int i;
    cin>>n;
    ht.resize(n);
    wd.resize(n);
    lis.resize(n);
    lds.resize(n);

    for(i = 0;i < n;i++)
        cin>>ht[i];

    for(i = 0;i < n;i++)
        cin>>wd[i];
}

void solve(int case_no)
{
    int i, j;
    int ans_inc, ans_dec;
    int max_inc, max_dec;

    ans_inc = ans_dec = lis[0] = lds[0] = wd[0];

    for(i = 1;i < n;i++)
    {
        max_inc = max_dec = 0;

        for(j = 0;j < i;j++)
        {
            if(ht[j] < ht[i] && max_inc < lis[j])
                max_inc = lis[j];
            else if(ht[j] > ht[i] && max_dec < lds[j])
                max_dec = lds[j];
        }

        lis[i] = wd[i] + max_inc;
        lds[i] = wd[i] + max_dec;

        ans_inc = max(ans_inc, lis[i]);
        ans_dec = max(ans_dec, lds[i]);
    }

    if(ans_inc >= ans_dec)
        printf("Case %d. Increasing (%d). Decreasing (%d).\n", case_no, ans_inc, ans_dec);
    else
        printf("Case %d. Decreasing (%d). Increasing (%d).\n", case_no, ans_dec, ans_inc);
}

int main()
{
    int t;
    cin>>t;

    for(int i = 1;i <= t;i++)
    {
        clearAll();
        read();
        solve(i);
    }

    return 0;
}