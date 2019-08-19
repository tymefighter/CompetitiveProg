#include<iostream>
#include<cstdio>

using namespace std;

/*

Solution: -

- First get the first coin denomination
- Store something called the diff_sum, this at each
step stores the value of the sum which gives max no of coins
till the previous to previous iteration added with the value of
the previous coin.
- If this value exceeds (or equals) the current coin denomination,
 then we can get smaller no of coins by using current denomination. 
 So, it is better that we keep the previous sum (stored in 'sum').
- Else we update the sum to diff_sum because we can get one more
coin (different).
- At the end we look at twice the maximum coin denomination, if 
diff_sum is less than this value, then we add the max coin. Else,
we do not.

*/




int main()
{
	long int t, n, i, x, sum, sum_check, diff_coins;

	cin>>t;
	
	while(t--)
	{
		cin>>n>>x; 

		sum_check = x;
		diff_coins = sum = 0;

		for(i = 0;i < n-1;i++)
		{
			cin>>x;
			if(sum_check < x)
			{
				sum = sum_check;
				diff_coins++;
			}

			sum_check = sum + x;
		}

		if(sum_check < 2*x)
		{
			sum = sum_check;
			diff_coins++;
		}

		cout<<diff_coins<<'\n';
	}

	return 0;
}
