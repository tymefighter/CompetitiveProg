#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<string, int> m;
vector<pair<int, int> > child_parent;
int n, parent[305];

void reset()
{
    for(int i = 0;i < n;i++)
        parent[i] = -1;
}

void read()
{
    string ch, pa;

    n = 0;
    m.clear();
    child_parent.clear();
    while(cin>>ch>>pa)
    {
        if(ch == "no.child" && pa == "no.parent")
            break;
        if(m.find(ch) == m.end())
            m[ch] = n ++;
        if(m.find(pa) == m.end())
            m[pa] = n ++;

        child_parent.push_back({m[ch], m[pa]});
    }

    reset();

    for(auto e : child_parent)
        parent[e.first] = e.second;
}

int checkAncestor(int p, int q)
{
    int ds = 0, par = p;

    while(par != -1)
    {
        if(par == q)
            return ds;
        
        par = parent[par];
        ds ++;
    }

    return -1;
}

int checkDescendent(int p, int q)
{
    return checkAncestor(q, p);
}

int distp[305], distq[305];

void resetDist()
{
    for(int i = 0;i < n;i++)
    {
        distp[i] = distq[i] = -1;
    }
}

pair<int, int> checkCousinSibling(int p, int q)
{
    resetDist();
    int ds = 0, par = p;
    while(par != -1)
    {
        distp[par] = ds;
        par = parent[par];
        ds ++;
    }
    ds = 0, par = q;
    while(par != -1)
    {
        distq[par] = ds;
        if(distp[par] >= 0)
            return {distp[par], distq[par]};

        par = parent[par];
        ds ++;
    }

    return {-1, -1};
}

void solve()
{
    string str_p, str_q;
    int p, q, val;
    pair<int, int> val_pair;
    while(cin>>str_p>>str_q)
    {
        if(m.find(str_p) == m.end()
            || m.find(str_q) == m.end())
        {
            printf("no relation\n");
            continue;
        }
        p = m[str_p], q = m[str_q];

        val = checkAncestor(p, q);
        if(val >= 0)
        {
            if(val == 1)
                cout<<"child\n";
            else
            {
                val -= 2;
                while(val--)
                    cout<<"great ";
                cout<<"grand child\n";
            }
            continue;
        }

        val = checkDescendent(p, q);
        if(val >= 0)
        {
            if(val == 1)
                cout<<"parent\n";
            else
            {
                val -= 2;
                while(val--)
                    cout<<"great ";
                cout<<"grand parent\n";
            }
            continue;
        }

        val_pair = checkCousinSibling(p, q);
        if(val_pair.first != -1 && val_pair.second != -1)
        {
            val_pair = {min(val_pair.first, val_pair.second) - 1, abs(val_pair.first - val_pair.second)};
            if(!val_pair.first && !val_pair.second)
                cout<<"sibling\n";
            else if(!val_pair.second)
                printf("%d cousin\n", val_pair.first);
            else
                printf("%d cousin removed %d\n", val_pair.first, val_pair.second);
            continue;
        }

        printf("no relation\n");
    }
}

int main()
{
    read();
    solve();
    return 0;
}