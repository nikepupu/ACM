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
  long double a,b,c, x1, x2;
  
  cin >> a >> b >> c;
  long double delta = b * b -4 * a * c;
  x1 = -b/2/a + sqrt(delta)/2/a;
  x2 = -b/2/a - sqrt(delta)/2/a;
  if (x1 > x2)
  	cout << fixed<<setprecision(10) << x1 << endl << x2 << endl;
  else cout << fixed<<setprecision(10) << x2 << endl<<x1 << endl;

  return 0;
}