#include<iostream>

using namespace std;

int n;
// dp1[i]: length of longest non-dec subseq in 1..i
// dp2[i]: length of longest non-dec subseq in i..(n-1)
int dp1[100005], dp2[100005];
// numZero[i]: num of zeros in 1..i
// numOne[i] : num of ones in i..(n-1)
int numZero[100005], numOne[100005];
string s;
int maxVal;

void build_dp()
{
    int i;
    dp1[0] = 1;
    numZero[0] = (s[0] == '0' ? 1 : 0);

    for(i = 1;i < n;i++)
    {
        if(s[i] == '0')
        {
            numZero[i] = numZero[i - 1] + 1;
            dp1[i] = max(dp1[i - 1], numZero[i]);
        }
        else
        {
            numZero[i] = numZero[i - 1];
            dp1[i] = dp1[i - 1] + 1;
        }
    }

    dp2[n - 1] = 1;
    numOne[n - 1] = (s[n - 1] == '1' ? 1 : 0);

    for(i = n - 2;i >= 0;i--)
    {
        if(s[i] == '1')
        {
            numOne[i] = numOne[i + 1] + 1;
            dp2[i] = max(dp2[i + 1], numOne[i]);
        }
        else
        {
            numOne[i] = numOne[i + 1];
            dp2[i] = dp2[i + 1] + 1;
        }
    }

    maxVal = dp1[n - 1];
}

void solve()
{
    int val;
    for(int i = 0;i < n;i++)
    {
        if(s[i] == '0')
            continue;
        val = max((i > 0 ? dp1[i - 1] : 0) + (i < n - 1 ? numOne[i + 1] : 0), (i > 0 ? numZero[i - 1] : 0) + 1 + (i < n - 1 ? dp2[i + 1] : 0));
        if(val == maxVal)
            s[i] = '0';
    }
    cout<<s<<"\n";
}

int main()
{
    cin>>s;
    n = s.size();
    build_dp();
    solve();
    return 0;
}