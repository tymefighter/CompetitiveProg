#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#define MAX 100000000

using namespace std;

int n;
vector<vector<int> > a;
vector<pair<int, int> > e; // edges along the diameter
int dist1[3005], dist2[3005], pred[3005];
int ds, de;

void reset()
{
    a.clear();
    e.clear();

    a.resize(n);
}

void read()
{
    cin>>n;
    reset();

    int x, y;
    for(int i = 0;i < n - 1;i++)
    {
        cin>>x>>y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

pair<int, int> edge;

void dfs(int u, int *dist, bool set_pred)
{
    // cout<<u<<" "<<dist[u]<<" -------\n";
    for(int v : a[u])
    {
        if(dist[v] == -1)
        {
            // cout<<v<<" ||"<<"\n";
            if((edge.first == u && edge.second == v) || (edge.first == v && edge.second == u))
            {
                dist[v] = -2;
                continue;
            }


            if(set_pred)
                pred[v] = u;
            dist[v] = dist[u] + 1;
            dfs(v, dist, set_pred);
        }
    }
}

void reset_arr(int *dist)
{
    for(int i = 0;i < n;i++)
        dist[i] = -1;
}

void find_diameter(int &st, int &end, bool set_pred = false, int start = 0)
{
    reset_arr(dist1);
    dist1[start] = 0;
    dfs(start, dist1, false);
    int i, val = dist1[start];
    st = start;
    for(i = 0;i < n;i++)
    {
        if(dist1[i] > val)
        {
            val = dist1[i];
            st = i;
        }
    }

    reset_arr(dist1);
    if(set_pred)
        reset_arr(pred);
    dist1[st] = 0;
    dfs(st, dist1, set_pred);
    end = st, val = dist1[st];
    for(i = 0;i < n;i++)
    {
        if(dist1[i] > val)
        {
            val = dist1[i];
            end = i;
        }
    }
}

void get_center(int s, int t, int &cent)
{
    bool even = (dist1[t] % 2 == 0);
    int val = dist1[t] / 2;
    for(cent = 0;cent < n;cent++)
    {
        // cout<<cent<<" "<<dist1[t]<<" "<<dist1[cent]<<" "<<dist2[cent]<<"|\n";
        if(even && dist1[cent] == dist2[cent] && dist1[cent] == val)
            return;
        if(!even && ((dist1[cent] == val + 1 && dist2[cent] == val) || (dist1[cent] == val && dist2[cent] == val + 1)) && dist1[cent] >= 0 && dist2[cent] >= 0)
            return;
    }
    // cout<<"abc\n";
}

void solve()
{
    edge = {-1, -1};
    find_diameter(ds, de, true);
    int v = de;
    // cout<<ds<<" "<<de<<"--\n";
    while(pred[v] != -1)
    {
        e.push_back({pred[v], v});
        v = pred[v];
        // cout<<v<<"\n";
    }

    int s, t, c1, c2, l1, l2, min_val = MAX, val;
    pair<pair<int, int>, pair<int, int> > ans = {{-1, -1}, {-1, -1}};
    for(int i = 0;i < e.size();i++)
    {
        edge = e[i];
        // cout<<edge.first<<" "<<edge.second<<"--|||||||||||||\n";
        
        find_diameter(s, t);
        l1 = dist1[t];
        reset_arr(dist2);
        dist2[t] = 0;
        dfs(t, dist2, false);
        get_center(s, t, c1);

        // cout<<s<<" "<<t<<"\n";

        for(v = 0;v < n;v++)
        {
            if(dist1[v] < 0)
                break;
        }

        // cout<<v<<"----\n";

        find_diameter(s, t, false, v);
        l2 = dist1[t];
        reset_arr(dist2);
        dist2[t] = 0;
        dfs(t, dist2, false);
        get_center(s, t, c2);

        // cout<<s<<" "<<t<<"\n\n";

        // cout<<l1<<" "<<l2<<" "<<c1<<" "<<c2<<" aaaaaaaaa\n";


        val = max(max(l1, l2), (int)ceil((float)l1 / 2.0) + (int)ceil((float)l2 / 2.0) + 1);

        if(val < min_val)
        {
            min_val = val;
            ans = {edge, {c1, c2}};
        }
    }

    cout<<min_val<<"\n";
    cout<<ans.first.first + 1<<" "<<ans.first.second + 1<<"\n";
    cout<<ans.second.first + 1<<" "<<ans.second.second + 1<<"\n";
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        solve();
    }
    return 0;
}