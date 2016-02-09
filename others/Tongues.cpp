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
  char c;
  int i;
  char v[]={'a','i','y', 'e', 'o','u'};
  char ch[] ={'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};
  while(cin.get(c))
  {
    int upper = 0;
    if (!isalpha(c)) {cout << c; continue;}
    if (isupper(c))
    {
      c = tolower(c);

      upper = 1;
    }
    for (i = 0; i < 6; i++ )
      if(v[i] == c)
        break;
    
    if (i != 6)
    {
      
      if (upper)
        cout << (char)toupper(v[(i+3)%6]);
       else
         cout << v[(i+3)%6];
      
      continue;
    }
    
    for (i = 0; i < 20; i++ )
      if(ch[i] == c)
        break;
    
    if (i != 20)
    {
      if (upper)
      cout << (char)toupper(ch[(i+10)%20]);
      else
        cout << ch[(i+10)%20];
    }
    
    
    
  }

  return 0;
}