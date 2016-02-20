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
  long long n;
  cin >> n;
  if (n == 0)
  {
  	cout << 1<<endl;
  	return 0;
  }

  else{

  	cout << 1 + n*(n+1)*3<<endl;
  }

  return 0;
}