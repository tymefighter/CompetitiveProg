#include<iostream>
#include<cmath>
#include<utility>

using namespace std;

int n;
pair<float, float>  coords[10];
float dist[10][10];
float dp[10][1025];
pair<int, int> pred[10][1025];

float dst(float x1, float y1, float x2, float y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void read()
{
    int i, j;
    for(i = 0;i < n;i++)
        cin>>coords[i].first>>coords[i].second;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            dist[i][j] = dst(coords[i].first, coords[i].second, coords[j].first, coords[j].second);
    }
}

void reset()
{
    int i, j;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j < 1025;j++)
        {
            dp[i][j] = -1.0;
            pred[i][j] = {-1, -1};
        }
    }
}

float solve(int i, int s)
{

    if(dp[i][s] >= 0)
        return dp[i][s];

    if(s == (1 << n) - 1)
    {
        dp[i][s] = 0;
        return 0;
    }

    float min_val, val;
    bool first_val = true;

    pair<int, int> next;

    for(int j = 0;j < n;j++)
    {
        if((s & (1 << j)) == 0)
        {
            val = solve(j, s | (1 << j)) + dist[i][j];
            if(first_val == true || val < min_val)
            {
                next = {j, s | (1 << j)};
                first_val = false;
                min_val = val;
            }
        }
    }

    pred[i][s] = next;
    dp[i][s] = min_val;
    return min_val;
}

float get_ans()
{
    int i, start;
    float min_val, val;
    bool first_ans = true;

    for(i = 0;i < n;i++)
    {
        val = solve(i, (1 << i));
        if(first_ans == true || val < min_val)
        {
            start = i;
            first_ans = false;
            min_val = val;
        }
    }

    pair<int, int> prev = {start, (1 << start)}, curr;
    curr = pred[prev.first][prev.second]; 
    float d;
    while(curr.first >= 0 && curr.second >= 0)
    {
        d = dist[prev.first][curr.first] + 16.0;
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %0.2f feet.\n", (int)coords[prev.first].first, (int)coords[prev.first].second, (int)coords[curr.first].first, (int)coords[curr.first].second, d);
        prev = curr;
        curr = pred[prev.first][prev.second];
    }

    return min_val + 16 * (n - 1);
}

int main()
{
    int net_no = 1;
    while(cin>>n)
    {
        if(!n)
            break;
        printf("**********************************************************\n");
        printf("Network #%d\n", net_no);
        read();
        reset();
        printf("Number of feet of cable required is %0.2f.\n",get_ans());
        net_no ++;
    }

    return 0;
}