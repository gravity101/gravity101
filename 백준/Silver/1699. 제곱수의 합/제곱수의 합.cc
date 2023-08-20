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
	cin>>N;
	
	int dp[100001];

	for (int i = 0; i <= N; i++)
	{
		dp[i] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		//cout << dp[i] << endl;
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i - j*j] + 1, dp[i]);
			//cout<<" j : " << j << endl;
		}
	}

	cout << dp[N];

	return 0;
}