#include <iostream>
#include <vector>
using namespace std;
int main()
{
	long long N;
	cin >> N;
	long long M;
	cin >> M;
	bool flag = true;

	long long count = 0;
	
	if (N == 1) {
		count = M * 8;
	}
	else if (N == 2) {
		if (M % 2 == 0) {
			count = (M * 4) + 1;
		}
		else if (M % 2 == 1) {
			count = (M * 4) + 3;
		}
	}
	else if (N == 3) {
		if (M % 2 == 0) {
			count = (M * 4) + 2;
		}
		else if (M % 2 == 1) {
			count = (M * 4) + 2;
		}
	}
	else if (N == 4) {
		if (M % 2 == 0) {
			count = (M * 4) + 3;
		}
		else if (M % 2 == 1) {
			count = (M * 4) + 1;
		}
	}
	else if (N == 5) {
		count = (M * 8) + 4;
	}

	cout << count;

	return 0;
}