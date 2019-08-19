#include<iostream>
#include<algorithm>

using namespace std;

int n;
char a[100005];

void read_solve()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>a[i];
    sort(a, a + n);

    for(int i = 0;i < n;i++)
        cout<<a[i];
    cout<<"\n";
}

int main()
{
    read_solve();
    return 0;
}