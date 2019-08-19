#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> even, odd, pos;
vector<bool> used;
int n;


void resetAll()
{
	even.clear();
	odd.clear();
	used.clear();
	pos.clear();

	for(int i = 1;i <= n;i++)
	{
		if(i % 2 == 0)
			even.push_back(i);
		else
			odd.push_back(i);
	}

	used.assign(n+1, false);
	pos.assign(n, 0);
	pos[0] = 1;
	used[1] = true;
}

bool is_prime(int x)
{
	for(int i = 2; i*i <= x; i++)
	{
		if(x % i == 0)
			return false;
	}
	
	return true;
}

void print_sol()
{
	for(int i = 0;i < n;i++)
	{
		if(i)
			cout<<" ";
		cout<<pos[i];
	}
	cout<<"\n";
}


void solve(int idx, bool flag) // true: odd, false: even
{
	int j;
	if(idx == n)
	{
		print_sol();
		return;
	}

	if(flag)
	{
		for(j = 0;j < odd.size();j++)
		{
			if(used[odd[j]] == false && is_prime(odd[j] + pos[idx-1]) == true && (idx != n-1 || is_prime(odd[j] + pos[0]) == true))
			{
				used[odd[j]] = true;
				pos[idx] = odd[j];
				solve(idx+1, ! flag);
				used[odd[j]] = false;
			}
		}
	}
	else
	{
		for(j = 0;j < even.size();j++)
		{
			if(used[even[j]] == false && is_prime(even[j] + pos[idx-1]) == true && (idx != n-1 || is_prime(even[j] + pos[0]) == true))
			{
				used[even[j]] = true;
				pos[idx] = even[j];
				solve(idx+1, ! flag);
				used[even[j]] = false;
			}
		}
	}
}

int main()
{
	int case_no = 1;
	while(cin>>n)
	{
		if(case_no != 1)
			cout<<'\n';
		resetAll();
		printf("Case %d:\n", case_no);
		solve(1, false);
		case_no++;
	}

	return 0;
}

