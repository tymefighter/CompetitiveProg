#include<iostream>
#include<vector>
#include<algorithm>

/*

    Not Solved !!!
*/

using namespace std;

int n, k;
vector<string> a;

void read()
{
    scanf("%d %d", &n, &k);
    a.clear();
    a.resize(n);
    for(int i = 0;i < n;i++)
        cin>>a[i];
}

int lcp(int i, int j)
{
    int len = min(a[i].size(), a[j].size());
    int val = 0;
    while(val < len && a[i][val] == a[j][val])
        val ++;
    return val;
}

void solve(int case_num)
{
    int ans = 0;
    sort(a.begin(), a.end());
    for(int i = 0;i < (n / k);i++)
        ans += lcp(i * k, (i + 1) * k - 1);
    
    cout<<"Case #"<<case_num<<": "<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        read();
        solve(i);
    }
    return 0;
}