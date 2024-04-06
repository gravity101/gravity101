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

int board_map[200][200];
bool visited[200][200][31];
bool horse_visited[200][200];
int dx[4] = {1, -1, 0, 0 };
int dy[4] = {0, 0, 1, -1 };

int h_dy[8] = { 2, 1, 2, 1, -2, -1, -2, -1 };
int h_dx[8] = { 1, 2, -1, -2, -1, -2, 1, 2 };


struct Node
{
	int x;
	int y;
	int cnt;
	int jump = 0;
	Node(int x_, int y_, int jump_, int cnt_)
	{
		x = x_;
		y = y_;
		jump = jump_;
		cnt = cnt_;
	};
};

int main()
{
	int K;

	int N, M;

	cin >> K;
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin>>board_map[i][j];
		}
	}
	
	queue<Node> q;

	q.push(Node(0, 0, 0, 0));
	visited[0][0][0] = true;
	while (!q.empty())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		int jump = q.front().jump;
		int cnt = q.front().cnt;
		q.pop();

		if (cx == M - 1 && cy == N - 1)
		{
			cout << cnt;
			exit(0);
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || board_map[ny][nx] == 1 || visited[ny][nx][jump] == true) continue;
			visited[ny][nx][jump] = true;
			q.push(Node(nx, ny, jump, cnt + 1));
		}

		for (int i = 0; i < 8; i++)
		{
			int nx = cx + h_dx[i];
			int ny = cy + h_dy[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || jump+1 > K || board_map[ny][nx] == 1 || visited[ny][nx][jump+1] == true ) continue;
			visited[ny][nx][jump+1] = true;
			q.push(Node(nx, ny, jump+1, cnt + 1));
		}
	}
	cout << -1;
	return 0;
}