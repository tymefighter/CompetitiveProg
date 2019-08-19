#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

/*

Solution: -

- Whenever we encounter a '.', we cover this block
and the next 2 blocks using a scarecrow.
- This actually means that we place the scarecrow 
at the i+1 index (if available), this allows us
to cover atmost 3 places in each step.
- If we aren't able to cover 3 spaces, then the gap
is less than 3 spaces (gap means fertile area).


*/


int main()
{
	int t, n, i, num_s, case_no = 1;
	string s;
	cin>>t;

	while(t--)
	{
		cin>>n>>s;
		num_s = 0;

		for(i = 0;i < n;i++)
		{
			if(s[i] == '.')
			{
				if(i+2 < n)
					s[i] = s[i+1] = s[i+2] = '#';
				else if(i+1 < n)
					s[i] = s[i+1] = '#';
				else
					s[i] = '#';
				num_s += 1;
			}
		}
		printf("Case %d: %d\n", case_no, num_s);
		case_no ++;
	}

	return 0;
}
