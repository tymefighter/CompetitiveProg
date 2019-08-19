#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> quasi;
vector<int> dp;
vector<int> pred;

void generate_quasi(int n)
{
    int i, j, sz;
    quasi.push_back(0);

    for(i = 1;i <= n;i *= 10)
    {
        sz = quasi.size();
        for(j = 0;j < sz;j++)
            quasi.push_back(quasi[j] + i);
    }

    sort(quasi.begin(), quasi.end());
    quasi[0] = 1;

}

int solve(int n)
{
    if(dp[n] != -1)
        return dp[n];
    
    if(n == 0)
    {
        dp[n] = 0;
        return 0;
    }

    int min_val = -1, val, pr = -1;
    for(int q : quasi)
    {
        if(n - q < 0)
            break;
        //cout<<n-q<<"--\n";
        
        val = solve(n - q);
        if(val == -1)
            continue;
        
        if(min_val == -1 || val < min_val)
        {
            pr = n - q;
            min_val = val;
        }
    }

    if(min_val == -1)
        dp[n] = -1;
    else
    {
        dp[n] = min_val + 1;
        pred[n] = pr;
    }
    
    return dp[n];
}

void print_pred(int n)
{
    if(pred[n] == -1)
        return;
    
    print_pred(pred[n]);
    cout<<n - pred[n]<<" ";
}


int main()
{
    
    int n;
    cin>>n;
    generate_quasi(n+1);
    dp.assign(n+1, -1);
    pred.assign(n+1, -1);

    cout<<solve(n)<<"\n";
    print_pred(n);
    cout<<"\n";

    return 0;
}

