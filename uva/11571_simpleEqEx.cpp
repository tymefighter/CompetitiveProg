#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int t, flag;
	long long int a[3];
	long long int A, B, C, x, y, z, k1, k2, val;
	
	cin>>t;
	while(t--)
	{
		cin>>A>>B>>C;
		flag = false;

		for(y = -1818000; y <= 1818000;y++)
		{
			if(2*(y*y*(A-y) + B) == y*(A*A - C))
			{
				k1 = A - y;
				k2 = B/y;
				val = k1*k1 - 4*k2;

				if(val < 0)
					continue;

				val = sqrt(val);
				x = (k1 + val)/2;
				z = (k1 - val)/2;


				if(x != y && y != z && x != z && x + y + z == A && x*y*z == B && x*x + y*y + z*z == C)
				{
					a[0] = x, a[1] = y, a[2] = z;
					sort(a, a+3);

					printf("%lld %lld %lld\n",a[0], a[1], a[2]);
					flag = true;
					break;
				}
			}
		}

		if(flag == false)
			printf("No solution.\n");
	}
}
