#include<iostream>
#include<set>
#include<vector>

using namespace std;

int q, x;
int even, odd;
set<int> s;
vector<int> a;

void reset()
{
    even = odd = 0;
    s.clear();
    a.clear();
}

bool parity(int val)
{
    bool odd = false;
    for(int i = 1;i <= val;i = (i << 1))
    {
        if(val & i)
            odd = !odd;
    }

    // cout<<val<<" "<<odd<<"\n";

    return odd;
}

void read_solve()
{
    cin>>q;

    int val, end;
    while(q--)
    {
        cin>>x;
        if(s.find(x) != s.end())
        {
            cout<<even<<" "<<odd<<"\n";
            continue;
        }

        end = a.size();


        for(int i = 0;i < end;i++)
        {
            val = a[i] ^ x;

            if(s.find(val) != s.end())
                continue;
            if(parity(val))
                odd++;
            else
                even++;
            s.insert(val);
            a.push_back(val);
        }

        s.insert(x);
        a.push_back(x);
        if(parity(x))
            odd++;
        else
            even++;
        cout<<even<<" "<<odd<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--)
    {
        reset();
        read_solve();
    }
    return 0;
}