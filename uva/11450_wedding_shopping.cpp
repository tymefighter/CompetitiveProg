#include<iostream>
#include<vector>

using namespace std;

int M, C; // M: total money, C: no of garments
bool reachable[2][202]; // (prev / current)garment, money
vector<vector<int> > gt(22); // garments

void read()
{
	int i, j, K;
	cin>>M>>C;

	for(i = 0;i < 2;i++)
	{
		for(j = 0;j <= M;j++)
		{
			reachable[i][j] = false;
		}
	}

	for(i = 0;i < C;i++)
	{
		cin>>K;
		gt[i].resize(K);
		for(j = 0;j < K;j++)
			cin>>gt[i][j];
	}
}

int solve()
{
	int i, m, k;
	bool flag = true; // true: curr = 1, prev = 0, false: curr = 0, prev = 1

	for(k = 0;k < gt[0].size();k++)
	{
		if(M - gt[0][k] >= 0)
		{
			reachable[0][M - gt[0][k]] = true;
			//cout<<M - gt[0][k]<<"--";
		}
	}
	//cout<<"----\n";

	for(i = 1;i < C;i++)
	{
		for(m = 0;m <= M;m++)
		{
			if(flag)
				reachable[1][m] = false;
			else
				reachable[0][m] = false;
		}

		for(m = 0;m <= M;m++)
		{
			if(((flag && reachable[0][m]) || (!flag && reachable[1][m])) == false)
				continue;

			for(k = 0;k < gt[i].size();k++)
			{
				if(m - gt[i][k] >= 0)
				{
					//cout<<i<<" "<<m - gt[i][k]<<" "<<flag<<"\n";

					if(flag)
						reachable[1][m - gt[i][k]] = true;
					else
						reachable[0][m - gt[i][k]] = true;
				}
			}
		}

		flag = ! flag;
	}
	
	flag = ! flag;

	for(m = 0;m <= M;m++)
	{
		if(flag && reachable[1][m])
			return M - m;
		else if(!flag && reachable[0][m])
			return M - m;
	}

	return -1;
	
}
int main()
{
	int t, ans;
	cin>>t;
	
	while(t--)
	{
		read();
		ans = solve();
		if(ans == -1)
			cout<<"no solution\n";
		else
			cout<<ans<<'\n';
	}

	return 0;
}
