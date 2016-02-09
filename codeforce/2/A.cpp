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


using namespace std;

long long a, b, c, n;

int main()
{

  
  cin >> n >> a >> b >> c;
  long long  cnt = 0;

  if (n < a && n < b)
  {
    cout << 0;
    return 0;
  }
  
  if (b-c < a && n-b > 0 ){
    n -= b;
    cnt = n/(b-c);
    n = n - cnt * b + c *cnt + b;
    }
  
  else if (a <= b-c) {
    cout << n/a<<endl;
    return 0;
  }
  
  
  while (n >= b) cnt++, n= n-b + c;
  if (n >= a) cnt += n/a;
  cout << cnt << endl;
  return 0;
}