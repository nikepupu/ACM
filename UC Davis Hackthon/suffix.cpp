#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;



int main()
{
  int an, bn, i,j, key,count = 0;
  
  
  cin >> an >> bn;
  int *a = new int[an];
  int *test = new int[an]();
  
  
  for (i = 0; i < an; i++)
  {
    cin>> a[i];
  }
  
  for (i = an-1; i > -1; i--)
  {
    
    for (j = an-1; j > i; j--)
    {
      if (a[j] == a[i])
        break;
    }
    
    if (i == j)
      count++;
    
    test[i] = count;
    
  }
    

  while(bn--)
  {
    cin>> key;
    cout << test[key-1]<<endl;
  }
  
  

  return 0;
}