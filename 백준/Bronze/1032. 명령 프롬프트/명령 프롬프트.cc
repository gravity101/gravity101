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
	int T;
	cin >> T;

	string answer;
	cin >> answer;
	for (int i = 1; i < T; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			if (answer[j] != s[j])
			{
				answer[j] = '?';
			}
		}
	}
	cout << answer;
	return 0;
}