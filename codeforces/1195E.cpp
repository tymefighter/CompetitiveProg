#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int n, m, a, b;
long long int x, y, z;

long long int g[10000000];
long long int h[3001][3001];
deque<int> dq;
vector<vector<long long int> > cm; // col min

void read()
{
    cin>>n>>m>>a>>b;
    cin>>g[0]>>x>>y>>z;

    int i, j;
    for(i = 1;i <= n*m;i++)
        g[i] = (g[i - 1] * x + y) % z;

    for(i = 1;i <= n;i++)
    {
        for(j = 1;j <= m;j++)
            h[i - 1][j - 1] = g[(i - 1) * m + j - 1];
    }

}

void solve()
{
    cm.clear();
    cm.resize(n);

    int i, j;
    for(i = 0;i < n;i++)
    {
        dq.clear();
        for(j = 0;j < b;j++)
        {
            while(!dq.empty() && h[i][dq.back()] >= h[i][j])
                dq.pop_back();
            dq.push_back(j);
        }

        cm[i].push_back(h[i][dq.front()]);
        for(;j < m;j++)
        {
            while(!dq.empty() && dq.front() <= j - b)
                dq.pop_front();
            
            while(!dq.empty() && h[i][dq.back()] >= h[i][j])
                dq.pop_back();

            dq.push_back(j);
            cm[i].push_back(h[i][dq.front()]);
        }
    }
    long long int sum = 0;

    for(j = 0;j < cm[0].size();j++)
    {
        dq.clear();
        for(i = 0;i < a;i++)
        {
            while(!dq.empty() && cm[dq.back()][j] >= cm[i][j])
                dq.pop_back();
            dq.push_back(i);
        }

        sum += cm[dq.front()][j];
        for(;i < n;i++)
        {
            while(!dq.empty() && dq.front() <= i - a)
                dq.pop_front();

            while(!dq.empty() && cm[dq.back()][j] >= cm[i][j])
                dq.pop_back();

            dq.push_back(i);
            sum += cm[dq.front()][j];
        }
    }

    cout<<sum<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}