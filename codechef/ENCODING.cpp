#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const long long int MOD = 1000000007;
long long int dp[100005][10];
int nl, nr;
string l, r;

string subOne(string str1) 
{ 
    string str2 = "1";
    string str = ""; 
    int n1 = str1.length(), n2 = 1; 
    reverse(str1.begin(), str1.end()); 
    int carry = 0; 
    for (int i=0; i<n2; i++) 
    {
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
        str.push_back(sub + '0'); 
    } 
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
        str.push_back(sub + '0'); 
    } 
    reverse(str.begin(), str.end()); 
    return str; 
}

long long int pow(int n)
{
    if(n == 0)
        return 1;
    if(n % 2)
        return (pow(n - 1) * 10) % MOD;
    else
    {
        long long int val = pow(n / 2);
        return (val * val) % MOD;
    }
}

void solve()
{
    int i, dig, dig2;
    for(dig = 0;dig <= 9;dig++)
        dp[0][dig] = dig;

    for(i = 1;i < nr;i++)
    {
        for(dig = 0;dig <= 9;dig++)
        {
            dp[i][dig] = - ((dig * pow(i - 1) * pow(max(i - 2, 0))) % MOD);

            for(dig2 = 0;dig2 <= 9;dig2++)
                dp[i][dig] = (dp[i][dig] + dp[i - 1][dig2] + dig * pow(i)) % MOD;
        }
    }

    reverse(r.begin(), r.end());
    reverse(l.begin(), l.end());

    int prev = -1, dig_val;
    long long int val, val2, ans_left, ans_right;

    ans_right = val = 0;
    for(i = nr - 1;i >= 0;i--)
    {
        dig_val = (r[i] - '0');

        if(i == 0)
        {
            for(dig = 0;dig <= dig_val;dig++)
            {
                if(prev != dig)
                    val2 = (val + dig) % MOD;
                else
                    val2 = val;

                cout<<i<<" "<<dig<<" "<<val2<<" --\n";
                ans_right = (ans_right + val2) % MOD;
            }
            continue;
        }

        for(dig = 0;dig < dig_val;dig++)
        {
            if(dig != prev)
                val2 = (val + dig * pow(i)) % MOD;
            else
                val2 = val;
            
            cout<<i<<" "<<dig<<" "<<dig * pow(i - 1) * pow(max(i - 2, 0))<<" "<<val2<<" --\n";
            ans_right = (ans_right - dig * pow(i - 1) * pow(max(i - 2, 0))) % MOD;

            for(dig2 = 0;dig2 <= 9;dig2++)
                ans_right = (ans_right + (dp[i - 1][dig2] + val2)) % MOD;
        }

        if(dig_val != prev)
            val = (val + dig_val * pow(i)) % MOD;
        prev = dig_val;
    }

    prev = -1;
    ans_left = val = 0;
    for(i = nl - 1;i >= 0;i--)
    {
        dig_val = (l[i] - '0');

        if(i == 0)
        {
            for(dig = 0;dig <= dig_val;dig++)
            {
                if(prev != dig)
                    val2 = (val + dig) % MOD;
                else
                    val2 = val;

                ans_left = (ans_left + val2) % MOD;
            }
            continue;
        }

        for(dig = 0;dig < dig_val;dig++)
        {
            if(dig != prev)
                val2 = (val + dig * pow(i)) % MOD;
            else
                val2 = val;
            
            ans_left = (ans_left - dig * pow(i - 1) * pow(max(i - 2, 0))) % MOD;

            for(dig2 = 0;dig2 <= 9;dig2++)
                ans_left = (ans_left + (dp[i - 1][dig2] + val2)) % MOD;
        }

        if(dig_val != prev)
            val = (val + dig_val * pow(i)) % MOD;
        prev = dig_val;
    }

    long long int ans = (ans_right - ans_left) % MOD;
    if(ans < 0)
        ans += MOD;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>nl>>l;
        cin>>nr>>r;
        l = subOne(l);
        solve();
    }
    return 0;
}