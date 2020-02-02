#include<iostream>
#include<cmath>

using namespace std;

long long A, B;
long long xb;

void solve()
{
    long long pw = 10, b, pw_val;
    xb = 0;
    pw_val = 1;

    while(pw - 1 <= B)
    {
        b = pw - 1;
        if(((long long)log10(b)) + 1 == pw_val)
            xb ++;

        pw *= 10;
        pw_val ++;
    }

    cout<<A * xb<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>A>>B;
        solve();
    }

    return 0;
}