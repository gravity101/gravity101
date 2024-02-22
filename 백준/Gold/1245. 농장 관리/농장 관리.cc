#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <sstream>
#include <string>
using namespace std;

int v_map[100][70];
bool visited[100][70];


int dx[8] = { 1, 0, -1, 0 , 1, 1, -1, -1};
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1};

int main() {
	
	/*n(2a+(n-1)d)/2
	*/
	int N, M;
	
	cin >> N >> M;

	int min = 1e9;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> v_map[i][j];
		}
	}


	queue<pair<int, int>> q;
	int cnt = 0;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == false )
			{
				int mountain_peaks = v_map[i][j];
				bool ans = false;
				
				//cout << i <<" " << j << endl;
				q.push(make_pair(i, j));
				visited[i][j] = true;
				while (!q.empty())
				{

					pair<int, int> pose = q.front();
					q.pop();
					
					int cy = pose.first;
					int cx = pose.second;

					for (int x = 0; x < 8; x++)
					{
						int ny = pose.first + dy[x];
						int nx = pose.second + dx[x];

						if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;

						if (v_map[ny][nx] > v_map[i][j])
						{
							ans = true;
						}

						if (visited[ny][nx] == true)
						{
							continue;
						}
						
						if (v_map[ny][nx] == v_map[cy][cx])
						{
							q.push(make_pair(ny, nx));

							visited[ny][nx] = true;
						}
						
						
						
					}

				}


				if (ans == false)
				{
					//std::cout << i << " " << j << endl;
					cnt++;
				}
			}
		}
	}

	cout << cnt;
	return 0;
}