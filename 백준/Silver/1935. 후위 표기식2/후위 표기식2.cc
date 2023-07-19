#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;
int main()
{
	int N;
	cin >> N;

	string t;
	cin >> t;
	map<char, double> m;
	for (int i = 0; i < N; i++)
	{
		
		cin >> m['A' + i];
	}
	stack<double> s;
	
	for (int i = 0; i < t.size(); i++)
	{
		//cout << m[t[i]] << endl;
		double answer = 0.0;
		
		
		if (t[i] >= 65 && t[i] <= 90)
		{
			s.push(m[t[i]]);
		}
		else
		{
			if (t[i] == '+')
			{
				double A = s.top();
				s.pop();
				double B = s.top();
				s.pop();
				answer += B+A;
				s.push(answer);
			}
			else if (t[i] == '-')
			{
				double A = s.top();
				s.pop();
				double B = s.top();
				s.pop();
				answer += B - A;
				s.push(answer);
			}
			else if (t[i] == '*')
			{
				double A = s.top();
				s.pop();
				double B = s.top();
				s.pop();
				answer += B * A;
				s.push(answer);
			}
			else if (t[i] == '/')
			{
				double A = s.top();
				s.pop();
				double B = s.top();
				s.pop();
				answer += B/A;
				s.push(answer);
			}
		}
		
		
	}
	printf("%.2f\n", s.top());
	return 0;
}