#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int n;
long int a[100005];
map<long int, bool> sim_res;

void read()
{
	sim_res.clear();
	cin>>n;

	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
	}
}

bool simulate(long int k)
{
	int k_store = k;
	if(sim_res.find(k) != sim_res.end())
		return sim_res[k];

	if(a[0] > k)
	{
		sim_res[k] = false;
		return sim_res[k];
	}
	else if(a[0] == k)
		k--;

	for(int i = 1;i < n;i++)
	{
		if(a[i] - a[i-1] > k)
			return false;

		if(a[i] - a[i-1] == k)
			k--;
	}
	
	sim_res[k_store] = true;
	return sim_res[k_store];
}

long int search()
{
	long int low = 0, high = 100000000000 * 1l, mid;

	mid = (low + high) / 2;

	while(low <= high)
	{
		if(mid > 0 && simulate(mid) == true && simulate(mid-1) == false)
			break;

		if(simulate(mid) == false)
			low = mid + 1;
		else if(mid > 0 && simulate(mid-1) == true)
			high = mid - 1;

		mid = (low + high) / 2;
	}
	
	return mid;
}

int main()
{
	int t, case_no = 1;
	cin>>t;

	while(t--)
	{
		read();
		printf("Case %d: %ld\n", case_no, search());
		case_no ++;
	}

	return 0;
}
