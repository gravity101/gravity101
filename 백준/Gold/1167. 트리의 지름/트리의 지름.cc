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

vector<pair<int, int>> graph[100001];
bool visited[100001];

int maxNode;
int dfs(int x, int& last)
{
	
	

	visited[x] = true;
	int dist = 0;
	int max_node = -1;
	//cout << x << endl;
	for (int i = 0; i < graph[x].size(); i++)
	{
		if (!visited[graph[x][i].first])
		{
			int next_dist = dfs(graph[x][i].first, max_node) + graph[x][i].second;
			//cout << next_dist << endl;
			if (dist < next_dist )
			{
				dist = next_dist;
				last = max_node;
			}
		}
		
	}

	if (max_node == -1)
	{
		last = x;
	}

	visited[x] = false;
	return dist;
}


int main()
{
	int N;
	cin >> N;

	

	for (int i = 1; i <= N; i++)
	{
		int current;
		cin >> current;

		while (true)
		{
			int Node, Edge;
			cin >> Node;
			if (Node == -1) break;
			cin >> Edge;
			graph[current].push_back(make_pair(Node, Edge));
		}
	}

	int max_node;
	dfs(1, max_node);
	//cout << "ya" << max_node << endl;
	for (int i = 1; i <= N; i++)
	{
		visited[i] = false;
	}
	cout << dfs(max_node, max_node);
	
	return 0;
}