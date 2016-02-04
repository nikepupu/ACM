#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <iomanip>

#define PI 3.14159265
template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;

int main()
{
  int T;
  double V, D;
  cin >> T;
  for (int k = 1; k <= T; k++)
  {
    cin >> V >> D;
    double temp = D/V * 9.8/V;
    if(temp > 1)
      temp = 1;
    double theta = asin(temp) / PI * 90;
    
    cout <<fixed << setprecision(6)<<"Case #"<<k<<": "<<theta<<endl;
    
  }

  return 0;
}