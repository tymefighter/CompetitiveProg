#include<iostream>
#include<unordered_map>
#include<vector>
#include<cassert>

using namespace std;

const int INF = 1e9;
int n, m, a[300005][8];
int low, high;

void read()
{
    int i, j;

    low = INF;
    high = -1;

    cin>>n>>m;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            cin>>a[i][j];
            low = min(a[i][j], low);
            high = max(a[i][j], high);
        }
    }
}

int getBitmask(int idx, int x)
{
    int bm = 0;
    for(int i = 0;i < m;i++)
    {
        if(a[idx][i] >= x)
            bm |= (1 << i);
    }

    return bm;
}

unordered_map<int, int> s;
vector<int> dist_bm;

pair<int, int> isAnsGEx(int x)
{
    s.clear();
    dist_bm.clear();

    for(int i = 0;i < n;i++)
    {
        int bm = getBitmask(i, x);
        if(s.find(bm) == s.end())
        {
            s[bm] = i;
            dist_bm.push_back(bm);
        }
    }

    int i, j;
    for(i = 0;i < dist_bm.size();i++)
    {
        for(j = i;j < dist_bm.size();j++)
        {
            if((dist_bm[i] | dist_bm[j]) == (1 << m) - 1)
                return {s[dist_bm[i]], s[dist_bm[j]]};
        }
    }

    return {-1, -1};
}

void solve()
{
    int mid, ans = -1;
    pair<int, int> ans_arr = {-1, -1}, val_arr;

    while(low <= high)
    {
        mid = (low + high) / 2;

        val_arr = isAnsGEx(mid);
        if(val_arr.first != -1)
        {
            if(mid > ans)
                ans_arr = val_arr;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    assert(ans_arr.first != -1 && ans_arr.second != -1);
    cout<<ans_arr.first + 1<<" "<<ans_arr.second + 1<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}