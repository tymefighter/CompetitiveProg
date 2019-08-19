#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int t, n, i, flag, len1, len2;
	int a1, b1, a2, b2, tempa, tempb;
	
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);
		flag = 1;

		scanf("%d %d",&a1, &b1);
		len1 = a1 - b1 + 1;
		tempa = a1 + (a1 - b1 + 1);
		tempb = b1 + (a1 - b1 + 1);
		a1 = tempa;
		b1 = tempb;

		for(i = 1;i < n;i++)
		{
			scanf("%d %d",&a2,&b2);
			len2 = a2 - b2 + 1;
			tempa = a2 + (a2 - b2 + 1);
			tempb = b2 + (a2 - b2 + 1);
			a2 = tempa;
			b2 = tempb;

			//printf("%d %d %d %d\n",a1, b1, a2, b2);
			if(min(abs(a1-b2), abs(a2-b1)) > 1 || len2 != len1)
				flag = 0;

			a1 = a2;
			b1 = b2;
			len1 = len2;
		}

		if(flag == 1)
		{
			if(t != 0)
				printf("yes\n\n");
			else 
				printf("yes\n");

		}
		else
			if(t != 0)
				printf("no\n\n");
			else 
				printf("no\n");

			
	}

	return 0;

}
