#include <iostream>

using namespace std;

int main()
{
  int x, y, m, n, L, count = 0;;
  int initx, inity;
  cin >> x >> y >> m >> n >> L;
  initx = x;
  inity = y;
  
  while(1)
  {
    
    if (x == y)
    {
      cout<< count << endl;
      break;
    }
    
    x = (x +m < L)?(x + m): (x + m - L);
    y = (y +n < L)? (y + n) : (y + n - L);
    count++;
    
  
    if(x == initx && y == inity)
    {
      cout << "Impossible\n";
      break;
    }
    
  }

  return 0;
}