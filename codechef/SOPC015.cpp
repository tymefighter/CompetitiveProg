#include<iostream>
#include<vector>

using namespace std;

const int N = 1200005;
int n;
vector<vector<int> > a;
int deg[N];
bool vis[N];

void reset()
{
    a.clear();
    a.resize(n);

    for(int i = 0;i < n;i++)
    {
        deg[i] = 0;
        vis[i] = false;
    }
}

void read()
{
    int u, v;
    for(int i = 0;i < n - 1;i++)
    {
        cin>>u>>v;
        u --, v --;
        deg[u] ++, deg[v] ++;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

bool isPrime(int x)
{

}

bool solve()
{
    int root = -1, int prime_ct = 0;
    for(int i = 0;i < n;i++)
    {
        if(isPrime(a[i].size()))
        {
            root = i;
            prime_ct ++;
            if(prime_ct )
        }
    }
}

int main()
{
    cin>>n;
    reset();
    read();
    return 0;
}