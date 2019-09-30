#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<pair<int, string> > a;
char str[1005];

void read()
{
    a.resize(n);
    int min, sec, mili;
    for(int i = 0;i < n;i++)
    {
        scanf("%s : %d min %d sec %d ms", str, &min, &sec, &mili);
        a[i].second = str;
        a[i].first = (60 * min + sec) * 1000 + mili;
    }
}

string lower(string x)
{
    for(int i = 0;i < x.size();i++)
        x[i] = tolower(x[i]);
    return x;
}

bool comp(pair<int, string> p1, pair<int, string> p2)
{
    if(p1.first != p2.first)
        return p1.first < p2.first;
    else
        return lower(p1.second) < lower(p2.second);
}

void solve()
{
    sort(a.begin(), a.end(), comp);
    int row = 1;

    for(int i = 0;i < n;i += 2)
    {
        printf("Row %d\n", row);
        cout<<a[i].second<<"\n";
        if(i + 1 < n)
            cout<<a[i + 1].second<<"\n";
        row ++;
    }
    cout<<"\n";
}

int main()
{
    while(cin>>n)
    {
        read();
        solve();
    }
    return 0;
}