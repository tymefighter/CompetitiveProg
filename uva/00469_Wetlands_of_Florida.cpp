#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

vector<string> a;
int m, n;
string s;
char line[128];

int ar[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ac[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void clear_all()
{
    s.clear();
    a.clear();
}

void resetMat()
{
    int r, c;
    for(r = 0;r < m;r++)
    {
        for(c = 0;c < n;c++)
        {
            if(a[r][c] == 'S')
                a[r][c] = 'W';
        }
    }
}

int floodFill(int r, int c)
{
    if(r < 0 || r >= m || c < 0 || c >= n)
        return 0;


    if(a[r][c] != 'W')
        return 0;
    
    a[r][c] = 'S';
    int ans = 1;

    for(int i = 0;i < 8;i++)
        ans += floodFill(r + ar[i], c + ac[i]);

    return ans;
}

void read_solve()
{
    int r, c;
    while(fgets(line, sizeof(line), stdin))
    {
        if(line[0] != 'W' && line[0] != 'L')
            break;
        
        s = line;
        s.pop_back();
        a.push_back(s);
    }

    m = a.size(), n = a[0].size();
    sscanf(line,  "%d %d", &r, &c);
    cout<<floodFill(r-1, c-1)<<"\n";

    while(fgets(line, sizeof(line), stdin))
    {
        if(line[0] < '0' || line[0] > '9')
            break;
        
        sscanf(line,  "%d %d", &r, &c);
        resetMat();
        cout<<floodFill(r-1, c-1)<<"\n";
    }
}

int main()
{
    int t;
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &t);
    fgets(line, sizeof(line), stdin);

    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        clear_all();
        read_solve();
    }

    return 0;
}