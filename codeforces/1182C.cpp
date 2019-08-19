#include<iostream>
#include<utility>
#include<map>
#include<string>
#include<vector>

using namespace std;

string s;
int n;
map<pair<int, char>, int> pm;
map<pair<int, char>, vector<string> > pm2;
map<int, int> m;
map<int, vector<string> > m2;
vector<string> pst;
vector<string> st;

bool is_vowel(char x)
{
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return true;
    
    return false;
}

void read()
{
    cin>>n;
    int n_vowels;
    char last_vowel;

    for(int i = 0;i < n;i++)
    {
        n_vowels = 0;
        last_vowel = '#';
        cin>>s;

        for(char x : s)
        {
            if(is_vowel(x))
            {
                n_vowels++;
                last_vowel = x;
            }
        }

        pm[make_pair(n_vowels, last_vowel)]++;
        pm2[make_pair(n_vowels, last_vowel)].push_back(s);
    }
}

void solve()
{
    pair<int, char> a;
    int val;
    int k, t; // k: ends equal, t: left but paired

    k = 0;
    pst.clear();
    for(auto it = pm.begin(); it != pm.end(); it++)
    {
        a = (*it).first, val = (*it).second;
        if(val % 2)
        {
            m[a.first] ++;
            k += val / 2;
            pst.insert(pst.end(), pm2[a].begin(), pm2[a].end());
            m2[a.first].push_back(pst[pst.size() - 1]);
            pst.pop_back();
        }
        else if(val != 0)
        {
            pst.insert(pst.end(), pm2[a].begin(), pm2[a].end());
            k += val / 2;
        }
    }

    int x;
    t = 0;
    st.clear();
    for(auto it = m.begin(); it != m.end(); it++)
    {
        x = (*it).first;
        val = (*it).second;
        t += val / 2;

        if(val % 2)
        {
            st.insert(st.end(), m2[x].begin(), m2[x].end());
            st.pop_back();
        }
        else if(val != 0)
        {
            st.insert(st.end(), m2[x].begin(), m2[x].end());
        }
    }

    if(t >= k)
    {
        cout<<k<<"\n";
        int ct1 = 0, ct2 = 0;

        for(int i = 0;i < k;i++)
        {
            cout<<st[ct1]<<" "<<pst[ct2]<<"\n";
            ct1++, ct2++;
            cout<<st[ct1]<<" "<<pst[ct2]<<"\n";
            ct1++, ct2++;
        }

        return;
    }
    
    int r = (k - t) / 2;

    cout<< t + r <<"\n";
    int ct1 = 0, ct2 = 0;

    for(int i = 0;i < r;i++)
    {
        cout<<pst[ct2]<<" "<<pst[ct2 + 2]<<"\n";
        cout<<pst[ct2 + 1]<<" "<<pst[ct2 + 3]<<"\n";
        ct2 += 4;
        /*cout<<pst[ct2]<<" ";
        ct2++;
        cout<<pst[ct2]<<"\n";
        ct2++;
        cout<<pst[ct2]<<" ";
        ct2++;
        cout<<pst[ct2]<<"\n";
        ct2++;*/
    }

    for(int i = 0;i < t;i++)
    {
        cout<<st[ct1]<<" "<<pst[ct2]<<"\n";
        ct1++, ct2++;
        cout<<st[ct1]<<" "<<pst[ct2]<<"\n";
        ct1++, ct2++;
    }
}


int main()
{

    read();
    solve();
    return 0;
}