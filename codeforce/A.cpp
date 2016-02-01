#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
  int n;
  unsigned long long a;
  set<int> list;
  cin >> n;
  int count = 0;
  unsigned long long sum = 0;
  while(n--)
  {
    cin >> a;
    list.insert(a);
    sum += a;
    if (a%2 == 1)
      count++;
  }
  
  if (count % 2 == 1)
    for (set<int>::iterator it = list.begin(); it != list.end(); ++it )
  {
    if((*it) %2 == 1)
    {
      sum -= (*it);
      break;
    }
  }

  cout << sum;
  return 0;
}