#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int k;
	vector<int> a;

	int i, j, p, q, r, s, count = 0;

	while(cin>>k)
	{
		if(k == 0)
			break;
		a.clear();
		a.resize(k);

		for(i = 0;i < k;i++)
			cin>>a[i];

		if(count != 0)
			cout<<'\n';
		
		for(i = 0;i <= k-6;i++)
		{
			for(j = i+1;j <= k-5;j++)
			{
				for(p = j+1;p <= k-4;p++)
				{
					for(q = p+1;q <= k-3;q++)
					{
						for(r = q+1;r <= k-2;r++)
						{
							for(s = r+1;s <= k-1;s++)
							{
								printf("%d %d %d %d %d %d\n",a[i], a[j], a[p], a[q], a[r], a[s]);
							}
						}
					}
				}
			}
		}
		count++;
	}
}
