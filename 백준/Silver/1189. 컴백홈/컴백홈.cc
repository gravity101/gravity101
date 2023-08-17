#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <string>

using namespace std;
int R, C, K;
char bmap[5][5];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool visited[5][5] = { 0, };
int count_ = 0;
void dfs(int x, int y, int count)
{

	if (count == K )
	{
		if (y == C - 1 && x == 0)
		{
			count_++;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
		if (bmap[nx][ny] == 'T') continue;
		if (!visited[nx][ny])
		{
			/*if ( ny == C-1 && nx == 0 ) cout << nx << " " << ny << " " << count << endl;
			cout << endl;
			for (int a = 0; a < R; a++)
			{
				for (int b = 0; b < C; b++)
				{
					cout << bmap[a][b];
				}
				cout << endl;
			}*/
			visited[nx][ny] = true;
			bmap[nx][ny] = 'b' + count;
			dfs(nx, ny, count + 1);
			bmap[nx][ny] = '.';
			visited[nx][ny] = false;
		}
	}

}


int main()
{
	cin >> R >> C >> K;
	
	

	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < C; j++)
		{
			bmap[i][j] = s[j];
		}
	}
	bmap[R - 1][0] = 'a';
	visited[R - 1][0] = true;

	dfs(R - 1, 0, 1);
	cout << count_;
	return 0;
}

