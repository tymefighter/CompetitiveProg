#include<iostream>
#include<cmath>

using namespace std;


int n, m, a, b;
int lgn, lgm;
int st[12][3002][12][3002]; // sparse table
int arr[3002][3002];

void read()
{
    cin>>n>>m>>a>>b;
    lgn = log2(n), lgm = log2(m);

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
            cin>>arr[i][j];
    }
}

void fill_table()
{
    int jr, ir, jc, ic;

    for(ir = 0;ir < n;ir++)
    {
        for(ic = 0;ic < m;ic++)
            st[0][ir][0][ic] = arr[ir][ic];
        
        for(jc = 1;jc <= lgm;jc++)
        {
            for(ic = 0;ic < m;ic++)
                st[0][ir][jc][ic] = min(st[0][ir][jc - 1][ic], st[0][ir][jc - 1][(int)(ic + pow(2, jc - 1))]);
        }
    }

    for(jr = 1;jr <= lgn;jr++)
    {
        for(ir = 0;ir < n;ir++)
        {
            for(jc = 1;jc <= lgm;jc++)
            {
                for(ic = 0;ic < m;ic++)
                    st[jr][ir][jc][ic] = min(st[jr - 1][ir][jc][ic], st[jr - 1][(int)(ir + pow(2, jr - 1))][jc][ic]);
            }
        }
    }
}

int query(int r1, int c1, int r2, int c2)
{
    int kr = log2(r2 - r1 + 1);
    int kc = log2(c2 - c1 + 1);

    int val1 = min(st[kr][r1][kc][c1], st[kr][r1][kc][(int)(c2 - pow(2, kc) + 1)]);
    int val2 = min(st[kr][(int)(r2 - pow(2, kr) + 1)][kc][c1], st[kr][(int)(r2 - pow(2, kr) + 1)][kc][(int)(c2 - pow(2, kc) + 1)]);

    return min(val1, val2);
}

void solve()
{
    int r, c;
    long long int ans = 0;

    for(r = 0;r < n;r++)
    {
        if(r + a >= n)
            break;
        for(c = 0;c < m;c++)
        {
            if(c + b >= m)
                break;

            ans += query(r, r + a, c, c + b) * 1ll;
        }
    }

    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}