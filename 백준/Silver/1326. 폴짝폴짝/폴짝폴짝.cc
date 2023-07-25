#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> a(N+1);
	vector<bool> visited(N+1, false);
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}

	int start, goal;

	cin >> start >> goal;


	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));
	visited[start] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int count = q.front().second;
		int interval = a[x];
		q.pop();
		
		if (x == goal)
		{
			std::cout << count;
			return 0;
		}
		
		for (int i = 1; x + interval * i <= N; i++)
		{
			if (visited[x + interval * i] == true) continue;
			visited[x + interval * i ] = true;
			q.push(make_pair(x + interval * i, count + 1));
		}
		for (int i = 1; x - interval * i >= 1; i++)
		{
			if (visited[x - interval * i] == true) continue;

			visited[x - interval * i] = true;
			q.push(make_pair(x - interval * i, count + 1));
		}
	}
	std::cout << -1;
	return 0;
}