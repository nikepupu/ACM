#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;
vector<string> table;

int main()
{
	int t,n;
	cin >> t;
	char c;
	for(int i = 1; i <= t; i++)
	{
		cout << "Case #"<<i<<": ";
		table.clear();
		string temp;
		cin >> temp;
		table.push_back(temp);
		while( (c = cin.get()) && c != '\n')
		{
			string temp;
			cin >> temp;
			table.push_back(temp);
		}

		reverse(table.begin(), table.end());
		for(int j = 0; j < table.size(); j++)
		{
			cout << table[j] << " ";
		}
		cout << endl;


	}
  

  return 0;
}