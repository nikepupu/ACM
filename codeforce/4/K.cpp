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
 unsigned long long n;
int main()
{
 
  cin >> n;
  unsigned long long res = 0, a, b, c, d, ab,ac,ad,bc,bd, cd, abc, abd, acd,bcd, abcd;
 

  a = n/3;
  b = n/5;
  c = n/7;
  d = n/2;
  ab = n/15;
  ac = n/21;
  ad = n/6;

  bc = n/35;
  bd = n/10;
  cd = n/14;

  abc = n/105;
  abd = n/30;
  acd = n/42;
  bcd = n/70;

  abcd = n/210;
  res = n - (a + b + c +d - ab -ac -ad -bc -bd -cd + abc + abd + acd + bcd - abcd);
cout << res << endl;
  return 0;
}