#include<iostream>
#include<cstdio>

using namespace std;

int n;
float dp[22][22][23];// u, v, length of path (i.e. no of conversions - 1)
int pred[22][22][23];

void reset()
{
    int i, j, m;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            for(m = 0;m < n;m++)
            {
                pred[i][j][m] = -1;
                dp[i][j][m] = 0;
            }
        }
    }
}

void read()
{
    reset();
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(i == j)
                continue;
            cin>>dp[i][j][0]; // 0 means 1 conversion
            pred[i][j][0] = i;
        }
    }
}

void printPath(int u, int v, int m)
{
    if(m > 0)
        printPath(u, pred[u][v][m-1], m-1);
    
    cout<<v+1<<" ";
}

void modified_FW()
{
    int m, k, u, v;
    float val;
    for(m = 1;m < n;m++) // maximum length cycle is m
    {
        for(k = 0;k < n;k++)
        {
            for(u = 0;u < n;u++)
            {
                for(v = 0;v < n;v++)
                {
                    val = dp[u][k][m - 1] * dp[k][v][0];
                    if(val > dp[u][v][m])
                    {
                        pred[u][v][m] = k;
                        dp[u][v][m] = val;
                    }
                }
            }
        }
    }

    for(m = 1;m < n;m++)
    {
        for(u = 0;u < n;u++)
        {
            if(dp[u][u][m] > 1.01)
            {
                printPath(u, pred[u][u][m], m);
                cout<<u+1<<"\n";
                return;
            }
        }
    }


    cout<<"no arbitrage sequence exists\n";
}


int main()
{
    while(cin>>n)
    {
        read();
        modified_FW();
    }
    return 0;
}