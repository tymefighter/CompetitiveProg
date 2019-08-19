#include<iostream>
#include<utility>

using namespace std;

int n, m;
char arr[1001][1001];
pair<pair<int, char>, pair<char, char> > a[1001][1001];

void read()
{
    cin>>n>>m;
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            cin>>arr[i][j];
            a[i][j] = {{-1, -1}, {-1, -1}};
        }
    }
}

void solve()
{
    int l, l1, l2;
    int r, c, rd;
    for(r = 1;r < n - 1;r++)
    {
        for(c = 0;c < m;c++)
        {
            if(arr[r][c] == arr[r-1][c])
                continue;
            l = 0;
            while(r + l < n && arr[r + l][c] == arr[r][c])
                l ++;

            if(r + l == n)
                continue;

            l1 = 0;
            while(l1 < l && r - l1 - 1 >= 0 && arr[r - l1 - 1][c] == arr[r - 1][c])
                l1 ++;

            if(l1 != l)
                continue;

            rd = r + l;
            l2 = 0;
            while(l2 < l && rd + l2 < n && arr[rd + l2][c] == arr[rd][c])
                l2 ++;

            if(l2 != l)
                continue;

            a[r][c] = {{l, arr[r-1][c]}, {arr[r][c], arr[rd][c]}};
        }
    }

    int cd, f = 0, x;
    for(r = 1;r < n;r++)
    {
        for(c = 0;c < m;)
        {
            if(a[r][c].first.first == -1)
            {
                c++;
                continue;
            }

            cd = c;
            while(cd < m && a[r][c] == a[r][cd])
                cd++;
            
            
            x = cd - c;
            f += (x * (x + 1)) / 2;
            c = cd;
        }
    }

    cout<<f<<"\n";
}



int main()
{
    read();
    solve();

    return 0;
}