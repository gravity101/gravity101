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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N>>M;
	
	string start = to_string(N);
	string end = to_string(M);


	if (end.size() > start.size())
	{
		cout << 0;
	}
	else
	{
		int count = 0;
		for (int i = 0; i < end.size(); i++)
		{
			if (start[i] == end[i])
			{
				if (start[i] == '8') count++;
			}
            else
            {
                break;
            }
		}
		cout<<count;
		
	}


	return 0;
}