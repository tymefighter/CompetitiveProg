#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

string scan;
int n;
pair<string, int> node[275];

bool read()
{
    char c;
    n = 0;
    while(cin>>scan)
    {
        if(scan == "()")
            return true;

        string num;
        node[n].first.clear();
        for(char c : scan)
        {
            if(c >= '0' && c <= '9')
                num.push_back(c);
            else if(c == 'L' || c == 'R')
                node[n].first.push_back(c);
        }
        node[n++].second = stoi(num);
    }

    return false;
}

bool comp(const pair<string, int> &a, const pair<string, int> &b)
{
    if(a.first.size() != b.first.size())
        return a.first.size() < b.first.size();
    
    if(a.first != b.first)
        return a.first < b.first;

    return a.second < b.second;
}

bool solve()
{
    sort(node, node + n, comp);
    
    set<string> seen;
    vector<int> ans;
    string parent_path;

    if(node[0].first.size() != 0)
        return false;
    
    seen.insert("");
    ans.push_back(node[0].second);

    for(int i = 1;i < n;i++)
    {
        parent_path = node[i].first;
        parent_path.pop_back();

        if(seen.find(parent_path) == seen.end()
            || seen.find(node[i].first) != seen.end())
            return false;
        
        seen.insert(node[i].first);
        ans.push_back(node[i].second);
    }

    for(int i = 0;i < ans.size();i++)
    {
        if(i)
            cout<<" ";
        cout<<ans[i];
    }
    cout<<"\n";
    return true;
}

int main()
{
    while(read())
    {
        if(!solve())
            cout<<"not complete\n";
    }
    return 0;
}
