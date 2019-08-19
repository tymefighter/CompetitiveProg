#include<iostream>
#include<string>

using namespace std;

int n;
int cf[100001];
string s;

void cumulativeSum()
{
    for(int i = 0;i <= n - 2;i++)
        cf[i] = (s[i] == s[i+1] ? 1 : 0) + (i > 0 ? cf[i-1] : 0);
}

int main()
{
    int q, a, b;
    cin>>s>>q;

    n = s.size();
    cumulativeSum();

    while(q--)
    {
        cin>>a>>b;
        a--,b--;
        cout<<cf[b-1] - (a > 0 ? cf[a-1] : 0)<<'\n';
    }
    return 0;
}