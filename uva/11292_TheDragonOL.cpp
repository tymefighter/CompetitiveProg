#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int dr[20001], kn[20001];

void read()
{
    int i;
    for(i = 0;i < n;i++)
        cin>>dr[i];

    for(i = 0;i < m;i++)
        cin>>kn[i];

    sort(dr, dr+n);
    sort(kn, kn+m);
}


int solve()
{
    int i, j, ans = 0;

    i = j = 0;

    while(i < n && j < m)
    {
        if(dr[i] <= kn[j])
        {
            i++;
            ans += kn[j];
            j++;
        }
        else
            j++;
    }

    if(i == n)
        return ans;
    else
        return -1;    
}


int main()
{
    int ans;
    while(cin>>n>>m)
    {
        if((n | m) == 0)
            break;

        read();
        ans = solve();
        if(ans < 0)
            cout<<"Loowater is doomed!\n";
        else
            cout<<ans<<"\n";
    }

    return 0;
}