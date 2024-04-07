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
	
int board[16][16];
int copy_board[16][16];
struct Enemey
{
	int x;
	int y;
	int dist;
	int index;
	Enemey(int x_, int y_, int dist_, int index_)
	{
		x = x_;
		y = y_;
		dist = dist_;
		index = index_;
	}
};

bool compare(Enemey a, Enemey b) {
	if (a.dist == b.dist) return a.x < b.x;
	return a.dist < b.dist;
}



int main()
{
	int N, M, D;
	cin >> N >> M >> D;

	vector<pair<int, int>> enemies;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 1)
			{
				enemies.push_back(make_pair(i, j));
			}
		}
	}

	int max = 0;
	for (int a = 0; a < M-2; a++)
	{
		for (int b = a+1; b < M-1; b++)
		{
			for (int c = b + 1; c < M; c++)
			{
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < M; j++)
					{
						copy_board[i][j] = board[i][j];
					}
				}
				
				vector<pair<int, int>> copy = enemies;
				vector<pair<int, int>> arrower;
				
				arrower.push_back(make_pair(N, a));
				arrower.push_back(make_pair(N, b));
				arrower.push_back(make_pair(N, c));
				int total = 0;
				//cout << "hey" << endl;
				while ( !copy.empty() )
				{
					//cout << "yo" << endl;
					vector<Enemey> obs[3];
					//cout << arrower[0].first << endl;
					for (int i = 0; i < copy.size(); i++)
					{
						for (int j = 0; j < arrower.size(); j++)
						{
							int c_x = arrower[j].second;
							int c_y = arrower[j].first;
							//cout << arrower[j].first << " " << arrower[j].second << endl;
							int dist = abs(copy[i].first - arrower[j].first) + abs(copy[i].second - arrower[j].second);
							if (dist <= D)
							{
								//cout << c_y << " " << c_x << endl;
								obs[j].push_back(Enemey(copy[i].second, copy[i].first, dist, i));
							}
						}
					}

					for (int j = 0; j < 3; j++)
					{
						//cout << "hi" << endl;
						sort(obs[j].begin(), obs[j].end(), compare);
						for (int i = 0; i < obs[j].size(); i++)
						{

							//cout << obs[j][i].dist << " " << obs[j][i].y <<" " <<obs[j][i].x << endl;
						}
					}
					

					int delete_list[3] = { -1, -1, -1 };
					int kill = 0;
					for (int i = 0; i < 3; i++)
					{
						if (obs[i].size() > 0 )
						{
							sort(obs[i].begin(), obs[i].end(), compare);
							delete_list[i] = obs[i][0].index;


							int obs_x = obs[i][0].x;
							int obs_y = obs[i][0].y;
							
							if (copy_board[obs_y][obs_x] == 0) continue;
							
							copy_board[obs_y][obs_x] = 0;
							kill++;
						}
					}

					vector<pair<int, int>> deleted_copy;

					for (int i = 0; i < 3; i++)
					{
						arrower[i].first -= 1;
					}

					for (int i = 0; i < copy.size(); i++)
					{
						if (delete_list[0] == i || delete_list[1] == i || delete_list[2] == i) continue;

						int c_x = copy[i].second;
						int c_y = copy[i].first;
						if (c_y == arrower[0].first ) continue;

						deleted_copy.push_back(make_pair(c_y, c_x));
					}

					copy = deleted_copy;
					total += kill;
				}

				if (max < total) max = total;
				

				
			}
		}
	}
	
	cout << max;

	return 0;
}