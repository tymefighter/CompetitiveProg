#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<pair<int, int> > a;

void read()
{
    cin>>n;
    a.resize(n);

    for(int i = 0;i < n;i++)
    {
        cin>>a[i].first;
        a[i].second = i+1;
    }
}

int check(int d)
{
    int idx = -1;
    int i;

    if((a[1].first - a[0].first != d) && (a[2].first - a[1].first == d))
    {
        idx = 0;
        for(i = 2;i < n;i++)
        {
            if(a[i].first - a[i-1].first != d)
                return -1;
        }

        return a[idx].second;
    }
    
    if((a[n - 1].first - a[n - 2].first != d) && (a[n - 2].first - a[n - 3].first == d))
    {
        idx = n - 1;
        for(i = 1;i < n - 1;i++)
        {
            if(a[i].first - a[i-1].first != d)
                return -1;
        }

        return a[idx].second;
    }

    for(i = 1;i < n - 1;i++)
    {
        if(a[i].first - a[i-1].first != d)
        {
            if(idx != -1)
                return -1;

            idx = i;
            if(a[i + 1].first - a[i - 1].first != d)
                return -1;
            i++;
        }
    }

    if(idx != -1)
        return a[idx].second;

    return a[0].second;
}

int solve()
{
    if(n <= 3)
        return 1;

    sort(a.begin(), a.end());

    int d1, d2, d3;
    d1 = a[1].first - a[0].first;
    d2 = a[2].first - a[1].first;
    d3 = a[3].first - a[2].first;

    int ans;
    
    ans = check(d1);
    if(ans != -1)
        return ans;

    ans = check(d2);
    if(ans != -1)
        return ans;

    ans = check(d3);
    return ans;
}

int main()
{
    read();
    cout<<solve()<<"\n";
    return 0;
}