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
int dp[101][11];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	/*for (int i = 1; i <= N; i++)
	{
		dp[i][0] = 1;
	}*/

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = dp[i-1][1];
		for (int j = 1; j <= 9; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	int sum = 0;
	for (int i = 1; i < 10; i++)
	{
		sum = (sum + dp[N][i])%1000000000;
	}

	cout << sum;
}