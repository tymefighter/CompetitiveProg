#include<iostream>
#include<cstdio>
#include<bitset>

using namespace std;

bitset<1000005> bs;

int n, m;

void resetAll()
{
	bs.reset();
}

bool fill(int start, int end)
{
		
	for(int i = start+1;i <= end;i++)
	{

		if(bs[i] == true)
			return false;
	

		bs.set(i);
	}

	return true;
}

bool fill(int start, int end, int rep)
{
	int i = 0;
	bool flag = true;
	while(start + i <= 1000000)
	{
		if(end + i <= 1000000)
			flag = fill(start + i, end + i);
		else
			flag = fill(start + i, 1000000);

		if(!flag)
			return false;
		i += rep;
	}

	return flag;
}

bool read_solve()
{
	int start, end, rep, i;
	bool flag = true;

	for(i = 0;i < n;i++)
	{
		cin>>start>>end;
		if(!fill(start, end))
			flag = false;
	}

	for(i = 0;i < m;i++)
	{
		cin>>start>>end>>rep;
		if(!fill(start, end, rep))
			flag = false;
	}
	return flag;
}

int main()
{
	while(cin>>n>>m)
	{
		if((n|m) == 0)
			break;
		
		resetAll();
		if(read_solve())
			printf("NO CONFLICT\n");
		else
			printf("CONFLICT\n");
	}

	return 0;
}
