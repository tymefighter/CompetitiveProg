#include<iostream>

using namespace std;

long long m1, y1, m2, y2;
int mn[12] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Feb is variable

int num_feb(int year)
{
    if(
        (year % 100 != 0 && year % 4 == 0) ||
        (year % 400 == 0)
    )
        return 29;
    else
        return 28;
}

int nextCook(int m, int y, int x) // x : curr
{
    int d1 = mn[m]; // curr
    int d2 = mn[(m + 1) % 12]; // next
    if(d1 < 0)
        d1 = num_feb(y);
    if(d2 < 0)
        d2 = num_feb(y);
    
    int u = x + 14 - d1;
    int val = d2 - u;

    if(val % 7)
    {
        val /= 7;
        val ++;
    }
    else
        val /= 7;
    
    return u + 7 * val - 14;
}

int prevCook(int m, int y, int x)
{
    int d1 = mn[(m + 11) % 12]; // prev
    if(d1 < 0)
        d1 = num_feb(y);

    return d1 + x - 7 * (x / 7) - 14;
}

int nextLong(int m, int y, int x)
{
    int d1 = mn[m]; // curr
    if(d1 < 0)
        d1 = num_feb(y);

    int val = d1 - x, ans;

    if(val % 7)
        ans = (val / 7) + 1;
    else
        ans = (val / 7);
    
    ans = 7 * ans - val;
    return ans;
}

int prevLong(int m, int y, int x)
{
    int d1 = mn[(m + 11) % 12]; // prev
    if(d1 < 0)
        d1 = num_feb(y);
    
    int v = x + d1 - 7;
    return v - 7 * (v / 7);
}

int A[2020][12];
int B[2020][12];
long long countVal[2020][12];

void compute()
{
    int i, j;
    A[2019][1] = 6;
    B[2019][1] = 15;
    for(i = 2019;i >= 0;i--)
    {
        if(i == 2019)
            j = 0;
        else
            j = 11;
        for(;j >= 0;j--)
        {
            if(j == 11)
            {
                A[i][j] = prevLong(0, i + 1 + 1, A[i + 1][0]);
                B[i][j] = prevCook(0, i + 1 + 1, B[i + 1][0]);
            }
            else
            {
                A[i][j] = prevLong(j + 1, i + 1, A[i][j + 1]);
                B[i][j] = prevCook(j + 1, i + 1, B[i][j + 1]);
            }
        }
    }
    
    for(i = 0;i < 400;i++)
    {
        for(j = 0;j < 12;j++)
        {
            if(i == 0 && j == 0)
                countVal[i][j] = 0;
            else if(j == 0)
                countVal[i][j] = countVal[i - 1][11];
            else
                countVal[i][j] = countVal[i][j - 1];

            if(A[i][j] <= B[i][j] && B[i][j] <= A[i][j] + 10)
                countVal[i][j] ++;
        }
    }
}

void solve()
{
	long long ans = countVal[399][11] * (y2 / 400) + (y2 % 400 ? countVal[(y2 % 400) - 1][m2 - 1] : 0);
	
	if(m1 != 1 || y1 != 1)
	{
		if(m1 == 1)
		{
			m1 = 12;
			y1 --;
		}
		else
			m1 --;
		ans -= countVal[399][11] * (y1 / 400) + (y1 % 400 ? countVal[(y1 % 400) - 1][m1 - 1] : 0);		
	}
	cout<<ans<<"\n";
}

int main()
{
    compute();
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m1>>y1;
        cin>>m2>>y2;
        solve();
    }
    return 0;
}
