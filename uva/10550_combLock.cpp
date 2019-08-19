#include<cstdio>

int calcCounter(int st, int end)
{
	return (end - st)>0?(end - st)*9:(360 + (end - st)*9);
}

int main()
{
	int start, p1, p2, p3;
	int val1, val2, val3, val4;

	while(scanf("%d %d %d %d", &start, &p1, &p2, &p3), (start|p1|p2|p3))
	{
		val1 = 1080;
		val2 = 360 - calcCounter(start, p1);
		val3 = calcCounter(p1, p2);
		val4 = 360 - calcCounter(p2, p3);
		printf("%d\n",val1+val2+val3+val4);
	}
	return 0;
}
