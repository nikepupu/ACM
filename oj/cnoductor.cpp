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

int main()
{
  double P, Q;
  double temp1, temp2;
  
  cin >> P >> Q;
  int n = 0;
  
  while(1)
  {
    n++;
    temp1 = n*P/100.0;
    temp2 = n*Q/100.0;
    
    for(int i = 0; i <= n; i++)
    {
      if (i > temp1  && i < temp2)
      {
        cout << n << endl;
        return 0;
      }
    }
    
    
  }

  
  

  return 0;
}