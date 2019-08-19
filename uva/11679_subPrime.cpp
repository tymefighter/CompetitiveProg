#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;


int main()
{
	int num_banks, num_debs;
	int i, temp;
	int deb, cred, amt;
	vector<int> a;

	while(scanf("%d %d",&num_banks,&num_debs))
	{
		if((num_banks|num_debs) == 0)
			break;

		a.clear();
		while(num_banks--)
		{
			scanf("%d",&temp);
			a.push_back(temp);
		}
		while(num_debs--)
		{
			scanf("%d %d %d",&deb, &cred, &amt);
			a[deb-1] -= amt;
			a[cred-1] += amt;
		}
		

		for(i = 0;i < a.size();i++)
		{
			if(a[i] < 0)
				break;
		}
		if(i == a.size())
			printf("S\n");
		else
			printf("N\n");
	}
	return 0;
}
