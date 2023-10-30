#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[500][500];
int panda_map[500][500];
int N;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1 ,0, -1 };

int dfs(int x, int y)
{
	if (dp[y][x] != 0) return dp[y][x];

	dp[y][x] = 1;


	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N && panda_map[y][x] < panda_map[ny][nx] )
		{
			dp[y][x] = max(dp[y][x], dfs(nx, ny) + 1);
		}
	}

	return dp[y][x];
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> panda_map[i][j];
		}
	}

	int max = 0;
	


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp = dfs(i, j);
		}
		
	}

	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (max < dp[i][j]) max = dp[i][j];
		}
	}
	
	
	cout << max;
	return 0;
}
