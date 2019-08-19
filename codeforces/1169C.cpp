#include<iostream>

using namespace std;

int n, m;
int a[300005], b[300005];

void read()
{
	cin>>n>>m;
	for(int i = 0;i < n;i++)
		cin>>a[i];
}


bool check(int x)
{
	int i, val, prev;
	
	val = (a[0] + x) % m;
	if(val >= a[0])
		b[0] = a[0];
	else
		b[0] = 0;
		
	prev = b[0];
	
	for(i = 1;i < n;i++)
	{
		val = (a[i] + x) % m;
		if(val < a[i])
		{
			if(prev >= a[i] || prev <= val)
				b[i] = prev;
			else
				b[i] = a[i];
		}
		else
		{	
			if(prev <= val)
				b[i] = max(a[i], prev);
			else
				return false;
		}
		prev = b[i];
	}
	
	for(i = 1;i < n;i++)
	{
		if(b[i - 1] > b[i])
			return false;
	}
	
	return true;
}	

int b_search()
{
	int low = 0, high = m - 1, mid;
	mid = (low + high) / 2;
	
	if(check(0))
		return 0;
	
	while(low <= high)
	{
		if(mid > 0 && !check(mid - 1) && check(mid))
			return mid;
		else if(mid > 0 && check(mid - 1))
			high = mid - 1;
		else
			low = mid + 1;
			
		mid = (low + high) / 2;
	}
	
	return -1;
}

int main()
{
	read();
	cout<<b_search()<<"\n";
	return 0;
}
