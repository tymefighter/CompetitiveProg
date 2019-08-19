#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long int n, a, b;
int sm_dig_n0; // index of smallest digit not zero
vector<int> v;

void convert()
{
    long long int temp = n;
    v.clear();
    while(temp)
    {
        v.push_back(temp % 10);
        temp /= 10;
    }

    sort(v.begin(), v.end());
}

void solve()
{
    for(sm_dig_n0 = 0;sm_dig_n0 < n;sm_dig_n0++)
    {
        if(v[sm_dig_n0])
            break;
    }

    int i;
    long long int pw;
    pw = 1;
    a = 0;
    for(i = 0;i < v.size();i++)
    {
        a += v[i] * pw;
        pw *= 10;
    }

    pw = 1;
    b = 0;
    for(i = v.size() - 1;i >= 0;i--)
    {
        if(i == sm_dig_n0)
            continue;
        b += v[i] * pw;
        pw *= 10;
    }
    b += v[sm_dig_n0] * pw;

    printf("%lld - %lld = %lld = 9 * %lld\n", a, b, a - b, (a - b) / 9);
}

int main()
{
    while(cin>>n)
    {
        convert();
        solve();
    }
    return 0;
}