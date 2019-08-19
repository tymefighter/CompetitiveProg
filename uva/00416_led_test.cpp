#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int n;

vector<string> nos(10);
vector<string> seq;

void read()
{
	seq.clear();
	seq.resize(n);
	
	for(int i = 0;i < n;i++)
	{
		cin>>seq[i];
	}

}


int check_led(int i, int idx, int broken)
{
	int new_broken = 0;
	for(int j = 0;j < 7;j++)
	{
		if(seq[i][j] == 'Y' && nos[idx][j] == 'N')
			return -1;

		if(seq[i][j] == 'N' && nos[idx][j] == 'Y')
			new_broken |= (1 << j);

		if(seq[i][j] == 'N' && nos[idx][j] == 'N' && (broken & (1 << j)) != 0)
			new_broken |= (1 << j);
		

	}

	return new_broken;
}

bool check_broken(int broken, int new_broken)
{

	for(int j = 1;j <= max(broken, new_broken);j = j << 1)
	{
		if(((broken & j) != 0) && ((new_broken & j) == 0))
		{
			return false;
		}
	}

	return true;
}

bool solve(int i, int idx, int broken)
{
	if(i == n)
		return true;

	if(idx >= 10)
		return false;

	
	int new_broken = check_led(i, idx, broken);


	if(new_broken < 0)
		return false;

	if(check_broken(broken, new_broken) == false)
		return false;
	

	return solve(i+1, idx+1, new_broken);
}


int main()
{
	bool flag;
	int i;

	nos[0] = "YYYYNYY";
	nos[1] = "YYYYYYY";
	nos[2] = "YYYNNNN";
	nos[3] = "YNYYYYY";
	nos[4] = "YNYYNYY";
	nos[5] = "NYYNNYY";
	nos[6] = "YYYYNNY";
	nos[7] = "YYNYYNY";
	nos[8] = "NYYNNNN";
	nos[9] = "YYYYYYN";



	while(cin>>n)
	{
		if(n == 0)
			break;

		read();
		flag = false;

		for(i = 0;i < 10;i++)
		{
			if(solve(0, i, 0))
			{
				flag = true;
				cout<<"MATCH\n";
				break;
			}
		}

		if(!flag)
			cout<<"MISMATCH\n";
	}

	return 0;
}
