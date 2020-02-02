#include<iostream>
#include<vector>

using namespace std;


/*
    Does not work
*/

const int N = 100005;
const long long MOD = 1e9 + 7;
int n, b[N];
vector<vector<int> > a;
long long dp[N][2], dp2[N][2];
// dp[i][0]: Number of ways to split subtree rooted at i s.t
// the part containing i does not contain a black vert
// dp[i][1]: Number of ways to split subtree rooted at i s.t
// the part containing i contains a black vert

// dp2[j][r] = (sum over all (a0 .. aj) s.t (a0 + .. + aj = r)) of (prod over all v0 .. vj) of (dp[vj][aj] + (aj != 1 ? dp[vj][1] : 0))

void read()
{
    int p;
    cin>>n;
    a.clear();
    a.resize(n);
    for(int i = 0;i < n - 1;i++)
    {
        cin>>p;
        a[i + 1].push_back(p);
        a[p].push_back(i + 1);
    }

    for(int i = 0;i < n;i++)
        cin>>b[i];
}

void computeValue(int u, int par)
{
    vector<int> ch;
    for(int v : a[u])
    {
        if(v != par)
        {
            computeValue(v, u);
            ch.push_back(v);
        }
    }

    if(ch.size() == 0)
    {
        dp[u][0] = (b[u] == 1 ? 0 : 1);
        dp[u][1] = (b[u] == 1 ? 1 : 0);
        return;
    }

    if(b[u] == 1)
    {
        dp[u][0] = 0;
        dp[u][1] = 1;
        for(int v : ch)
            dp[u][1] = (dp[u][1] * ((dp[v][0] + dp[v][1]) % MOD)) % MOD;
    }
    else
    {
        dp[u][0] = 1;
        for(int v : ch)
            dp[u][0] = (dp[u][0] * ((dp[v][0] + dp[v][1]) % MOD)) % MOD;
        
        dp2[0][0] = (dp[ch[0]][0] + dp[ch[0]][1]) % MOD;
        dp2[0][1] = dp[ch[0]][1];

        for(int j = 1;j < ch.size();j++)
        {
            dp2[j][0] = (((dp[ch[j]][0] + dp[ch[j]][1]) % MOD) * dp2[j - 1][0]) % MOD;
            dp2[j][1] = (((dp[ch[j]][0] + dp[ch[j]][1]) % MOD) * dp2[j - 1][1]) % MOD
                    + (dp[ch[j]][1] * dp2[j - 1][0]) % MOD;
        }

        dp[u][1] = dp2[ch.size() - 1][1];
    }
}

int main()
{
    read();
    computeValue(0, -1);
    cout<<dp[0][1] % MOD<<"\n";
    return 0;
}