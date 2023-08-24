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
int N, SUM;
std::vector<int> s;
bool visited[20];
int arr[20];
int cnt = 0;

void combination(int x, int count, int goal)
{
	if (goal == count)
	{
		long long sum_value = 0;
		for (int i = 0; i < goal; i++)
		{
			//cout << arr[i] << " ";
			sum_value += arr[i];
		}
		//cout << endl;
		if (sum_value == SUM)
		{
			cnt++;
		}
	}
	else
	{
		for (int i = x; i < N; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				arr[count] = s[i];
				combination(i + 1, count + 1, goal);
				visited[i] = false;
			}
		}
	}
}

int main()
{
	cin >> N >> SUM;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		//if (x == SUM) cnt++;
		s.push_back(x);
	}


	for (int i = 0; i < N; i++)
	{
		combination(0, 0, i + 1);
	}

	cout << cnt;
	return 0;
}