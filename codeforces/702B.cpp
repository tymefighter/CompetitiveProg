#include<iostream>
#include<map>

using namespace std;

map<long long int, long long int> m;
int n, no;
long long int a[100005], pw[50];

void generate()
{
    long long int x = 2;
    int i = 0;

    while(x < 2000000000)
    {
        pw[i] = x;
        x *= 2;
        i++;
    }
    no = i;
}

void read_solve()
{
    int i, j;
    long long int ans = 0, x;
    m.clear();
    cin>>n>>x;
    m[x] = 1;

    for(i = 1;i < n;i++)
    {
        cin>>x;
        for(j = 0;j < no;j++)
        {
            if(m.find(pw[j] - x) != m.end())
                ans += m[pw[j] - x];
        }
        m[x]++;
    }

    cout<<ans<<"\n";
}


int main()
{
    generate();
    read_solve();
    return 0;
}