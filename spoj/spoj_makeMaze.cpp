#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

bool check_valid(const vector<vector<char> > &maze, vector<vector<bool> >visited, int r, int c, const int &end_r, const int &end_c, const int &m, const int &n)
{
	visited[r][c] = true;

	if(r == end_r && c == end_c)
		return true;


	if(r - 1 >= 0 && maze[r - 1][c] == '.' && visited[r-1][c] == false && check_valid(maze, visited, r - 1, c, end_r, end_c, m, n) == true)
	{
		return true;
	}
	else if(r + 1 < m && maze[r + 1][c] == '.' && visited[r+1][c] == false  && check_valid(maze, visited, r + 1, c, end_r, end_c, m, n) == true)
	{
		return true;
	}
	else if(c - 1 >= 0 && maze[r][c - 1] == '.' && visited[r][c-1] == false && check_valid(maze, visited, r, c-1, end_r, end_c, m, n) == true)
	{
		return true;
	}
	else if(c + 1 < n && maze[r][c + 1] == '.' && visited[r][c+1] == false && check_valid(maze, visited, r, c+1, end_r, end_c, m, n) == true)
	{
		return true;
	}

	return false;
		
}


int main()
{
	int t, m, n, i, j, count;
	int start_r, start_c, end_r, end_c;
	vector<vector<char> >maze;
	vector<vector<bool> > visited;

	cin>>t;
	while(t--)
	{
		cin>>m>>n;

		maze.clear();
		visited.clear();

		maze.resize(m);
		visited.resize(m);
		count = 0;

		for(i = 0;i < m;i++)
		{
			maze[i].resize(n);
			visited[i].assign(n, false);

			for(j = 0;j < n;j++)
			{
				cin>>maze[i][j];
				

				if((i == m-1 || j == n-1 || i == 0 || j == 0) && maze[i][j] == '.')
				{
					if(count == 0)
					{
						start_r = i;
						start_c = j;
						count++;
					}
					else if(count == 1)
					{
						end_r = i;
						end_c = j;
						count++;
					}
					else
						count++;
				}
			}
		}

		//printf("%d %d, %d %d, %d\n", start_r, start_c, end_r, end_c, count);

		if(count != 2)
			printf("invalid\n");
		else
		{
			if(check_valid(maze, visited, start_r, start_c, end_r, end_c, m, n))
				printf("valid\n");
			else
				printf("invalid\n");
		}

	}
}
