#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

double absolute(double a)
{
	return (a > 0 ? a : -a);
}

int main()
{
	int C, S, set_no = 1, i;
	double avg, imb;
	vector<int> a;

	while(cin>>C>>S)
	{
		//if(set_no != 1)
			//cout<<'\n';
		a.resize(2*C);
		avg = 0;
		for(i = 0;i < 2*C;i++)
		{
			if(i < S)
			{
				cin>>a[i];
				avg += a[i];
			}
			else
				a[i] = 0;
		}
		avg /= (double)C;

		sort(a.rbegin(), a.rend());
		printf("Set #%d\n",set_no);
		imb = 0;

		for(i = 0;i < C;i++)
		{
			printf(" %d:", i);
			
			if(a[i] != 0)
				printf(" %d",a[i]);

			if(a[2*C - i - 1] != 0)
				printf(" %d",a[2*C - i - 1]);
			cout<<'\n';

			imb += absolute(avg - (double)(a[i] + a[2*C - i - 1]));
		}
		set_no++;
		
		printf("IMBALANCE = %0.5f\n\n",imb);
	}

	return 0;
	

}
