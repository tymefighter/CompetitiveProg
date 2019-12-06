#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> a;

void read()
{
    int prev, x;
    
    cin>>n;
    cin>>prev;

    a.clear();
    a.push_back(1);

    for(int i = 1;i < n;i++)
    {
        cin>>x;
        if(x != prev)
        {
            a.push_back(1);
            prev = x;
        }
        else
            a[a.size() - 1] ++;
    }
}

bool solve()
{
    if(a.size() < 3)
        return false;
    
    int idx = -1, sum = 0;
    for(int i = 0;i < a.size();i++)
    {
        sum += a[i];
        if(idx == -1 && sum > (n / 2))
        {
            sum -= a[i];
            idx = i - 1;
            break;
        }
    }

    if(idx < 2)
        return false;
    
    int g = a[0], s = 0, b;
    sum -= a[0];

    for(int i = 1;i <= idx;i++)
    {
        s += a[i];
        b = sum - s;
        if(s > g && b > g)
        {
            cout<<g<<" "<<s<<" "<<b<<"\n";
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        if(!solve())
            cout<<"0 0 0\n";
    }
    return 0;
}