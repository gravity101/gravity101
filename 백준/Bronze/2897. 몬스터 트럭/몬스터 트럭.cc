#include <iostream>

#include <string>

using namespace std;

 

const int MAX = 50;

 

string s[MAX];

int result[5];

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        int R, C;

        cin >> R >> C;

 

        for (int i = 0; i < R; i++)

                 cin >> s[i];

 

        for (int i = 0; i < R; i++)

        {

                 for (int j = 0; j < C; j++)

                 {

                         if (i < R - 1 && j < C - 1)

                         {

                                 int temp = 0;

                                 //건물이 있으면 주차 불가능

                                 if (s[i][j] == '#' || s[i][j + 1] == '#' || s[i + 1][j] == '#' || s[i + 1][j + 1] == '#')

                                          continue;

                                 //몇 개의 차를 부셔야하는지 파악

                                 if (s[i][j] == 'X')

                                          temp++;

                                 if (s[i + 1][j] == 'X')

                                          temp++;

                                 if (s[i][j + 1] == 'X')

                                          temp++;

                                 if (s[i + 1][j + 1] == 'X')

                                          temp++;

                                 result[temp]++;

                         }

                 }

        }

        for (int i = 0; i < 5; i++)

                 cout << result[i] << "\n";

        return 0;

}