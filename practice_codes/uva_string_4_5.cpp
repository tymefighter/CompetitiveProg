#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

char line[128];
vector<string> token;
map<string, int> m;

void read()
{
    fgets(line, sizeof(line), stdin);
}

void tokenize()
{
    string s;
    char *pch = strtok(line, " .");
    int idx;

    while(pch != NULL)
    {
        token.push_back(s.assign(pch));
        idx = token.size() - 1;

        for(int i = 0;i < token[idx].size();i++)
            token[idx][i] = tolower(token[idx][i]);

        pch = strtok(NULL, " .");
    }
}

void solve()
{
    sort(token.begin(), token.end());

    for(auto x : token)
        cout<<x<<"\n";

    for(auto s : token)
    {
        m[s] ++;
    }

    cout<<"\nCounts: -\n";
    for(auto x : m)
    {
        cout<<x.first<<" |count: "<<x.second<<"\n";
    }
}

int main()
{
    read();
    tokenize();
    solve();
    return 0;
}