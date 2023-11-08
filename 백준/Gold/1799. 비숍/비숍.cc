#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int chess_board[10][10];
bool flag1[19];
bool flag2[19];
vector<pair<int, int>> white_space;
vector<pair<int, int>> black_space;
vector<pair<int, int>> free_space;
int N;
int max_cnt = 0;
int chess_board_size = 0;
int real_cnt = 0;

int check_map[20][20];
void Queen(int cnt)
{
	if (max_cnt < real_cnt) max_cnt = real_cnt;

	for (int i = cnt; i < free_space.size(); i++)
	{
		int y = free_space.at(i).first;
		int x = free_space.at(i).second;

		if (flag1[N - y + x] == false && flag2[ x + y ] == false)
		{
			flag1[N - y + x] = true;
			flag2[x + y] = true;
			real_cnt += 1;
			Queen( i + 1);
			real_cnt -= 1;
			flag1[N - y + x] = false;
			flag2[x + y] = false;
		}
	}
}
//
//void Black_Queen(int cnt)
//{
//	if (max_cnt < real_cnt) max_cnt = real_cnt;
//
//	for (int i = cnt; i < black_space.size(); i++)
//	{
//		int y = black_space.at(i).first;
//		int x = free_space.at(i).second;
//
//		//(x + y) % 2 == 0
//
//		if (flag1[N - y + x] == false && flag2[x + y] == false)
//		{
//			flag1[N - y + x] = true;
//			flag2[x + y] = true;
//			real_cnt += 1;
//			Black_Queen(i + 1);
//			real_cnt -= 1;
//			flag1[N - y + x] = false;
//			flag2[x + y] = false;
//		}
//	}
//}

int main()
{
	//int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> chess_board[i][j];

			if (chess_board[i][j] == 1)
			{
				if ( i % 2 == 0 )
				{
					if (j % 2 == 0)
					{
						white_space.push_back(make_pair(i, j));
					}
					else
					{
						black_space.push_back(make_pair(i, j));
					}
				}
				else
				{
					if (j % 2 == 0)
					{
						black_space.push_back(make_pair(i, j));
					}
					else
					{
						white_space.push_back(make_pair(i, j));
					}
				}
			}
			
		}
	}

	/*for (int i = 0; i < white_space.size(); i++)
	{
		check_map[white_space[i].first][white_space[i].second] = 1;
	}
	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << check_map[i][j] << " ";
		}
		cout << endl;
	}*/

	free_space = white_space;
	
	Queen(0);
	int white_cnt = max_cnt;
	free_space = black_space;
	max_cnt = 0;
	Queen(0);
	int black_cnt = max_cnt;
	cout << white_cnt + black_cnt;
	return 0;

}