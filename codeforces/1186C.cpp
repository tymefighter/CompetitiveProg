#include<iostream>
#include<string>

using namespace std;

string a, b;

void solve()
{
    int k = b.size(), num_diff = 0, ans = 0;
    int i;
    for(i = 0;i < k;i++)
        num_diff += (a[i] == b[i] ? 0 : 1);
    
    if(num_diff % 2 == 0)
        ans ++;
    
    for(i = k;i < a.size();i++)
    {
        if(a[i - k] != b[0])
            num_diff --;
        
        if(a[i] != b[k - 1])
            num_diff ++;

        if(num_diff % 2 == 0)
            ans ++;
    }

    cout<<ans<<"\n";
}

int main()
{
    cin>>a>>b;
    solve();
    return 0;
}