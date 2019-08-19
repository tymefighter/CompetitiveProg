#include<iostream>
#include<bitset>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

const int N = 182;
bitset<N> bs;
vector<int> primes;

string s;
stringstream ss;
stack<int> st;
int n;

void sieve()
{
    bs.set();
    bs[0] = bs[1] = false;

    long long int i, j;
    for(i = 2;i <= N;i++)
    {
        if(!bs[i])
            continue;
        for(j = i * i;j <= N;j += i)
            bs[j] = false;
        primes.push_back(i);
    }
}

void read()
{
    while(s[s.size() - 1] == ' ')
        s.pop_back();
    ss.clear();
    ss.str(s);

    int pf, pw;
    n = 1;
    while(!ss.eof())
    {
        ss >> pf >> pw;
        n *= pow(pf, pw);
    }
}

void solve()
{
    n--;
    int pf = primes[0], idx = 0, pw;
    while(idx < primes.size() && pf * (pf * 1ll) <= (n * 1ll))
    {
        if(n % pf)
        {
            idx++;
            if(idx >= primes.size())
                break;
            pf = primes[idx];
            continue;
        }
        pw = 0;
        while(n % pf == 0)
        {
            n /= pf;
            pw ++;
        }
        st.push(pw);
        st.push(pf);
        idx++;
        if(idx >= primes.size())
            break;
        pf = primes[idx];
    }

    if(n != 1)
    {
        st.push(1);
        st.push(n);
    }

    int i = 0;
    while(!st.empty())
    {
        if(i)
            cout<<" ";
        cout<<st.top();
        st.pop();
        i++;
    }
    cout<<"\n";
}

int main()
{
    sieve();
    while(getline(cin, s))
    {
        if(s[0] == '0')
            break;
        read();
        solve();
    }
    return 0;
}