#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;
int x, y, d;

vector<vector<char>> adj;
vector<pair<int, int>> airC;
vector<vector<int>> visited;
vector<int> stick;

char b_map[101][101];
void stickFun(int x, int th) {
	x = N - x;
	if (th % 2 == 0)
	{
		for (int i = 0; i < M; i++) {
			if (adj[x][i] == 'x') {
				adj[x][i] = '.';
				break;
			}
		}
	}
	else {
		for (int i = M - 1; i >= 0; i--) {
			if (adj[x][i] == 'x') {
				adj[x][i] = '.';
				break;
			}
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 1;

	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (!visited[nx][ny] && adj[nx][ny] == 'x') {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

int move(int x, int y) {
	int cnt = 0;
	for (int i = x + 1; i < N; i++) {
		if (adj[i][y] == 'x') { // 밑에가 클러스터일 경우 
			if (!visited[i][y]) {
				return INF; // 밑에 클러스터가 있음
			}
			else {
				return cnt;
			}
		}
		else {
			cnt++;
		}
	}

	return cnt;
}

void remake() {
	int down = INF;
	for (int i = 0; i < airC.size(); i++) {
		int cnt = move(airC[i].first, airC[i].second);
		down = min(down, cnt);
	}
	if (down == INF) return;
	for (int i = 0; i < airC.size(); i++) {
		int x = airC[i].first;
		int y = airC[i].second;
		adj[x][y] = '.';
	}
	for (int i = 0; i < airC.size(); i++) {
		int x = airC[i].first;
		int y = airC[i].second;
		adj[x + down][y] = 'x';
	}
}

int find_C() {
	int can = 0;

	for (int i = 0; i < M; i++) {
		if (adj[N - 1][i] == 'x' && !visited[N - 1][i]) {
			bfs(N - 1, i);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (adj[i][j] == 'x' && !visited[i][j]) {
				airC.push_back({ i, j });
				can = 1;
			}
		}
	}

	return can;
}

int main()
{
	cin >> N >> M;
	adj.resize(N, vector<char>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> adj[i][j];
		}
	}

	int num_throw;
	cin >> num_throw;
	for (int i = 0; i < num_throw; i++)
	{
		int floor;
		cin >> floor;
		visited.clear();
		visited.resize(N, vector<int>(M, 0));
		airC.clear();
		stickFun(floor, i);
		//cout << "hey" << endl;

		if (find_C())
		{
			remake();
		}

		
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << adj[i][j];
		}
		cout << '\n';
	}
	return 0;
}