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
long long radius;
long long rsquare;
bool check(long long x, long long y)
{
	if ( x*x+ y*y < rsquare)
	{
		if ( (x+1)*(x+1) + (y+1)*(y+1) > rsquare)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	long long N;
	cin >> N;

	radius = N / 2;
	long long cnt = 0;
	long long x_base = 0;
	rsquare = radius * radius;
	for (long long y = radius; y >=0; y--)
	{

		for (long long x = x_base; x < radius; x++)
		{
			
			if (!check(x, y))
			{
				if (x != x_base)
				{
					x_base = x - 1;
					break;
				}
			}
			else
			{
				cnt++;
				x_base = x;
				//cout << "x : " << x << "  y : " << y << endl;
			}
			
		}
	}
	cout << cnt*4;
	return 0;
}

