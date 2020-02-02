#include<iostream>
#include<vector>

using namespace std;

const int N = 2005;
int n, root, a[N], c[N], num_nodes_subtree[N];
vector<vector<int> > t;

void read()
{
    cin>>n;

    t.clear();
    t.resize(n);
    int parent_i;
    for(int i = 0;i < n;i++)
    {
        cin>>parent_i>>c[i];
        parent_i --;
        if(parent_i != -1)
            t[parent_i].push_back(i);
        else
            root = i;
    }
}

bool noAns;

void reAssignValue(int u, int addValue, int threshold)
{
    a[u] += addValue;
    if(a[u] > threshold)
        a[u] ++;
    
    for(int v : t[u])
        reAssignValue(v, addValue, threshold);
}

void assignValue(int u)
{
    if(t[u].size() == 0)
    {
        if(c[u] > 0)
            noAns = true;
        
        num_nodes_subtree[u] = 1;
        a[u] = 1;
        return;
    }

    num_nodes_subtree[u] = 1;

    for(int v : t[u])
    {
        assignValue(v);
        num_nodes_subtree[u] += num_nodes_subtree[v];
    }

    if(num_nodes_subtree[u] - 1 < c[u])
        noAns = true;

    int add_value = 0;
    for(int v : t[u])
    {
        reAssignValue(v, add_value, c[u]);
        add_value += num_nodes_subtree[v];
    }

    a[u] = c[u] + 1;
}

int main()
{
    read();
    noAns = false;
    assignValue(root);

    if(!noAns)
    {
        cout<<"YES\n";
        for(int i = 0;i < n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
    else
        cout<<"NO\n";
    return 0;
}