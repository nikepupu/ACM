#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;
int num1[100005];
int num2[100005];
int prime[100005];
int len[100005];
int main()
{
  int n, p, a,b, i;
  int c= 0;
  long double sum = 0;
 
  cin >> n >> p;
  while(n--)
  {
    cin >> num1[c] >> num2[c];
  
    len[c] = num2[c] - num1[c] + 1;
    prime[c] = len[c] - (num2[c]/p - (num1[c]-1)/p);
    c++;
  }
  
  len[c] = len[0];
  num1[c] = num1[0];
  num2[c]= num2[0];
  prime[c] = len[c] - (num2[c]/p - (num1[c]-1)/p);
  
  for ( i = 0; i < c; i++)
  {
    sum +=  2000.0 * (1.0 - 1. *prime[i] /len[i] * prime[i+1]/len[i+1]);
    
  }

  
        cout << fixed << setprecision(14)<<sum;
  return 0;
}