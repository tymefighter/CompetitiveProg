#include<iostream>
#include<algorithm>
#include<cassert>

using namespace std;

const int N = 200005;
long long MOD = 1e9 + 7, INF = 1e12;
int n;
long long a[N], sum_val, fact_mod[N + 1];
pair<long long, long long> p[N];

void generateFac()
{
    fact_mod[0] = fact_mod[1] = 1;
    for(int i = 2;i <= N;i++)
        fact_mod[i] = (fact_mod[i - 1] * i) % MOD;
}

void read()
{
    cin>>n;
    sum_val = 0;
    for(int i = 0;i < 2 * n;i++)
    {
        cin>>a[i];
        sum_val += a[i];
    }
}

long long pw(long long x, long long y)
{
    if(y == 0)
        return 1;
    else if(y % 2 == 1)
        return (pw(x, y - 1) * x) % MOD;
    else
    {
        long long val = pw(x, y / 2);
        return (val * val) % MOD;
    }
}

// We must handle n = 1 seperately
bool solve()
{
    if(n == 1)
    {
        if(a[0] != a[1])
            return false;
        cout<<"1\n";
        return true;
    }

    if(sum_val % (n + 1) != 0)
        return false;
    sum_val /= (n + 1);

    int i, sum_val_count = 0;
    for(i = 0;i < 2 * n;i++)
    {
        if(a[i] == sum_val)
        {
            a[i] = INF;
            sum_val_count ++;

            if(sum_val_count == 2)
                break;
        }
    }

    if(sum_val_count < 2)
        return false;

    sort(a, a + 2 * n);
    int front_ptr = 0, back_ptr = 2 * n - 3;

    i = 0;
    while(front_ptr < back_ptr)
    {
        if(a[front_ptr] + a[back_ptr] == sum_val)
        {
            p[i] = {a[front_ptr], a[back_ptr]};
            i ++;
            front_ptr ++;
            back_ptr --;
        }
        else if(a[front_ptr] + a[back_ptr] < sum_val)
            return false;
        else if(a[front_ptr] + a[back_ptr] > sum_val)
            return false;
    }

    int fst_sec_diff = 0;
    for(i = 0;i < n - 1;i++)
    {
        if(p[i].first != p[i].second)
            fst_sec_diff ++;
    }

    long long ans = (pw(2, fst_sec_diff) * fact_mod[n - 1]) % MOD;

    sort(p, p + n - 1);

    int ct = 1;
    for(i = 1;i < n - 1;i++)
    {
        if(p[i].first == p[i - 1].first && p[i].second == p[i - 1].second)
            ct ++;
        else
        {
            ans = (ans * pw(fact_mod[ct], MOD - 2)) % MOD;
            ct = 1;
        }
    }

    ans = (ans * pw(fact_mod[ct], MOD - 2)) % MOD;
    cout<<ans<<"\n";

    assert(ans >= 0);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    generateFac();

    int t;
    cin>>t;
    while(t--)
    {
        read();
        if(!solve())
            cout<<"0\n";
    }
    return 0;
}
