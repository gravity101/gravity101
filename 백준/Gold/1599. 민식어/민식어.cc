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
#define FASTI cin.tie(0)->sync_with_stdio(false)
typedef int64_t ll;
using namespace std;
map<string, int> m;
vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    int pos = 0;
    string token = "";
    while ((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(token);
    return ret;
}

bool Sort(vector<string>& a, vector <string>& b)
{
    for (int i = 0; i < min(a.size(), b.size()); i++)
    {
        if (m[a[i]] == m[b[i]])
        {
            continue;
        }
        else
        {
            return m[a[i]] < m[b[i]];
        }
            
    }
    return a.size() < b.size();
}


int main()
{
	string s = "a b k d e g h i l m n ng o p r s t u w y";

    vector<string> a = split(s, " ");

    for (int i = 0; i < a.size(); i++)
    {
        m[a[i]] = i+1;
        
    }
    m["y"] = 21;
    //cout << endl;
    int N;
    cin >> N;
    vector<string> store(N);
    for (int i = 0; i < N; i++)
    {
        cin >> store[i];
    }
    vector < vector<string>> answer;
    for (ll i = 0; i < N; i++) {
        string str = store[i];
        vector<string> splits;

        string temp = "";
        for (ll j = 0; j < str.length(); j++) {
            temp += str[j];
            if (temp == "n")
                continue;
            else if (temp.length() == 1 || temp == "ng") {
                splits.emplace_back(temp);
                temp = "";
            }
            else if (temp.length() == 2 && temp != "nn") {
                splits.emplace_back("n");
                splits.emplace_back(temp.substr(1, 1));
                temp = "";
            }
            else if (temp == "nn") {
                splits.emplace_back("n");
                temp = "n";
            }
        }

        if (temp == "n")
            splits.emplace_back(temp);

        answer.emplace_back(splits);
    }
    //cout << "hey" << endl;
    


    sort(answer.begin(), answer.end(), Sort);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j];
        }
        cout << endl;
    }
	return 0;
}
