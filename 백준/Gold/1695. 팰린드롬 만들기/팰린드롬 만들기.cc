#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int min_ = 1e9;

int dp[5001][5001];
int arr[5001];

int recursive(int start, int end)
{
	if (start >= end)
	{
		return 0;
	}

	if (dp[start][end] != -1) return dp[start][end];

	//cout << start << "  " << end <<" " << count << endl;
	if (arr[start] != arr[end])
	{
		dp[start][end] = min(recursive(start, end-1) +1, recursive(start+1, end) +1);
	}
	else
	{
		dp[start][end] = recursive(start + 1, end - 1);
	}
	return dp[start][end];

}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	for (int i = 0; i <N; i++)
	{
		for (int j = 0; j <N; j++)
		{
			dp[i][j] = -1;
		}
	}


	//recursive(0, s.size() - 1, s);

	cout << recursive(0, N-1);


	return 0;
}
