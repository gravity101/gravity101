#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <sstream>
#include <string>
using namespace std;

vector<vector<char>> matrix;
vector<vector<int>> sum_matrix;
int main()
{
	int N, M;
	cin >> N >> M;
	matrix.resize(N+1, vector<char>(M+1));
	sum_matrix.resize(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> matrix[i][j];
		}
	}
	//cout << "hey";

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (matrix[i][j] == '0')
			{
				sum_matrix[i][j] = sum_matrix[i-1][j] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		int cnt = 1;
		for (int j = 1; j <= M; j++)
		{
			if (sum_matrix[i][j] == 0)
			{
				continue;
			}
			int MIN = 2000000000;
			for (int k = j; k >= 1; k--)
			{
				if (sum_matrix[i][k] < MIN)
				{
					MIN = sum_matrix[i][k];
				}
				if ((j - k + 1) * MIN > ans)
				{
					ans = (j - k + 1) * MIN;
				}
			}
		}
		
	}


	/*for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << sum_matrix[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << ans;
	return 0;
}