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
typedef long long ll;
int main()
{
  ll s, x;
  cin >> s >> x;
  if (s < x)
  {
    cout << 0<<endl;
    return 0;
  }
  ll count = 0;


  	for (ll  i = 1; i < s  ; i++)
  	{
  		if ((i ^ (s-i)) == x){
        cout << i <<" " <<(s-i) <<endl;
  			count++;
  		}
  	}
  
 

  cout << count<<endl;


  return 0;
}