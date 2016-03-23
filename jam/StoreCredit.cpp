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
vector<int> table;

int main()
{
	int t,c,n;
	cin >> t;
	for(int i = 1; i <= t;)
	{
		cout << "Case #"<<i<<": ";
		cin >> c >> n;
		table.clear();
		
		for(int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			table.push_back(temp);
		}

		for(int j = 0; j < n; j++ )
		{
			for(int p = j + 1; p < n; p++)
			{
				if (table[j] + table[p] == c)
				{
					cout << j+1 << " "<< p+1 <<endl;
					goto next;
				}
			}
		}
		next: i++;

	}
  

  return 0;
}