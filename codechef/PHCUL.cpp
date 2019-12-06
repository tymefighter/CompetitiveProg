#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n, m, k;
pair<int, int> x, a[5005], c[5005], e[5005];
double dae[5005], dce[5005];

double dist(const pair<int, int> &u, const pair<int, int> &v)
{
    double val1 = u.first - v.first, val2 = u.second - v.second;
    return sqrt(val1 * val1 + val2 * val2);
}

void read()
{
    cin>>x.first>>x.second;
    cin>>n>>m>>k;

    int i, j;
    for(i = 0;i < n;i++)
        scanf("%d%d",&a[i].first, &a[i].second);
    
    for(i = 0;i < m;i++)
        scanf("%d%d",&c[i].first, &c[i].second);
    
    for(i = 0;i < k;i++)
        scanf("%d%d",&e[i].first, &e[i].second);

    double d;
    for(i = 0;i < n;i++)
    {
        dae[i] = -1;
        for(j = 0;j < k;j++)
        {
            d = dist(a[i], e[j]);
            if(dae[i] < 0 || d < dae[i])
                dae[i] = d;
        }
    }

    for(i = 0;i < m;i++)
    {
        dce[i] = -1;
        for(j = 0;j < k;j++)
        {
            d = dist(c[i], e[j]);
            if(dce[i] < 0 || d < dce[i])
                dce[i] = d;
        }
    }
}

void solve()
{
    int i, j;
    double d, ans = -1, val;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            d = dist(a[i], c[j]);
            val = min(dist(x, a[i]) + dce[j], dist(x, c[j]) + dae[i]);
            val += d;
            if(ans < 0 || val < ans)
                ans = val;
        }
    }

    printf("%0.10f\n", ans);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        solve();
    }
    return 0;
}