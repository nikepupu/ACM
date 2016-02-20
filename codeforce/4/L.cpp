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
#include <sstream>
template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;

int main()
{
  unsigned long long  a,b;
  char s[6];
  s[5] = '\0';
  string p;
  cin >> p;
 
  s[0] = p[0];
  s[1] = p[2];
  s[2] = p[4];
  s[3] = p[3];
  s[4] = p[1];
  a = atoi(s); 
  b = a;
 
  for(int i = 0; i < 4; i++)
  {
     b *= a;
     b %= 100000;
     
  }
  stringstream is;
  is << b;
  string pp = is.str();
  
   int c = 5-pp.length();
   while (c--)
   {
    cout << 0;
   } 
   cout << b << endl;

 

  return 0;
}