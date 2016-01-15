#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int a[6];
const int lefts[4] = {0, 5, 3, 1};

int min(int b, int c)
{
  if (b < c)
    return b;
  else
    return c;
}


int main()
{
  int i;
  int space, space2, extra;
  int twobytwo, onebyone;
  int num;
  while(1)
  {
    
    for(i = 0; i <= 5; i++)
      cin >> a[i];
    
    
    if(a[0] + a[1] + a[2] + a[3] + a[4] + a[5] == 0)
      break;
    
    num = a[3] + a[4] + a[5] + ceil(a[2]/4.0);
    space = 5 * a[3] + lefts[a[2]%4];
    
    
    twobytwo = min(space, a[1]);
    extra = ceil((a[1] - twobytwo)/18.0);
    num += extra;
    
    space = num * 36 - (4 * a[1] + 9 * a[2] + 16 * a[3] + 25 * a[4] + 36 * a[5]);
    onebyone = min(space, a[0]);
    extra = ceil((a[0] - onebyone)/36.0);
    num += extra;
    
    
    
    cout << num << endl;
    
  }// while(1)
  
  return 0;
}