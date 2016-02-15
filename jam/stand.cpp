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
  int T;
  cin >> T;
  string a;
  int max;
  for (int i = 1; i <= T; i++)
  {
    int count = 0;
    int cur = 0;
    cout <<"Case #"<<i<<": ";
    cin >> max>>a;
    for (int j = 0; j <= max; j++)
    {
      if (cur >= j)
      {
        cur += a[j]-'0';
      }
      else
      {
        count += j-cur;
        cur = j + a[j]-'0';
      }
      
    }
         cout << count << endl;
    
    
  }

  return 0;
}