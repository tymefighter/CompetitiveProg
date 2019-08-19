#include<iostream>
#define MAX 100000000

using namespace std;

int n, k;
char s[2005];
char arr[3] = {'R', 'G', 'B'};

void read()
{
    cin>>n>>k;

    for(int i = 0;i < n;i++)
        cin>>s[i];
}

void solve()
{
    int ans = MAX;
    int i, j, r, changes;
    for(i = 0;i <= n - k;i++)
    {
        for(r = 0;r < 3;r++)
        {
            changes = 0;
            if(s[i] != arr[r])
                changes = 1;
            
            for(j = 1;j < k;j++)
            {
                if(s[i + j] != arr[(r + j) % 3])
                    changes++;
            }
            ans = min(ans, changes);
        }
    }

    cout<<ans<<"\n";
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