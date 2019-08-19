#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
	int t, x, max = -1, count = 1;
	string s;
	stringstream stream;
	
	getline(cin, s);
	stream.str(s);
	stream>>t;
	
	while(t--)
	{
		getline(cin, s);
		stream.str(s);
		stream.clear();
		s.clear();
		max = -1;
		while(stream)
		{
			stream>>x;
			if(x > max)
				max = x;
		}
		stream.clear();
		s.clear();
		cout<<"Case "<<count<<": "<<max<<'\n';
		count++;
	}
	return 0;
}
