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

int board_map[101][101];
bool visited[101][101][5];
int dx[5] = {0, 1, -1, 0, 0 };
int dy[5] = {0, 0, 0, 1, -1 };

struct Node
{
	int x;
	int y;
	int dir;
	int cnt;

	Node(int x_, int y_, int dir_, int cnt_)
	{
		x = x_;
		y = y_;
		dir = dir_;
		cnt = cnt_;
	};
};

int main()
{

	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board_map[i][j];
		}
	}

	int start_y, start_x, start_dir;
	cin >> start_y >> start_x >> start_dir;
	int goal_y, goal_x, goal_dir;
	cin >> goal_y >> goal_x >> goal_dir;
	
	queue<Node> q;
	q.push(Node(start_x, start_y, start_dir, 0));
	visited[start_y][start_x][start_dir] = true;
	while (!q.empty())
	{
		int cur_y = q.front().y;
		int cur_x = q.front().x;
		int cur_dir = q.front().dir;
		int rank = q.front().cnt;

		//cout << cur_y << " " << cur_x << " " << cur_dir << " " << rank << endl;
		q.pop();

		if (cur_y == goal_y && cur_x == goal_x && cur_dir == goal_dir )
		{
			cout << rank << endl;
			break;
		}

		for (int i = 1; i <= 3; i++)
		{
			int next_x = cur_x + i*dx[cur_dir];
			int next_y = cur_y + i*dy[cur_dir];
			
			if (next_x <= 0 || next_x > M || next_y <= 0 || next_y > N) continue;
			if ( board_map[next_y][next_x] == 1) break;
			
			if (visited[next_y][next_x][cur_dir] == true) continue;
			visited[next_y][next_x][cur_dir] = true;
			q.push(Node(next_x, next_y, cur_dir, rank + 1));
		}

		if (cur_dir == 1 || cur_dir == 2)
		{
			if (visited[cur_y][cur_x][3] == false)
			{
				visited[cur_y][cur_x][3] = true;
				q.push(Node(cur_x, cur_y, 3, rank + 1));
			}
			if (visited[cur_y][cur_x][4] == false)
			{
				visited[cur_y][cur_x][4] = true;
				q.push(Node(cur_x, cur_y, 4, rank + 1));
			}
		}
		else
		{
			if (visited[cur_y][cur_x][1] == false)
			{
				visited[cur_y][cur_x][1] = true;
				q.push(Node(cur_x, cur_y, 1, rank + 1));
			}
			if (visited[cur_y][cur_x][2] == false)
			{
				visited[cur_y][cur_x][2] = true;
				q.push(Node(cur_x, cur_y, 2, rank + 1));
			}
		}


	}
	return 0;
}