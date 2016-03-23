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
  int n;
  string s;
  cin >> n;
  vector<long long> num(n);
  vector<long long> sumf(n);
  vector<long long> sumb(n);

  for(int i = 0; i < n; i++)
  {
    cin >> num[i];
  }
  cin >> s;
  
  long long original = 0;
  for(int i = 0; i < n; i++)
    original += num[i]*(s[i] == 'B');
  
  sumf[0] = num[0] * ( ( s[0] == 'A' )  - (s[0] == 'B') );
  long long f  = sumf[0], fi = 0;

  for(int i = 1; i < n; i++)
  {
    sumf[i] = sumf[i-1] + num[i] * ( ( s[i] == 'A' )  - (s[i] == 'B') );
     if ( f < sumf[i])
    {
      f = sumf[i];
      fi = i;
    }

  }

  sumb[n-1] = num[n-1] * ( ( s[n-1] == 'A' )  - (s[n-1] == 'B') ); 
  long long b =  sumb[n-1], bi = n-1;
  for(int i = n-2; i >= 0; i--)
  {
    sumb[i] = sumb[i+1] + num[i] * ( ( s[i] == 'A' )  - (s[i] == 'B') );
    if ( b < sumb[i])
    {
      b = sumb[i];
      bi = i;
    }

  }



  if (f > b)
  {
    for(int i = 0; i <= fi; i++ )
    {
      if (s[i] == 'A')
        s[i] = 'B';
      else s[i] = 'A';
    }

  }

  else
  {
    for (int i = n-1; i >= bi; i--)
    {
      if (s[i] == 'B')
        s[i] = 'A';
      else s[i] = 'B';
    }
  }

  long long r = 0;
  for(int i = 0; i < n; i++)
    r += (s[i] == 'B') * num[i];


  if (r > original)
  cout << r << endl;
else cout << original<<endl;

  return 0;
}