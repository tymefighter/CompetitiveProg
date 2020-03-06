#include<iostream>
#include<vector>

using namespace std;

// The complexity of this solution is n * 30
// because a number can occur atmost 30 times
// since it would only occur if each of the previous
// bit positions match. The number can have
// atmost 30 bits, so we can match only those
// many of them
long long solve(vector<long long> a, int bit)
{
    if(a.size() == 0 || bit < 0)
        return 0;

    vector<long long> o, z; // one, zero

    for(long long x : a)
    {
        if(x & (1 << bit))
            o.push_back(x);
        else
            z.push_back(x);
    }

    if(o.size() == 0)
        return solve(z, bit - 1);
    if(z.size() == 0)
        return solve(o, bit - 1);

    return min(solve(o, bit - 1), solve(z, bit - 1)) + (1 << bit);
}

int main()
{
    int n;
    vector<long long> a;
    cin>>n;
    a.resize(n);
    for(int i = 0;i < n;i++)
        cin>>a[i];
    
    cout<<solve(a, 30)<<"\n";
    return 0;
}