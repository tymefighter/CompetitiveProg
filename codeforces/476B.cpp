#include<iostream>
#include<string>
#include<cstring>

using namespace std;

double dp[11][31];
string a, b;
int pos;

void init()
{
    int i, j;
    for(i = 0;i < 11;i++)
    {
        for(j = 0;j < 31;j++)
            dp[i][j] = -1.;
    }
}

void find_pos()
{
    pos = 10;

    for(char x : a)
    {
        if(x == '+')
            pos++;
        else
            pos--;
    }
}

double solve(int i, int c)
{

    if(i == -1)
    {
        if(c == pos)
            return 1.;
        else
            return 0.;
    }

    if(dp[i][c] >= 0)
        return dp[i][c];

    if(b[i] == '+')
        dp[i][c] = solve(i-1, c+1);
    else if(b[i] == '-')
        dp[i][c] = solve(i-1, c-1);
    else
        dp[i][c] = 0.5 * solve(i-1, c+1) + 0.5 * solve(i-1, c-1);

    return dp[i][c];
}

int main()
{
    cin>>a>>b;
    init();
    find_pos();
    printf("%0.12lf\n", solve(a.size()-1, 10));
    return 0;
}