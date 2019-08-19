#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<set>
#include<string>
#include<sstream>

using namespace std;

stringstream ss;
string s;


int n, k;
int t[5];      // array of times
set<int> st[5]; // array of sets
int dist[5][99];
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

void get_val()
{
    ss.clear();
    ss.str(s);
    ss >> n;
    ss >> k;
}

void read()
{
    int i, j;
    getline(cin, s);
    ss.clear();
    ss.str(s);
    for(i = 0;i < n;i++)
        ss >> t[i];
    
    int x;
    for(i = 0;i < n;i++)
    {
        st[i].clear();
        getline(cin, s);
        ss.clear();
        ss.str(s);

        while(!ss.eof())
        {
            ss >> x;
            st[i].insert(x);
        }

        for(j = 0;j < 100;j++)
            dist[i][j] = -1;
    }
}

void relax(int e1, int f1, int e2, int f2, int w)
{
    if(dist[e2][f2] == -1 || dist[e1][f1] + w < dist[e2][f2])
    {
        dist[e2][f2] = dist[e1][f1] + w;
        pq.push({dist[e2][f2], {e2, f2}});
    }
}

void Dijkstra()
{
    int i;
    for(i = 0;i < n;i++)
    {
        if(st[i].find(0) != st[i].end())
        {
            dist[i][0] = 0;
            pq.push({0, {i, 0}});
        }
    }

    pair<int, pair<int, int> > x;
    int d, fl, ele;
    while(! pq.empty())
    {
        x = pq.top(), pq.pop();

        d = x.first;
        ele = x.second.first;
        fl = x.second.second;

        if(dist[ele][fl] < d)   // lazy deletion
            continue;


        if(st[ele].find(fl) != st[ele].end())   // shifting elevator
        {
            for(int ele2 = 0;ele2 < n;ele2++)
            {
                if(ele2 == ele)
                    continue;
                if(st[ele2].find(fl) != st[ele2].end())
                    relax(ele, fl, ele2, fl, 60);
            }
        }

        if(fl < 99)
            relax(ele, fl, ele, fl+1, t[ele]);

        if(fl > 0)
            relax(ele, fl, ele, fl-1, t[ele]);

    }

    int ans = -1;
    for(i = 0;i < n;i++)
    {
        if(dist[i][k] != -1 && st[i].find(k) != st[i].end())
        {
            if(ans == -1 || dist[i][k] < ans)
                ans = dist[i][k];
        }
    }

    if(ans == -1)
        cout<<"IMPOSSIBLE\n";
    else
        cout<<ans<<"\n";
}

int main()
{
    while(getline(cin, s))
    {
        get_val();
        read();
        Dijkstra();
    }
    return 0;
}