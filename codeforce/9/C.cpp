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
vector<long double> x, y;
int main()
{
  int n; 
  cin >> n;
  for(int i = 0; i < n; i++)
  {
  	int t1, t2;
  	cin >> t1 >> t2;
  	x.push_back(t1);
  	y.push_back(t2);
  }
  long long count = 0;
  for(int i =0; i < n-1; i++)
  	for(int j = i+1; j < n; j++ )
  	{
  			if (x[i] == x[j] || y[i] == y[j])
  			count++; 
  		


  	}
  	cout << count << endl;
  return 0;
}