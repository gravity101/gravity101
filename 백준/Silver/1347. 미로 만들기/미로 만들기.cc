#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <cmath>
using namespace std;

bool map_[101][101];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;
	
	int Min_width = 50;
	int Max_width = 50;
	int Min_height = 50;
	int Max_height = 50;

	int cur_dir = 0;
	std::vector<pair<int, int>> s_;
	int cur_x = 50; 
	int cur_y = 50;
	map_[cur_y][cur_x] = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'F')
		{
			cur_x += dx[cur_dir];
			cur_y += dy[cur_dir];
			map_[cur_y][cur_x] = true;
		}
		else if (s[i] == 'R')
		{
			cur_dir += 1;

			if ( cur_dir > 3 )
			{
				cur_dir = 0;
			}
		}
		else
		{
			cur_dir -= 1;

			if (cur_dir < 0)
			{
				cur_dir = 3;
			}
		}

		Max_height = max(cur_y, Max_height);
		Min_height = min(cur_y, Min_height);
		Max_width = max(cur_x, Max_width);
		Min_width = min(cur_x, Min_width);
	}
	
	//cout << Max_height << " " << Min_height << " " << Max_width << " " << Min_width << endl;
	for (int i = Min_height; i <= Max_height; i++)
	{
		for (int j = Min_width; j <= Max_width; j++)
		{
			cout << (map_[i][j] ? '.' : '#');
		}
		cout << endl;
	}
	return 0;
}