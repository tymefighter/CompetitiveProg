#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int n;
vector<int> a, lis, pred;

void print_sol(int i)
{
    if(pred[i] != -1)
        print_sol(pred[i]);
    
    cout<<a[i]<<"\n";
}

void solve()
{
    int i, j, max_val, pred_val;
    int ans_idx = 0;
    lis[0] = 1;
    pred[0] = -1;

    for(i = 1;i < n;i++)
    {
        max_val = 0;
        pred_val = -1;
        for(j = i-1;j >= 0;j--)
        {
            if(a[j] < a[i] && lis[j] > max_val)
            {
                max_val = lis[j];
                pred_val = j;
            }
        }

        lis[i] = 1 + max_val;
        pred[i] = pred_val;

        if(lis[ans_idx] <= lis[i])
            ans_idx = i;
    }

    cout<<lis[ans_idx]<<"\n-\n";
    print_sol(ans_idx);
}

int main()
{
    int x;
    while(cin>>x)
    {
        a.push_back(x);
    }

    n = a.size();
    lis.assign(n, 0);
    pred.assign(n, -1);

    solve();
    return 0;
}