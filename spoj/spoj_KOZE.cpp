#include<iostream>

using namespace std;

const int MAX = 255;

void operator+= (pair<int, int> &a, const pair<int, int> &b)
{
    a.first += b.first;
    a.second += b.second;
}

int n, m;
char a[MAX][MAX];
bool vis[MAX][MAX];

void read()
{
    cin>>n>>m;
    int i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            cin>>a[i][j];
            vis[i][j] = false;
        }
    }
}

int ar[] = {-1, 1, 0, 0};
int ac[] = {0, 0, -1, 1};

bool isValid(int r, int c)
{
    if(r < 0 || r >= n || c < 0 || c >= m
        || a[r][c] == '#' || vis[r][c])
        return false;
    return true;
}

pair<int, int> dfs(int r, int c)        // Returns: (num_sheep, num_wolf)
{
    pair<int, int> animal_count = {0, 0};
    
    vis[r][c] = true;
    if(a[r][c] == 'k')
        animal_count.first = 1;
    else if(a[r][c] == 'v')
        animal_count.second = 1;
    
    int rd, cd;

    for(int i = 0;i < 4;i++)
    {
        rd = r + ar[i];
        cd = c + ac[i];
        if(isValid(rd, cd))
            animal_count += dfs(rd, cd);
    }

    return animal_count;
}

void solve()
{
    pair<int, int> animal_alive = {0, 0};
    int i, j;
    for(i = 0;i < n;i++)
    {
        if(isValid(i, 0))
            animal_alive += dfs(i, 0);
        if(isValid(i, m - 1))
            animal_alive += dfs(i, m - 1);
    }

    for(j = 0;j < m;j++)
    {
        if(isValid(0, j))
            animal_alive += dfs(0, j);
        if(isValid(n - 1, j))
            animal_alive += dfs(n - 1, j);
    }

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            if(isValid(i, j))
            {
                pair<int, int> animals_present_sector = dfs(i, j);
                if(animals_present_sector.first > animals_present_sector.second)
                    animal_alive.first += animals_present_sector.first;
                else
                    animal_alive.second += animals_present_sector.second;
            }
        }
    }

    cout<<animal_alive.first<<" "<<animal_alive.second<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}