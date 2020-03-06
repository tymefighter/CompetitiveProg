#include<iostream>
#include<set>

using namespace std;

int n, g, m;
int car[105];
set<int> con[105];
bool dir[105], seen[105];

void read()
{
    char ch;
    cin>>n>>g>>m;

    for(int i = 0;i < n;i++)
        con[i].clear();

    for(int i = 0;i < g;i++)
    {
        cin>>car[i]>>ch;
        car[i]--;
        con[car[i]].insert(i);
        if(ch == 'A')
            dir[i] = false;
        else
            dir[i] = true;
    }
}

void simulate()
{
    int i, j;
    for(i = 0;i < m;i++)
    {
        for(j = 0;j < n;j++)
            seen[j] = false;
        for(j = 0;j < g;j++)
        {
            if(dir[j])
                car[j] = (car[j] + 1) % n;
            else
                car[j] = (car[j] + n - 1) % n;
            if(!seen[car[j]])
            {
                con[car[j]].clear();
                seen[car[j]] = true;
            }
            con[car[j]].insert(j);
        }
    }

    for(j = 0;j < g;j++)
        car[j] = 0;
    
    for(i = 0;i < n;i++)
    {
        for(int x : con[i])
            car[x]++;
    }

    for(j = 0;j < g;j++)
        cout<<car[j]<<" ";
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        read();
        printf("Case #%d: ", i);
        simulate();
        cout<<"\n";
    }
    return 0;
}