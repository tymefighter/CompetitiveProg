#include<iostream>

using namespace std;

int n, prev_occ[26];

void reset()
{
    for(int i = 0;i < 26;i++)
        prev_occ[i] = -1;
}

void read_solve()
{
    cin>>n;

    int ans = 0;
    char x;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        if(prev_occ[x - 'a'] == -1)
        {
            prev_occ[x - 'a'] = i;
            continue;
        }

        ans = max(ans, n + prev_occ[x - 'a'] - i);
        prev_occ[x - 'a'] = i;
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
        read_solve();
    }
    return 0;
}