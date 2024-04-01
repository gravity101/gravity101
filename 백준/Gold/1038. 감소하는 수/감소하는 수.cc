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


vector<string> answer;
char arr[10];

void dfs(int size, int count)
{
	if (count == size)
	{
		string s;
		
		for (int i = 0; i < size; i++)
		{
			s += arr[i];
		}

		//cout<<s<<endl;
		answer.push_back(s);
		return;
	}
	else
	{
		for (int i = 0; i <= 9; i++)
		{
			if (arr[count - 1] - '0' > i)
			{
				arr[count] = i + '0';
				dfs(size, count + 1);
			}
		}
	}
}


int main()
{
	int N;
	cin >> N;
	//cout<<"0"<<endl;
	for (int i = 1; i <= 9; i++)
	{
		int j;
		if (i == 1) j = 0;
		else j = 1;
		for (j; j <= 9; j++)
		{
			arr[0] = j + '0';
			dfs(i, 1);
		}
	}
	answer.push_back("9876543210");
	if (N > answer.size()-1)
	{
		cout << -1;
	}
	else
	{
		cout << answer[N];
	}

	return 0;
}