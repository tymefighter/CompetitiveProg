#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[100005], b[100005];

void read()
{
    cin>>n;

    for(int i = 0;i < n;i++)
        cin>>a[i];
}

void solve()
{
    sort(a, a + n);
    b[0] = 0;

    for(int i = 1 ;i < n;i++)
    {
        b[i] = b[i - 1] | a[i - 1];
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

    }

    return 0;
}