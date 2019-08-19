#include<iostream>
#include<cstdio>
#include<utility>
#include<vector>

using namespace std;


vector<int> tower; // stores the num served by individual towers
vector<pair<int, int> > common; // first stores the sets contained and second stores the num served
int n, x, m;
int ans;


void read()
{
	int i, j, num_common, com, bit_val, num_served;
	tower.clear();
	tower.resize(n);

	for(i = 0;i < n;i++)
	{
		cin>>tower[i];
	}

	cin>>m;

	common.clear();
	common.resize(m);


	for(i = 0; i < m;i++)
	{
		cin>>num_common;
		
		bit_val = 0;
		for(j = 0;j < num_common;j++)
		{
			cin>>com;
			com--;
			bit_val |= (1 << com);
		}
		cin>>num_served;
		common[i] = {bit_val, num_served};
	}
}

int num_bits_on(int a)
{
	int val = 0;
	while(a != 0)
	{
		val++;
		a -= (a & (-a));
	}
	
	return val;
}

int compute_ct(int comb)
{
	int i ,j, tc = 0;
	
	for(i = 1, j = 0;i < (1 << n); (i = (i << 1)), j++)
	{
		if(comb & i)
			tc += tower[j];
	}

	return tc;
}

int priority_ans(int ans1, int ans2)
{
	int i = 1;
	while(i < (1 << n))
	{
		if((ans1 & i) == true && (ans2 & i) == false)
			return ans1;
		else if((ans1 & i) == false && (ans2 & i) == true)
			return ans2;

		i = i << 1;

	}

	return ans1;
}

void solve(int case_no)
{
	int comb, total_count = 0, max_count = 0;
	int i, j;
	ans = 0;

	for(comb = 0;comb < (1 << n);comb++)
	{
		if(num_bits_on(comb) != x)
			continue;
		
		total_count = compute_ct(comb);

		for(auto com_area : common)
		{
			total_count -= max((num_bits_on(comb & com_area.first) - 1) * com_area.second, 0);
		}

		if(total_count > max_count)
		{
			max_count = total_count;
			ans = comb;
		}
		else if(total_count == max_count)
		{
			ans = priority_ans(ans, comb);
		}
	}
	
	printf("Case Number  %d\n", case_no);
	printf("Number of Customers: %d\n", max_count);
	printf("Locations recommended: ");


	int count_print = 0;
	for(i = 1, j = 1;i <= ans; (i = (i << 1)), j++)
	{
		if(i & ans)
		{
			if(count_print)
				cout<<" ";
			cout<<j;
			count_print++;
		}
	}
	
	cout<<"\n\n";
}

int main()
{
	int case_no = 1;

	

	while(cin>>n>>x)
	{
		if((n|x) == 0)
			break;
		
		read();
		solve(case_no);
		case_no ++;
	}

	return 0;
}
