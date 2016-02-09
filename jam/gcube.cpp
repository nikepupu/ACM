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
#include <iomanip>
#include <queue>

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;


int main()
{
  int T, N, M, R, L;
  long double p, a;
  double dim[1000];
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    cout << "Case #"<<t << ":"<<endl;
    cin >> N >>M;
    for (int i = 0; i < N; i++)
      cin >> dim[i];
    
    while(M--)
    {
      cin >> L >> R;
      p = 1;
      int interval = R - L +1;
      for (int i = L; i <= R; i++)
      {
        p *= pow(dim[i], 1.0/interval);
      }
      
      cout << fixed << setprecision(10) <<p << endl;
      
    }
  }
  
  return 0;
}