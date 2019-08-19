#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int dp[51][51];
vector<string> a;
int n, m;

void read()
{
    cin>>n;
    a.resize(n);

    for(int i = 0;i < n;i++)
        cin>>a[i];
    
    m = a[0].size();
}

bool check(int i, int j, int k)
{
    int p;

    for(p = 0;p < m;p++)
    {
        if(a[i][(p+j)%m] != a[i-1][(p+k)%m])
            return false;
    }

    return true;
}

int solve()
{
    int i, j, k;
    int val, min_val;

    for(j = 0;j < m;j++)
        dp[0][j] = j;

    for(i = 1;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            dp[i][j] = min_val = -1;
            
            for(k = 0;k < m;k++)
            {
                if(check(i, j, k))
                {
                    val = dp[i-1][k];
                    if(val == -1)
                        continue;
                    
                    val += j;

                    if(min_val == -1 || val < min_val)
                        min_val = val;
                }
            }
            dp[i][j] = min_val;
        }
    }

    min_val = -1;
    for(j = 0;j < m;j++)
    {
        val = dp[n-1][j];
        if(min_val == -1 || val < min_val)
            min_val = val;
    }

    return min_val;
}

int main()
{
    read();
    cout<<solve()<<"\n"; 

    return 0;
}