#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int a[200000]={0}, b[2100000]= {0};
int x,y;
int main()
{
  int n, x, y, count1 = 0,count2 = 0, count = 0;
  int sum = 0;
  int m;
  cin >> n;
  
  int i = 0;
  while(n--)
  {
    
    cin >> x >> y;
    sum += a[x+y] + b[x-y+10000];
    a[x+y]++;
    b[x-y+10000]++;
    i++;
  }
  cout << sum;

  return 0;
}