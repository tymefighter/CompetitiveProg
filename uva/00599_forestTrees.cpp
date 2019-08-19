#include<bitset>
#include<cstdio>

using namespace std;

int main()
{
	char line[128];
	int i, num_v, t, sum;
	int num_edges;

	bitset<26> bs;

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &t);

	while(t--)
	{
		for(i = 0;i < 26;i++)
			bs[i] = false;
		
		num_edges = 0;
		while(fgets(line, sizeof(line), stdin), line[0] != '*')
		{
			//printf("%s", line);
			bs[line[1] - 'A'] = true;
			bs[line[3] - 'A'] = true;
			num_edges++;
		}

		fgets(line, sizeof(line), stdin);
		//printf("%s", line);

		i = 0;
		num_v = 0;
		while(line[i] != '\0')
		{
			if(line[i] >= 'A' && line[i] <= 'Z')
				num_v++;
			i++;
		}

		sum = 0;
		for(i = 0;i < 26;i++)
		{
			sum += bs[i];
		}

		printf("There are %d tree(s) and %d acorn(s).\n", sum-num_edges, num_v-sum);
	}
}
