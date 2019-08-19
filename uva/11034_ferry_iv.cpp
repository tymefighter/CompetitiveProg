#include<iostream>
#include<queue>
#include<string>

using namespace std;

int l, m;
queue<int> qleft, qright;

void read()
{
	int len;
	string loc;
	cin>>l>>m;
	l = l * 100;

	for(int i = 0;i < m;i++)
	{
		cin>>len>>loc;
		if(loc == "left")
			qleft.push(len);
		else
			qright.push(len);
	}
}

int solve()
{
	bool loc = false; // left: false, right: true
	int len, no = 0;

	while((qleft.empty() == false) || (qright.empty() == false))
	{
		len = 0;

		if(loc == false)
		{
			while((qleft.empty() == false) && (len + qleft.front() <= l))
			{
				len += qleft.front();
				qleft.pop();
			}
		}
		else
		{
			while((qright.empty() == false) && (len + qright.front() <= l))
			{
				len += qright.front();
				qright.pop();
			}
		}

		no ++;
		loc = !loc;
	}

	return no;
}

int main()
{
	int c;	
	cin>>c;
	
	while(c--)
	{
		read();
		cout<<solve();
		cout<<'\n';
	}

	return 0;
}
