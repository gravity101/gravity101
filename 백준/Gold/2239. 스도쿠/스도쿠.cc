#include <cstdio>
#include <cstdlib>

int arr[10][10];
bool row[10][10], col[10][10], box[10][10];

void solve(int y, int x) {
    if (y == 9 && x == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) printf("%d", arr[i][j]);
            printf("\n");
        }
        exit(0);
    }
    if (!arr[y][x]) {
        for (int i = 1; i <= 9; i++) {
            if (row[y][i] || col[x][i] || box[(y / 3) * 3 + x / 3][i]) continue;
            row[y][i] = true;
            col[x][i] = true;
            box[(y / 3) * 3 + x / 3][i] = true;
            arr[y][x] = i;
            solve(y + (x + 1) / 9, (x + 1) % 9);
            row[y][i] = false;
            col[x][i] = false;
            box[(y / 3) * 3 + x / 3][i] = false;
            arr[y][x] = 0;
        }
    } else {
        solve(y + (x + 1) / 9, (x + 1) % 9);
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%1d", &arr[i][j]);
            row[i][arr[i][j]] = true;
            col[j][arr[i][j]] = true;
            box[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;
        }
    }
    solve(0, 0);
}


//#include <iostream>
//#include <string>
//#include <cmath>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int map[9][9];
//
//
//void sudoku(int x, int y)
//{
//	if ( y == 9 && x == 9 )
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			for (int j = 0; j < 9; j++)
//			{
//				cout << map[i][j];
//			}
//			cout << endl;
//			exit(0);
//		}
//	}
//	/*if (map[i][x] != 0) sudoku(i, x + 1);*/
//	if (map[y][x] == 0)
//	{
//		for (int k = 1; k <= 9; k++)
//		{
//			bool flag = false;
//			for (int a = 0; a < 9; a++)
//			{
//				if (map[y][a] == k )
//				{
//					flag = true;
//					break;
//				}
//				if (map[a][x] == k )
//				{
//					flag = true;
//					break;
//				}
//			}
//
//			for (int a = y - (y % 3); a < y - (y % 3) + 3; a++)
//			{
//				for (int b = x - (x % 3); b < x - (x % 3) + 3; b++)
//				{
//					if (map[a][b] == k) flag = true;
//				}
//			}
//
//			if (flag == false )
//			{
//				map[y][x] = k;
//
//
//				if (x == 8 && y == 8)
//				{
//					sudoku(9, 9);
//				}
//				else
//				{
//					if (x == 8)
//					{
//						sudoku(0, y + 1);
//					}
//					else
//					{
//						sudoku(x + 1, y);
//					}
//				}
//				map[y][x] = 0;
//			}
//
//		}
//	}
//	else
//	{
//		if (x == 8 && y == 8)
//		{
//			sudoku(9, 9);
//		}
//		else
//		{
//			if (x == 8)
//			{
//				sudoku(0, y + 1);
//			}
//			else
//			{
//				sudoku(x + 1, y);
//			}
//		}
//	}
//}
//
//
//
//int main()
//{
//	//for (int i = 0; i < 9; i++)
//	//{
//	//	string s;
//	//	cin >> s;
//	//	for (int j = 0; j < 9; j++)
//	//	{
//	//		map[i][j] = s[j] - '0';
//	//	}
//	//}
//	////cout << "yaho" << endl;
//	//
//	//
//	//sudoku(0, 0);
//	/*for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			if (map[i][j] != 0) continue;
//
//			for (int k = 1; k <= 9; k++)
//			{
//				bool flag = false;
//				for (int x = 0; x < 9; x++)
//				{
//					if (map[i][x] == k)
//					{
//						flag = true;
//						break;
//					}
//
//					if (map[x][j] == k)
//					{
//						flag = true;
//						break;
//					}
//				}
//
//				for (int a = i - (i % 3); a < i - (i % 3) + 3; a++)
//				{
//					for (int b = j - (j % 3); b < j - (j % 3) + 3; b++)
//					{
//						if ( map[a][b] == k ) flag = true;
//					}
//				}
//
//				if (flag == false)
//				{
//					map[i][j] = k;
//					break;
//				}
//
//			}
//		}
//	}*/
//	int y, x;
//	cin >> y >> x;
//	for (int a = y - (y % 3); a < y - (y % 3) + 3; a++)
//	{
//		for (int b = x - (x % 3); b < x - (x % 3) + 3; b++)
//		{
//			cout << a << " " << b << endl;
//		}
//		//cout << endl;
//	}
//	return 0;
//}