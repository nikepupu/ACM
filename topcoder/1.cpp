#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
  char a[256];
  int i,j;
  cin >> a;
  int front, back;
  int diff = -1;
  int status;
  
  int n = strlen(a);
  
  for (i = 0; i < n; i++)
  {
    status = 0;
    for(j = n-1; j > i; j--)
    {
    
      if (a[i] != a[j] )
      {
        status = 1;
        break;
      
      }
      
    }
    if(status == 1 && j - i > diff)
    {
      diff = j-i;
    }
    
  }
  
  cout << diff;

  return 0;
}