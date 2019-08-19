#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<queue>
#include<utility>
#include<set>

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<int> indeg;
vector<bool> chk;
map<string, int> mp;
vector<string> re_mp;
set<pair<int, int> >st;


void clearAll()
{
    adj.clear();
    mp.clear();
    re_mp.clear();
    indeg.clear();
    chk.clear();
    st.clear();
}

void read()
{
    int i;
    string s, s2;
    adj.resize(n);
    indeg.assign(n, 0);
    chk.assign(n, false);
    re_mp.resize(n);

    for(i = 0;i < n;i++)
    {
        cin>>s;
        mp[s] = i;
        re_mp[i] = s;
    }

    cin>>m;

    for(i = 0;i < m;i++)
    {
        cin>>s>>s2;
        if(st.find({mp[s], mp[s2]}) != st.end())
            continue;


        adj[mp[s]].push_back(mp[s2]);
        indeg[mp[s2]]++;
        st.insert({mp[s], mp[s2]});
    }
}

void KahnTopo()
{
    queue<int> q;
    int i, j, u;

    for(j = 0;j < n;j++)
    {
        for(i = 0;i < n;i++)
        {
            if(indeg[i] == 0 && chk[i] == false)
            {
                cout<<" "<<re_mp[i];
                q.push(i);
                chk[i] = true;
                while(q.empty() == false)
                {
                    u = q.front();
                    q.pop();

                    for(int v : adj[u])
                        indeg[v]--;
                }

                break;
            }
        }
    }

    
    
    cout<<".\n";
}

int main()
{
    int c_no = 1;
    while(cin>>n)
    {
        clearAll();
        read();
        printf("Case #%d: Dilbert should drink beverages in this order:",c_no);
        KahnTopo();
        c_no++;
        cout<<"\n";
    }

    return 0;
}