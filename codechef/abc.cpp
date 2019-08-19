#include<iostream>
#include<set>

using namespace std;

set<long long int> st;
long long int x, s, l, r;
int n, q;

void reset()
{
    st.clear();
    s = 0;
}

long long int solve()
{
    while(r >= l)
    {
        if(st.find(r) == st.end())
            return r;
        r--;
    }

    return 0;
}

void read_solve()
{
    int qu;
    long long int ans;
    cin>>n>>q;

    for(int i = 0;i < q;i++)
    {
        cin>>qu;

        if(qu == 1)
        {
            cin>>x;
            x += s;
            st.insert(x);
        }
        else
        {
            cin>>l>>r;
            l += s;
            r += s;
            ans = solve();
            s = (s + ans % n) % n;
            cout<<ans<<"\n";
        }
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        reset();
        read_solve();
    }
    return 0;
}