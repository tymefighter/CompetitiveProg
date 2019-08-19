#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int n, m, q;
vector<int> qy, arr, no; // queries, input array, number of indices with value i
vector<pair<int, int> > a;
set<int> st;

/*
    This is not yet solved,

    learn either of the following before: -

    - tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
    - Cartesian tree "treap"
    - 
*/


void reset()
{
    qy.resize(q);
    no.assign(m+1, 0);
    arr.assign(m, 0);
}

void read()
{
    cin>>n>>m>>q;
    reset();

    int i, x;
    for(i = 0;i < n;i++)
    {
        cin>>x;
        x--;
        arr[x] ++;
    }

    for(i = 0;i < q;i++)
        cin>>qy[i];

    for(i = 0;i < m;i++)
    {
        a.push_back({arr[i], i});
        no[arr[i]] ++;
    }

    sort(qy.begin(), qy.end());
    sort(a.begin(), a.end());
}

void solve()
{
    int s = 0, i, j, sum_j, id, index;

    id = j = 0;
    sum_j = no[0];
    for(int k : qy)
    {
        while(j <= m && s + sum_j <= k)
        {
            while(id < a.size() && a[id].first == j)
            {
                st.insert(a[id].second);
                id++;
            }

            s += sum_j;
            j++;
            sum_j += no[j];
        }

        if(j == m+1)
        {
            cout<< (k - s) % m;
            continue;
        }

        index = k - s;
        auto it = st.begin() + (k - s);
        
    }
}

int main()
{
    read();


    return 0;
}