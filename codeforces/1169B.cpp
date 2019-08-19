#include<iostream>
#include<utility>

using namespace std;

int n, m;
pair<int, int> a[300005];

void read()
{
    cin>>n>>m;
    for(int i = 0;i < m;i++)
        cin>>a[i].first>>a[i].second;
}

bool in_pair(int val, int i)
{
    if(val == a[i].first || val == a[i].second)
        return true;
    
    return false;
}

bool in_pair2(int val1, int val2, int i)
{
    if(val1 == a[i].first || val1 == a[i].second || val2 == a[i].first || val2 == a[i].second)
        return true;
    
    return false;
}

int checkAlone(int x)
{
    int i = 1;
    while(i < m && in_pair(x, i))
        i++;
    
    return i;
}

bool checkPair(int x, int y, int i)
{
    while(i < m && in_pair2(x, y, i))
        i++;
    

    return i == m;
}

bool solve()
{
    int x, i;
    
    x = a[0].first;
    i = checkAlone(x);
    if(i == m)
        return true;

    
    if(checkPair(x, a[i].first, i))
        return true;
    
    if(checkPair(x, a[i].second, i))
        return true;

    x = a[0].second;
    i = checkAlone(x);
    if(i == m)
        return true;

    if(checkPair(x, a[i].first, i))
        return true;
    
    if(checkPair(x, a[i].second, i))
        return true;
    
    return false;
}

int main()
{
    read();
    if(solve())
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}