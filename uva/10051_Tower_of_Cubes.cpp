#include<iostream>

using namespace std;

const int N = 505;
int n, cube[N][6], dp[N][6];
pair<int, int> p[N][6];

int input_seq[] = {0, 5, 2, 3, 4, 1};
string s[] = {"front", "bottom", "left", "right", "top", "back"};


void read()
{
    for(int i = n - 1;i >= 0;i--)
    {
        for(int j = 0;j < 6;j++)
            cin>>cube[i][input_seq[j]];
    }
}

void solve()
{
    int i, f, j, fd;
    int max_val = -1;
    pair<int, int> cube_info;

    for(i = 0;i < n;i++)
    {
        for(f = 0;f < 6;f++)
        {
            dp[i][f] = 1;
            p[i][f] = {-1, -1};

            for(j = 0;j < i;j++)
            {
                for(fd = 0;fd < 6;fd++)
                {
                    if(cube[i][5 - f] == cube[j][fd]
                        && dp[i][f] < dp[j][fd] + 1)
                    {
                        dp[i][f] = dp[j][fd] + 1;
                        p[i][f] = {j, fd};
                    }
                }
            }

            if(max_val < dp[i][f])
            {
                max_val = dp[i][f];
                cube_info.first = i;
                cube_info.second = f;
            }
        }
    }

    cout<<max_val<<"\n";
    while(cube_info.first != -1)
    {
        cout<<n - cube_info.first<<" "<<s[cube_info.second]<<"\n";
        cube_info = p[cube_info.first][cube_info.second];
    }
}

int main()
{
    int cno = 1;
    while(cin>>n)
    {
        if(!n)
            break;
        if(cno != 1)
            cout<<"\n";
        read();
        printf("Case #%d\n", cno);
        solve();
        cno ++;
    }
    return 0;
}