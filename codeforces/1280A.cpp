#include<iostream>
#include<vector>
#include<map>

using namespace std;

const long long MOD = 1000000007;
int x, idx;
long long l;
string s;

void solve()
{
    l = s.length();
    idx = 1;

    bool string_size_done = false;
    string temp;
    int curr_size;
    long long len_temp;

    while(idx != x + 1)
    {
        len_temp = (idx + (s[idx - 1] - '0') * (l - idx)) % MOD;
        
        if(!string_size_done)
        {
            curr_size = s.size();


            for(int i = 0;i < (s[idx - 1] - '0') - 1;i++)
            {
                if(string_size_done)
                    break;
                
                for(int j = idx;j < curr_size;j++)
                {
                    char c = s[j];
                    if(s.length() >= x)
                    {
                        string_size_done = true;
                        break;
                    }

                    s.push_back(c);
                }
            }
        }

        idx ++;
        l = len_temp;
    }
    if(l < 0)
        l += MOD;
    cout<<l<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    int t;
    cin>>t;

    while(t--)
    {
        cin>>x>>s;
        solve();
    }
    return 0;
}