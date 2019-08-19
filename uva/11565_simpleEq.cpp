#include<iostream>

using namespace std;

int main()
{
	int t, x, y, z, A, B, C;
	bool flag;

	cin>>t;

	while(t--)
	{
		cin>>A>>B>>C;
		flag = false;

		for(z = -100; z <= 100;z++)
		{
			for(y = -100; y <= 100 && y != z; y++)
			{
				for(x = -100; x <= 100 && x != y && x != z; x++)
				{
					if((x + y + z) == A && (x*y*z == B) && (x*x + y*y + z*z == C))
					{
						if(!flag)
							printf("%d %d %d\n",x, y, z);
						flag = true;
					}
				}

			}
		}

		if(flag == false)
			printf("No solution.\n");
	}
}
