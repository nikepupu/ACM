#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

char hello[] = {"hello"};
char world[] = {"world"};


int main()
{
  char str[1000000];
  short a[100],b[100];
  int a1, b1, count = 0, last = 0, lastIndex=0;
  int i, j;
  cin>>str;
  int len = strlen(str);
  
  
  for (i = 0; i< len; i++)
  {
    if (strncmp(str+i, world, 5) == 0)
    {
      b[b1++] = i;
    }
    
    else if (strncmp(str+i, hello, 5) == 0)
    {
      a[a1++] = i;
    }
    
  }
  for (j = 0; j < b1; j++)
  {
    count += last;
    for (i = lastIndex; i < a1; i++)
    {
      if (a[i] < b[j])
        count++;
      else
        break;
      
    }
    
    last = count;
    lastIndex = i;
    
  }
  
  
  cout << count;
  return 0;
}