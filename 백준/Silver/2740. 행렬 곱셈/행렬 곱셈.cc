#include <iostream>


using namespace std;

int pro1[101][101];
int pro2[101][101];
int res[101][101];

int main()
{
	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin>>pro1[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> pro2[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				res[i][j] += pro1[i][k] * pro2[k][j];
			}
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	
}