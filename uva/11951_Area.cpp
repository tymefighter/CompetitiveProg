#include<iostream>
#include<cstdio>

int cf[101][101];

using namespace std;

int n, m, K;
int max_area, min_cost;

void read()
{
    int i, j;
    cin>>n>>m>>K;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            cin>>cf[i][j];

            if(i > 0)
                cf[i][j] += cf[i-1][j];
            if(j > 0)
                cf[i][j] += cf[i][j-1];
            if(i > 0 && j > 0)
                cf[i][j] -= cf[i-1][j-1];
        }
    }
}

int compute2D(int i, int j, int k, int l)
{
    return cf[k][l] + (i > 0 && j > 0 ? cf[i-1][j-1] : 0) - (i > 0 ? cf[i-1][l] : 0) - (j > 0 ? cf[k][j-1] : 0);  
}

void solve()
{
    int i, j, k, l;
    int cost, area;
    bool first_comp = true;

    max_area = min_cost = 0;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            for(k = i;k < n;k++)
            {
                for(l = j;l < m;l++)
                {
                    cost = compute2D(i, j, k, l);
                    area = (k - i + 1) * (l - j + 1);

                    if(first_comp == true && cost <= K)
                    {
                        max_area = area;
                        min_cost = cost;
                        first_comp = false;
                    }
                    else if(area > max_area && cost <= K)
                    {
                        max_area = area;
                        min_cost = cost;
                    }
                    else if(area == max_area)
                    {
                        if(cost < min_cost)
                            min_cost = cost;
                    }
                }
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;

    for(int i = 1;i <= t;i++)
    {
        read();
        solve();
        printf("Case #%d: %d %d\n", i, max_area, min_cost);
    }

    return 0;
}