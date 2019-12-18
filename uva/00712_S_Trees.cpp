#include<iostream>

using namespace std;

int n, order[7];
char a[256], vaa[7];

void read()
{
    string s;

    for(int i = 0;i < n;i++)
    {
        cin>>s;
        order[i] = s[1] - '1';
    }

    for(int i = (1 << n);i < (1 << (n + 1));i++)
        cin>>a[i];
}

void getAns()
{
    int idx = 1;
    
    for(int i = 0;i < n;i++)
    {
        if(vaa[order[i]] == '1')
            idx = 2 * idx + 1;
        else
            idx = 2 * idx;
    }

    cout<<a[idx];
}

void solve()
{
    int m;
    cin>>m;

    while(m --)
    {
        for(int i = 0;i < n;i++)
            cin>>vaa[i];
        getAns();
    }
    cout<<"\n";
}

int main()
{
    int stree_no = 1;
    while(cin>>n)
    {
        if(!n)
            break;
        read();
        printf("S-Tree #%d:\n", stree_no);
        solve();
        stree_no ++;
        cout<<"\n";
    }
    return 0;
}