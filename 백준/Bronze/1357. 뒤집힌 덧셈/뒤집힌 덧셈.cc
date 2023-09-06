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

//int main()
//{
//    int n, k, s, r, t;
//    scanf("%d%d", &n, &k);
//    for (s = 9, r = 1, t = 1; s * r < k; k -= s * r, s *= 10, r++, t *= 10);
//    k--; t += k / r, k %= r;
//    if (n < t) { puts("-1"); return 0; }
//    k = r - k - 1;
//    while (k--) t /= 10;
//    printf("%d\n", t % 10);
////}
int main()
{
	string n, m;
	cin >> n >> m;

	
	reverse(n.begin(), n.end());
	reverse(m.begin(), m.end());
	

	long long sum = stoi(n) + stoi(m);
	string answer;
	answer = to_string(sum);

	reverse(answer.begin(), answer.end());

	cout << stoi(answer) << endl;
	return 0;

}

