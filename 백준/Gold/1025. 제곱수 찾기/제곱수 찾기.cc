#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <string>;
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<char>> s(N, vector<char>(M));
	for (int i = 0; i < N; i++)
	{
		string copy;
		cin >> copy;
		for (int j = 0; j < M; j++)
		{
			s[i][j] = copy[j];
		}
	}

	int move[8][2] = {{0,1}, {1,-1}, {1,0}, {1,1}, {0,-1}, {-1,1}, {-1,0}, {-1,-1}};
	vector<int> answer;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				for (int z = 1; z <= M; z++)
				{
					for (int x = 0; x < 8; x++)
					{
						int cur_y = i;
						int cur_x = j;

						string str = "";
						while (cur_x < M && cur_y < N && cur_x >= 0 && cur_y >= 0)
						{
							str.push_back(s[cur_y][cur_x]);
							cur_x += move[x][0] * z;
							cur_y += move[x][1] * k; 
							int num = stoi(str);
							int n_sq = sqrt(num);
							if (n_sq * n_sq == num)
							{
								answer.push_back(num);
							}
						}

					}
				}
			}

		}
	}

	/*for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}*/

	sort(answer.begin(), answer.end());

	if (answer.size() > 0)
	{
		cout << answer.back();
	}
	else
	{
		cout << -1;
	}
	return 0;
}
