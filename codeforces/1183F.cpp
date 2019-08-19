#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int b[200005];
vector<int> a;

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>b[i];
    sort(b, b + n);

    a.clear();
    a.push_back(b[0]);
    for(int i = 1;i < n;i++)
    {
        if(b[i] != b[i - 1])
            a.push_back(b[i]);
    }
}

void solve()
{
    if(a.size() == 1)
    {
        cout<<a[0]<<"\n";
        return;
    }

    int x, y, z, ans, i, val1, val2;

    x = y = z = -1;
    
    val1 = x = a[a.size() - 1];

    for(i = a.size() - 2;i >= 0;i--)
    {
        if(x % a[i] != 0)
        {
            if(y == -1)
            {
                y = a[i];
                val1 += y;
            }
            else if(y % a[i] != 0)
            {
                z = a[i];
                val1 += z;
                break;
            }
        }
    }

    x = y = z = -1;
    
    val2 = x = a[a.size() - 2];

    for(i = a.size() - 3;i >= 0;i--)
    {
        if(x % a[i] != 0)
        {
            if(y == -1)
            {
                y = a[i];
                val2 += y;
            }
            else if(y % a[i] != 0)
            {
                z = a[i];
                val2 += z;
                break;
            }
        }
    }

    cout<<max(val1, val2)<<"\n";
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        read();
        solve();
    }
    return 0;
}