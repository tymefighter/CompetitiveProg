#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

set<vector<int>> s;

void solve()
{
	int a, b, c, d, count;
	vector<int> arr(4);

	for(a = 1;a <= 500;a += 1)
	{
		for(b = a;b <= 700;b += 1)
		{
			for(c = b;c <= 1000;c += 1)
			{
				if(a*b*c == 1000000)
					continue;
				d = (1000000*(a + b + c)) / ((a*b*c) - 1000000);
				
				if(d <= 0 || ((a + b + c + d) > 2000))
					continue;
				
				

				if(1000000*(a + b + c + d) == (a*b*c*d))
				{
					arr[0] = a;
					arr[1] = b;
					arr[2] = c;
					arr[3] = d;
					sort(arr.begin(), arr.end());
					s.insert(arr);
				}
			}
		}
	}
	
	for(auto it = s.begin(); it != s.end(); it++)
	{
		count = 0;
		for(auto x : *it)
		{
			if(count != 0)
				printf(" ");
			printf("%0.2f", x / 100.0);
			count++;
		}
		printf("\n");
	}
}

int main()
{	
	solve();	
	return 0;
}
