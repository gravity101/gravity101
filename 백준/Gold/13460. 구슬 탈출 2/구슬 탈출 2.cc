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
struct Point
{
	int x, y;
};

struct Node
{
	Point Red;
	Point Blue;
	int count = 0;
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	int N, M;
	cin >> N >> M;
	std::vector<vector<char>> map(N, vector<char>(M));
	queue<Node> q;
	Node start;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = s[j];

			if (map[i][j] == 'R')
			{
				start.Red.x = j;
				start.Red.y = i;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B')
			{
				start.Blue.x = j;
				start.Blue.y = i;
				map[i][j] = '.';
			}
		}
	}

	q.push(start);

	while (!q.empty())
	{
		int Blue_x = q.front().Blue.x;
		int Blue_y = q.front().Blue.y;

		int Red_x = q.front().Red.x;
		int Red_y = q.front().Red.y;
		int count = q.front().count;

		if (count >= 10) break;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int N_Blue_x = Blue_x;
			int N_Blue_y = Blue_y;

			int N_Red_x = Red_x;
			int N_Red_y = Red_y;
			bool r_collision_flag = false;
			bool r_flag = false;
			int move_count = 0;
			while (map[N_Red_y + dy[i]][N_Red_x + dx[i]] != '#' )
			{
				move_count++;
				N_Red_x += dx[i];
				N_Red_y += dy[i];
				if ( N_Red_x == N_Blue_x && N_Red_y == N_Blue_y )
				{
					r_collision_flag = true;
				}
				//cout << N_Red_x << " " << N_Red_y << endl;
				if (map[N_Red_y][N_Red_x] == 'O')
				{
					r_flag = true;
					break;
				}
			}
			bool b_flag = false;
			bool b_collision_flag = false;
			while (map[N_Blue_y + dy[i]][N_Blue_x + dx[i]] != '#')
			{
				N_Blue_x += dx[i];
				N_Blue_y += dy[i];
				move_count++;
				if (map[N_Blue_y][N_Blue_x] == 'O')
				{
					b_flag = true;
					break;
				}
				if (N_Red_x == N_Blue_x && N_Red_y == N_Blue_y)
				{
					b_collision_flag = true;
				}
			}

			if (b_flag == true)
			{
				continue;
			}

			if (r_flag == true)
			{
				cout << count + 1;
				return 0;
			}

			if (r_collision_flag == true)
			{
				N_Red_x -= dx[i];
				N_Red_y -= dy[i];
				move_count -= 1;
			}
			else
			{
				if (b_collision_flag == true)
				{
					N_Blue_x -= dx[i];
					N_Blue_y -= dy[i];
					move_count -= 1;
				}
			}

			if (move_count == 0)
			{
				continue;
			}

			Node next_node;
			next_node.Blue.x = N_Blue_x;
			next_node.Blue.y = N_Blue_y;
			next_node.Red.x = N_Red_x;
			next_node.Red.y = N_Red_y;
			next_node.count = count + 1;

			q.push(next_node);
		}
	}

	cout << -1;
	return 0;
}
//
//if (dx[i] == 0)
//{
//	if (Blue_x == Red_x)
//	{
//		if (dy[i] == -1)
//		{
//			if
//		}
//		else
//		{
//
//		}
//	}
//	else
//	{
//
//	}
//}
//else
//{
//	if (Red_y == Blue_y)
//	{
//
//	}
//	else
//	{
//
//	}
//}