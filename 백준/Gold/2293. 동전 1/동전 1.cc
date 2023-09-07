#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>

#include <string>

using namespace std;

int main()
{

	int N, K;
	cin >> N >> K;

	long long dp[10001];
	for (int i = 1; i <= 10000; i++)
	{
		dp[i] = 0;
	}
	vector<int> array(N);

	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
	}
	dp[0] = 1;


	for (int j = 0; j < N; j++)
	{
		for (int i = array[j]; i <= K; i++)
		{
			//cout << i << " " << dp[i]<<endl;
			dp[i] = dp[i] + dp[i - array[j]];
		}
	}


	
	cout << dp[K];
	


	return 0;

}
