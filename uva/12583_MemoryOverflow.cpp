#include<iostream>
#include<map>

using namespace std;

int n, k;
char a[505];
map<char, int> m;

void read_solve(int cno)
{
    int ans = 0;
    m.clear();

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        if(i - (k + 1) >= 0)
            m[a[i - (k + 1)]] --;
        
        if(m[a[i]] > 0)
            ans ++;
        
        m[a[i]] ++;
    }

    printf("Case %d: %d\n", cno, ans);
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        cin>>n>>k;
        read_solve(i);
    }
    return 0;
}