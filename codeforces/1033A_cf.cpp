#include<iostream>
#include<cstdio>

using namespace std;

bool solve(int **a, int n, int ax, int ay, int bx, int by, int cx, int cy)
{
	int ans = false;
	//cout<<bx<<" "<<by<<'\n';
	a[bx-1][by-1] = 1;

	if(bx == cx && by == cy)
	{
		return true;
	}

	//cout<<ans<<'\n';
	if(bx+1 >= 1 && bx+1 <= n && a[bx+1-1][by-1 ]== 0 && bx+1 != ax && abs(by-(bx+1)) != abs(ay-ax) && ans == false)//(bx+1, by)
	{
		ans = solve(a, n, ax, ay, bx+1, by, cx, cy);
	}
	if(bx-1 >= 1 && bx-1 <= n && a[bx-1-1][by-1]== 0 && bx-1 != ax && abs(by-(bx-1)) != abs(ay-ax) && ans == false)
	{
		ans = solve(a, n, ax, ay, bx-1, by, cx, cy);
	}
	if(by+1 >= 1 && by+1 <= n && a[bx-1][by+1-1]== 0 && by+1 != ay && abs(by+1-(bx)) != abs(ay-ax) && ans == false)
	{
		ans = solve(a, n, ax, ay, bx, by+1, cx, cy);
	}
	if(by-1 >= 1 && by-1 <= n && a[bx-1][by-1-1]== 0 && by-1 != ay && abs(by-1-(bx)) != abs(ay-ax) && ans == false)
	{
		ans = solve(a, n, ax, ay, bx, by-1, cx, cy);
	}
	//Corners
	if(by-1 >= 1 && bx-1 >= 1 && by-1 <= n && bx-1 <= n && a[bx-1-1][by-1-1]== 0 && by-1 != ay && bx-1 != ax && abs(by-1-(bx-1)) != abs(ay-ax) && ans == false) 
	{
		ans = solve(a, n, ax, ay, bx-1, by-1, cx, cy);
	}
	if(by-1 >= 1 && bx+1 >= 1 && by-1 <= n && bx+1 <= n && a[bx+1-1][by-1-1]== 0 && by-1 != ay && bx+1 != ax && abs(by-1-(bx+1)) != abs(ay-ax) && ans == false) 
	{
		ans = solve(a, n, ax, ay, bx+1, by-1, cx, cy);
	}
	if(by+1 >= 1 && bx-1 >= 1 && by+1 <= n && bx-1 <= n && a[bx-1-1][by+1-1]== 0 && by+1 != ay && bx-1 != ax && abs(by+1-(bx-1)) != abs(ay-ax) && ans == false) 
	{
		ans = solve(a, n, ax, ay, bx-1, by+1, cx, cy);
	}
	if(by+1 >= 1 && bx+1 >= 1 && by+1 <= n && bx+1 <= n && a[bx+1-1][by+1-1]== 0 && by+1 != ay && bx+1 != ax && abs(by+1-(bx+1)) != abs(ay-ax) && ans == false) 
	{
		ans = solve(a, n, ax, ay, bx+1, by+1, cx, cy);
	}

	return ans;
}


int main()
{
	int n, ax, ay, bx, by, cx, cy;
	int i, j;

	cin>>n;
	cin>>ax>>ay;
	cin>>bx>>by;
	cin>>cx>>cy;

	int **a = (int **)malloc(n*sizeof(int *));


	for(i = 0;i < n;i++)
	{
		a[i] = (int *)malloc(n*sizeof(int));
		for(j = 0;j < n;j++)
		{
			a[i][j] = 0;
		}
	}

	if(solve(a, n, ax, ay, bx, by, cx, cy))
		cout<<"YES\n";
	else
		cout<<"NO\n";


	return 0;
}
