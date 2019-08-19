#include<iostream>
#include<string>
#include<algorithm>
#include<vector>


using namespace std;

int n;
string s, t, a, b;
vector<int> ans;

void read()
{
    cin>>n;
    cin>>s>>t;

    a = s, b = t;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

void solve()
{
    ans.clear();
    if(a != b)
    {
        cout<<"-1\n";
        return;
    }

    int i, j;
    for(i = 0;i < n;i++)
    {
        if(s[i] != t[i])
        {
            for(j = i + 1;j < n;j++)
            {
                if(s[j] == t[i])
                    break;
            }

            while(j > i)
            {
                ans.push_back(j);
                swap(s[j], s[j-1]);
                j--;
            }
        }
    }

    cout<<ans.size()<<"\n";
    for(int x : ans)
        cout<<x<<" ";
    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}