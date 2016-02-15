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
  long n, m;
  int k = 0;
  cin >> n >> m;
  
  
  for (int i = 1; ; i++)
  {
    if (i % 6 == 0) {k++; goto stop;}
    if (i % 2 == 0 && n > 0) n--;
    if (i %3 == 0 && m > 0) m--;
    
  stop: if (k >= n + m){
      cout << i << endl;
      break;
    }
  }

  
  return 0;
}