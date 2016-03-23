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
vector<long long> table1, table2;

int main()
{
	int T,n;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #"<<t<<": ";
		table1.clear();
		table2.clear();
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			table1.push_back(temp);
		}

		for(int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			table2.push_back(temp);
		}
		sort(table1.begin(), table1.end() );
		sort(table2.begin(), table2.end(), greater<long long>() );

		long long sum = (1LL<<56), count= 0;
		
			for(int i = 0; i < n; i++)
				count += table1[i]*table2[i]; 
			
		

		cout << count<< endl;

	}
  

  return 0;
}