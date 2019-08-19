#include<iostream>
#include<vector>
#include<string>
#define MOD 1000000007

using namespace std;

vector<string> a;
vector<vector<bool> > done;
int n;

void clearAll()
{
    a.clear();
    done.clear();
}

void read()
{
    cin>>n;
    a.resize(n);
    done.resize(n);

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        done[i].assign(n, false);
    }
}

bool checkNotAdj(int i, int j)
{
    if((i == 0 || a[i-1][j] == '.') && (i == n-1 || a[i+1][j] == '.') && (j == 0 || a[i][j-1] == '.') && (j == n-1 || a[i][j+1] == '.'))
        return true;
    else
        return false;
}

bool checkValid(int i, int j)
{
    if(a[i][j] == 'G')
    {
        if(checkNotAdj(i, j))
            return true;
        else
            return false;
    }
    else
    {
        if((i == 0 || a[i-1][j] == '.' || a[i-1][j] == '?' || a[i-1][j] == a[i][j]) && (i == n-1 || a[i+1][j] == '.' || a[i+1][j] == '?' || a[i+1][j] == a[i][j]) && (j == 0 || a[i][j-1] == '.' || a[i][j-1] == '?' || a[i][j-1] == a[i][j]) && (j == n-1 || a[i][j+1] == '.' || a[i][j+1] == '?' || a[i][j+1] == a[i][j]))
            return true;
        else
            return false;
    }
}

void dfs(int i, int j, bool &found_g, bool &found_b, bool &found_p)
{
    done[i][j] = true;

    if(i > 0)
    {
        if(a[i-1][j] == 'G')
            found_g = true;
        else if(a[i-1][j] == 'P')
            found_p = true;
        else if(a[i-1][j] == 'B')
            found_b = true;
    }

    if(i < n-1)
    {
        if(a[i+1][j] == 'G')
            found_g = true;
        else if(a[i+1][j] == 'P')
            found_p = true;
        else if(a[i+1][j] == 'B')
            found_b = true;
    }

    if(j > 0)
    {
        if(a[i][j-1] == 'G')
            found_g = true;
        else if(a[i][j-1] == 'P')
            found_p = true;
        else if(a[i][j-1] == 'B')
            found_b = true;
    }

    if(j < n-1)
    {
        if(a[i][j+1] == 'G')
            found_g = true;
        else if(a[i][j+1] == 'P')
            found_p = true;
        else if(a[i][j+1] == 'B')
            found_b = true;
    }

    if(i > 0 && a[i-1][j] == '?' && done[i-1][j] == false)
        dfs(i-1, j, found_g, found_b, found_p);
    
    if(i < n-1 && a[i+1][j] == '?' && done[i+1][j] == false)
        dfs(i+1, j, found_g, found_b, found_p);

    if(j > 0 && a[i][j-1] == '?' && done[i][j-1] == false)
        dfs(i, j-1, found_g, found_b, found_p);
    
    if(j < n-1 && a[i][j+1] == '?' && done[i][j+1] == false)
        dfs(i, j+1, found_g, found_b, found_p);
}

long int solve()
{
    int i, j;
    long int val = 1;
    bool found_g, found_b, found_p;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(a[i][j] == '?' && done[i][j] == false && checkNotAdj(i, j))
                val = (val * 3) % MOD;
            else if(a[i][j] == '?' && done[i][j] == false)
            {
                found_g = found_b = found_p = false;
                dfs(i, j, found_g, found_b, found_p);

                if(found_g || (found_b & found_p))
                    return 0;
                
                if((found_b || found_p) == false)
                    val = (val * 2) % MOD;

            }
            else if(a[i][j] != '.' && a[i][j] != '?')
            {
                if(checkValid(i, j) == false)
                    return 0;
            }
            

        }
    }

    return val % MOD;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        clearAll();
        read();
        cout<<solve()<<'\n';
    }

    return 0;
}