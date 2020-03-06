#include<iostream>
#include<cmath>

using namespace std;

const int N = 100005;
int n, m, q, phi_m[105]; // phi_m[i] : i times application of phi function on m
int w[N], just_next_one[N];

void computePhiM()
{
    for(int i = 0;i < 105;i++)
        phi_m[i] = 1;

    phi_m[0] = m;
    int idx = 1, m_val = m;
    while(m_val != 1)
    {
        int m_temp = m_val;
        phi_m[idx] = m_val;

        for(int i = 2;i * i <= m_temp;i++)
        {
            if(m_temp % i)
                continue;
            
            while(m_temp % i == 0)
                m_temp /= i;

            phi_m[idx] -= phi_m[idx] / i;
        }

        if(m_temp != 1)
            phi_m[idx] -= phi_m[idx] / m_temp;
        
        m_val = phi_m[idx];
        idx ++;
    }
}

void computeJustNextOne()
{
    int next_one = -1;
    for(int i = n - 1;i >= 0;i--)
    {
        if(w[i] == 1)
            next_one = i;
        
        just_next_one[i] = next_one;
    }
}

long long bin_exp(long long x, long long pw, long long mod_val)
{
    if(pw == 0)
        return 1;
    else if(pw % 2)
    {
        if(mod_val != -1)
            return (bin_exp(x, pw - 1, mod_val) * x) % mod_val;
        else
            return bin_exp(x, pw - 1, mod_val) * x;
    }
    else
    {
        long long val = bin_exp(x, pw / 2, mod_val);
        if(mod_val != -1)
            return (val * val) % mod_val;
        else
            return val * val;
    }
}

bool checkUsePhi(int i, int j, int value)
{
    if(i > j)
        return false;

    double val = (double)value;
    for(int k = i;k <= j;k++)
    {
        if((double) w[k] >= val)
            return true;

        val = log2(val) / log2((double) w[k]);
    }

    if(1 >= val)
        return true;
    else
        return false;
}

// i: current left index, j: final index, num: number of applications of phi on m
// for wi .. wj
long long computePow(int i, int j, int num, bool use_phi)
{
    if(use_phi && phi_m[num] == 1)
        return w[i] % phi_m[num - 1];

    long long pw;

    if(use_phi && checkUsePhi(i + 1, j, phi_m[num]))
        pw = (i < j ? computePow(i + 1, j, num + 1, true) : 1) + (long long) phi_m[num];
    else
        pw = (i < j ? computePow(i + 1, j, num + 1, false) : 1);

    if(use_phi)
        return bin_exp(w[i] % phi_m[num - 1], pw, phi_m[num - 1]);
    else
        return bin_exp(w[i], pw, -1);
}

int main()
{
    scanf("%d%d",&n, &m);
    computePhiM();
    
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &w[i]);
        just_next_one[i] = -1;
    }
    computeJustNextOne();
    
    scanf("%d", &q);
    while(q--)
    {
        int l, r;
    
        scanf("%d%d", &l, &r);
        l --, r --;
        if(w[l] == 1)
            printf("%d\n", 1 % m);
        else
        {
            if(just_next_one[l] != -1 && just_next_one[l] <= r)
                r = just_next_one[l] - 1;

            printf("%lld\n", computePow(l, r, 1, true)); // Now l ... r has only non-ones
        }
    }
    return 0;
}