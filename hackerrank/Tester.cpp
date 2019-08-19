#include<iostream>
#include<stack>

using namespace std;

int n[2];
long long x;
int a[100005];
stack<int> s[2];

void reset()
{
    for(int j = 0;j < 2;j++)
    {
        while(!s[j].empty())
            s[j].pop();
    }
}

void read()
{
    cin>>n[0]>>n[1]>>x;
    int i, j;

    for(j = 0;j < 2;j++)
    {
        for(i = 0;i < n[j];i++)
            cin>>a[i];
        
        for(i = n[j] - 1;i >= 0;i--)
            s[j].push(a[i]);
    }
}

void solve()
{
    long long sum = 0;
    int i, ans = 0, min_val, min_idx;
    bool flag = true;

    while(flag)
    {
        flag = false;       // assume that the game terminated
        min_val = x + 1;

        for(i = 0;i < 2;i++)
        {
            if(!s[i].empty() && s[i].top() < min_val)
            {
                min_idx = i;
                min_val = s[i].top();
            }
        }

        if(sum + min_val <= x)
        {
            s[min_idx].pop();
            sum += min_val; 
            ans ++;
            cout<<sum<<" "<<min_val<<" "<<x<<"\n";
            flag = true;
        }
    }

    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        reset();
        read();
        solve();
    }
    return 0;
}