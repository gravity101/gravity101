#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int dp[1001][1001];

bool visited[1001][1001];
string s;
string sentence_1;
string sentence_2;



int main()
{

	cin >> sentence_1;
	cin >> sentence_2;
	int N = sentence_1.size();
	int M = sentence_2.size();
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (sentence_2[j - 1] == sentence_1[i - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	//DFS(N, M, dp[N][M]);
	cout << dp[N][M] << endl;
	int i = N;
	int j = M;
	stack<char> s;
	while (i > 0 && j > 0)
	{
		if (sentence_1[i - 1] == sentence_2[j - 1])
		{
			s.push(sentence_1[i - 1]);
			i -= 1;
			j -= 1;
		}
		else if (dp[i][j] == dp[i][j - 1])
		{
			j -= 1;
		}
		else if (dp[i][j] == dp[i-1][j])
		{
			i -= 1;
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
    
	return 0;
}