#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <set>
#include <sstream>
#include <string>
using namespace std;

struct Node
{
	int x;
	int y;
	int cnt;
	int prev_move;
	int goal_cnt;

	Node(int x_, int y_, int cnt_, int prev_move_, int goal_cnt_)
	{
		x = x_;
		y = y_;
		cnt = cnt_;
		prev_move = prev_move_;
		goal_cnt = goal_cnt_;
	}
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

char bmap[50][50];
bool visited[50][50][3][4];

int main()
{
	int N, M;
	cin >> N >> M;
	queue<Node> q;
	vector<pair<int, int>> goal_list;
	for (int i = 0; i < N; i++)
	{
		string copy;
		cin >> copy;

		for (int j = 0; j < M; j++)
		{
			bmap[i][j] = copy[j];
			if (bmap[i][j] == 'S')
			{
				q.push(Node(j, i, 0, -1, 0));
				
			}

			if (bmap[i][j] == 'C')
			{
				goal_list.push_back(make_pair(i, j));
			}
		}
	}
	

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int prev_dir = q.front().prev_move;
		int goal_cnt = q.front().goal_cnt;

		//cout << y << " " << x << " " << goal_cnt << "  " << prev_dir << endl;
		q.pop();
		for (int i = 0; i < goal_list.size(); i++)
		{
			if (x == goal_list[i].second && y == goal_list[i].first && goal_cnt != i+1 )
			{
				if (goal_cnt == 0)
				{
					goal_cnt = i + 1;
				}
				else
				{
					cout << cnt;
					return 0;
				}
			}

		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			//cout << ny << " " << nx << " " << endl;
			if (prev_dir == i) continue;
			//cout << ny << " " << nx << " " << endl;
			if (ny < 0 || nx < 0 || nx >= M || ny >= N) continue;
			//cout << ny << " " << nx << " " << endl;
			if (bmap[ny][nx] == '#') continue;
			//cout << ny << " " << nx << " " << endl;
			if (visited[ny][nx][goal_cnt][i] == true) continue;
			//cout << ny << " " << nx << " " << endl;
			visited[ny][nx][goal_cnt][i] = true;

			q.push(Node(nx, ny, cnt + 1, i, goal_cnt));

		}

	}

	cout << -1;


	return 0;
}