#include<iostream>

using namespace std;

const int N = 2005;
int n, m;
pair<int, int> fst_found[26], last_found[26];
char req[N][N], a[N][N];

bool ansExists;

void read()
{
    cin>>n>>m;

    int i, j;

    for(i = 0;i < 26;i++)
        fst_found[i] = last_found[i] = {-1, -1};

    ansExists = true;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            cin>>req[i][j];
            a[i][j] = '.';

            if(req[i][j] != '.')
            {
                if(fst_found[req[i][j] - 'a'].first == -1)
                    fst_found[req[i][j] - 'a'] = {i, j};
                else if(last_found[req[i][j] - 'a'].first == -1)
                {
                    if(i != fst_found[req[i][j] - 'a'].first && j != fst_found[req[i][j] - 'a'].second)
                        ansExists = false;

                    last_found[req[i][j] - 'a'] = {i, j};
                }
                else if(ansExists)
                {
                    if((last_found[req[i][j] - 'a'].first == i || last_found[req[i][j] - 'a'].second == j))
                        last_found[req[i][j] - 'a'] = {i, j};
                    else
                        ansExists = false;
                }
            }
        }
    }
}

void solve()
{
    if(!ansExists)
    {
        cout<<"NO\n";
        return;
    }

    int k, i, j, ct = -1;
    pair<int, int> general_ans;

    for(k = 0;k < 26;k++)
    {
        if(fst_found[k].first == -1)
            continue;
        ct = k;
        general_ans = fst_found[k];

        if(last_found[k].first == -1)
            a[fst_found[k].first][fst_found[k].second] = (char)('a' + k);
        else if(last_found[k].first > fst_found[k].first)
        {
            for(i = fst_found[k].first;i <= last_found[k].first;i++)
                a[i][fst_found[k].second] = (char)('a' + k);
        }
        else if(last_found[k].second > fst_found[k].second)
        {
            for(i = fst_found[k].second;i <= last_found[k].second;i++)
                a[fst_found[k].first][i] = (char)('a' + k);
        }
    }
    general_ans.first ++;
    general_ans.second ++;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            if(a[i][j] != req[i][j])
            {
                cout<<"NO\n";
                return;
            }
        }
    }

    cout<<"YES\n";
    cout<<ct + 1<<"\n";
    for(k = 0;k <= ct;k++)
    {
        if(fst_found[k].first == -1)
            cout<<general_ans.first<<" "<<general_ans.second<<" "<<general_ans.first<<" "<<general_ans.second<<"\n";
        else if(last_found[k].first == -1)
            cout<<fst_found[k].first + 1<<" "<<fst_found[k].second + 1<<" "<<fst_found[k].first + 1<<" "<<fst_found[k].second + 1<<"\n";
        else
            cout<<fst_found[k].first + 1<<" "<<fst_found[k].second + 1<<" "<<last_found[k].first + 1<<" "<<last_found[k].second + 1<<"\n";
    }
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