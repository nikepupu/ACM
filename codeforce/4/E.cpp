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

int main()
{
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long n = 0;
  for(long long i = x1; i <= x2 ; i++)
  {
  	if (i %2 == 1)
  		n += (y2-y1)/2 + 1;
  	else n += y2/2 - y1/2;
  }



cout << n << endl;
  return 0;
}