#include<iostream>
#include<vector>

using namespace std;

int l, r;
vector<long long int> tt; // two threes

void generate()
{
    long long int x = 2;
    int idx;
    tt.push_back(1);
    while(x <= 2000000000ll)
    {
        tt.push_back(x);
        x *= 2;
    }
    idx = tt.size();
    x = 3;
    while(x <= 2000000000ll)
    {
        tt.push_back(x);
        x *= 3;
    }
    int i, j;
    int n = tt.size();
    for(i = 1;i < idx;i++)
    {
        for(j = idx;j < n;j++)
        {
            if(tt[i] * tt[j] > 2000000000ll)
                break;
            tt.push_back(tt[i] * tt[j]);
        }
    }
}

void solve()
{
    int ans = 0;
    for(long long int x : tt)
    {
        if(x >= l && x <= r)
            ans++;
    }
    cout<<ans<<"\n";
}

int main()
{
    cin>>l>>r;
    generate();
    solve();
    return 0;
}