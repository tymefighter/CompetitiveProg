#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> front, rear;
vector<float> drive;
int f, r;

void read()
{
	int i;
	front.clear();
	rear.clear();

	front.resize(f);
	rear.resize(r);

	for(i = 0;i < f;i++)
		cin>>front[i];
	for(i = 0;i < r;i++)
		cin>>rear[i];
}

void solve()
{
	int i, j;
	float val, max = 0;
	drive.clear();
	drive.resize(f*r);

	for(i = 0;i < f;i++)
	{
		for(j = 0;j < r;j++)
		{
			drive[i * r + j] = rear[j] / (float)front[i];
		}
	}

	sort(drive.begin(), drive.end());

	for(i = 1;i < drive.size();i++)
	{
		val = drive[i] / drive[i-1];
		if(val > max)
			max = val;
	}

	printf("%0.2f\n", max);
}

int main()
{

	while(cin>>f)
	{
		if(f == 0)
			break;
		cin>>r;
		read();
		solve();
	}
}
