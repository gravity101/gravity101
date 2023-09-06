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
	int N; int K;
	
	cin >> N >> K;
	int T = 9;
	int digit = 1;
	int count = 1;
	int n, k, s, r, t;
	n = N;
	k = K;
	while (K > T * count)
	{
		K -= T * count;
		T *= 10;
		count += 1;
		digit *= 10;
	}

	for (s = 9, r = 1, t = 1; s * r < k; k -= s * r, s *= 10, r++, t *= 10);
	k--; t += k / r, k %= r;
	

	if (n < t) { puts("-1"); return 0; }
	/*cout << K << " " << T << endl;*/
	k = r - k - 1;
	while (k--) t /= 10;
	
	cout << t%10 << endl;

	return 0;
}

