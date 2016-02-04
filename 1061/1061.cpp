#include <iostream>

using namespace std;

int dd;
int i = 0;
void gcd(int a, int b, int &x, int &y)
{
  if (b == 0)
  {
    dd = a;
    x = 1;
    y = 0;
    return;
  }
  else gcd(b, a % b,x,y);
  
  int temp = x;
  x = y;
  y = temp- a/b * y ;
  
  return;
}

int main()
{
  int x, y, m, n, L;
  cin >> x >> y >> m >> n >> L;
  int b = n-m, a = L, d = y-x;
  int xx, yy;
  gcd(a,b, xx, yy);
  
  if ( (y-x) %dd != 0){
    cout << "Impossible"<<endl;
    return 0;
  }
  int k = (y-x)/dd;
  yy  = (yy *k % k + k)%k;
  cout << yy<<endl;
  
  

  return 0;
}