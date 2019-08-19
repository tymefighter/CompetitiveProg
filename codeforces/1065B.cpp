#include<iostream>

using namespace std;

long long int n, m;
long long int max_val, min_val;
// are the number of edges greater than the complete graph on r verts and less than complete
// graph on r + 1 verts 
bool check(long long int r)
{
    long long int val1 = (r * (r - 1)) / 2;
    long long int val2 = (r * (r + 1)) / 2;

    if(val1 < m && m <= val2)
        return true;
    
    return false;
}

void solve()
{
    cin>>n>>m;

    if(m == 0)
    {
        cout<<n<<" "<<n<<"\n";
        return;
    }

    max_val = min(2 * m, n);

    for(long long int r = 0;r < n;r++)
    {
        if(check(r))
        {
            min_val = r + 1;
            break;
        }
    }

    cout<<n - max_val<<" "<<n - min_val<<"\n";
}

int main()
{
    solve();
    return 0;
}