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


int dx[9] = { 0, 1, 0, -1, 0, -1, 1, -1, 1};
int dy[9] = { 0, 0, 1, 0, -1, -1, -1, 1, 1};

struct Node
{
	int A_x;
	int A_y;
	int B_x;
	int B_y;
	int cnt;

	Node(int a_x, int a_y, int b_x, int b_y, int cnt_)
	{
		A_x = a_x;
		A_y = a_y;
		B_x = b_x;
		B_y = b_y;
		cnt = cnt_;
	}
};

char b_map[20][20];
bool visited[20][20][20][20];
int main()
{
	int N, M;
	cin >> N >> M;
	Node s(0,0,0,0,0);

	int A_x = 0;
	int A_y = 0;
	int B_x = 0;
	int B_y = 0;
	for (int i = 0; i < N; i++)
	{
		string copy;
		cin >> copy;
		for (int j = 0; j < M; j++)
		{
			if (copy[j] == 'X' || copy[j] == '.')
			{
				b_map[i][j] = copy[j];
			}
			else
			{
				if (copy[j] == 'A')
				{
					s.A_x = j;
					s.A_y = i;
					A_x = j;
					A_y = i;
				}
				else
				{
					s.B_x = j;
					s.B_y = i;
					B_y = i;
					B_x = j;
				}
				b_map[i][j] = '.';
			}
		}
	}

	queue<Node> q;

	q.push(s);

	while (!q.empty())
	{
		int a_x = q.front().A_x;
		int a_y = q.front().A_y;
		int b_x = q.front().B_x;
		int b_y = q.front().B_y;
		int cnt = q.front().cnt;
		q.pop();

		if (A_x == b_x && A_y == b_y && B_x == a_x && B_y == a_y)
		{
			cout << cnt;
			return 0;
		}
		for (int i = 0; i < 9; i++)
		{
			int n_a_x = a_x + dx[i];
			int n_a_y = a_y + dy[i];

			if (n_a_x < 0 || n_a_x >= M || n_a_y < 0 || n_a_y >= N) continue;
			if (b_map[n_a_y][n_a_x] == 'X') continue;
			for (int j = 0; j < 9; j++)
			{
				int n_b_x = b_x + dx[j];
				int n_b_y = b_y + dy[j];
				if (n_b_x < 0 || n_b_x >= M || n_b_y < 0 || n_b_y >= N) continue;
				if (b_map[n_b_y][n_b_x] == 'X') continue;
				if (visited[n_a_y][n_a_x][n_b_y][n_b_x]) continue;
				
				if ( n_a_x == n_b_x && n_a_y == n_b_y ) continue;
				
				if ( n_a_x == b_x && n_a_y == b_y && n_b_x == a_x && n_b_y == a_y) continue;
				
				
				q.push(Node(n_a_x, n_a_y, n_b_x, n_b_y, cnt + 1));
				visited[n_a_y][n_a_x][n_b_y][n_b_x] = true;
				
			}

		}
	}
	
	cout << -1;
		

	return 0;
}