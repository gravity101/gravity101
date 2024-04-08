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

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
struct Node
{
	int index;
	string s;
	int cnt;
	
	Node(int current_, int cnt_, string s_)
	{
		index = current_;
		cnt = cnt_;
		s = s_;
	}

};

int main()
{
	char board[3][3];
	queue<Node> q;
	Node start(0, 0, "");
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> board[i][j];
			start.s += board[i][j];
			if (board[i][j] == '0')
			{
				start.index = i * 3 + j;
			}
		}
	}
	//cout << start.s << endl;
	start.cnt = 0;
	string goal = "123456780";
	
	set<string> Visit;
	Visit.insert(start.s);
	q.push(start);

	while (!q.empty())
	{
		int cur_index = q.front().index;
		string cur_string = q.front().s;
		int cnt = q.front().cnt;
		q.pop();

		int x = cur_index % 3;
		int y = cur_index / 3;
		if ( goal == cur_string)
		{
			cout << cnt;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			int next_index = ny * 3 + nx;
			if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3)
			{
				string next_string = cur_string;

				next_string[next_index] = cur_string[cur_index];
				next_string[cur_index] = cur_string[next_index];
				if (Visit.find(next_string) == Visit.end())
				{
					Visit.insert(next_string);
					q.push(Node(next_index, cnt + 1, next_string));
				}

			}
		}
		
		
	}
	cout << -1;
	return 0;
}