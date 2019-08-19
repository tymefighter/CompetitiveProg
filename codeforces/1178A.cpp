#include<iostream>
#include<vector>

using namespace std;

int n, val;
int a[105];
vector<int> ans;

void read()
{
    cin>>n;
    val = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        val += a[i];
    }

    val /= 2;
}

void solve()
{
    int sum = a[0], i = 1;
    ans.push_back(1);
    while(i < n && sum <= val)
    {
        if(a[i] <= a[0] / 2)
        {
            sum += a[i];
            ans.push_back(i+1);
        }
        i++;
    }

    if(sum <= val)
        cout<<"0\n";
    else
    {
        cout<<ans.size()<<"\n";
        for(int x : ans)
            cout<<x<<" ";
        cout<<"\n";
    }
}

int main()
{
    read();
    solve();
    return 0;
}