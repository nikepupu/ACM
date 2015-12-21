#include <iostream>
#include <cstdlib>
#include <cstring>


using namespace std;


int main()
{
  int n, k, i= 0, j, num;
  char c;
  char phoneBook[100000][9];
  bool duplicates = 0;
  
  

  
  cin >> n;
  num = n;
  cin.get();
  while(n>=1)
  {
    k = 0;
    while( cin.get(c) && c != '\n' )
    {
      if(c == '-') continue;
      
      if (c >= 'A' && c <= 'C')
        c = '2';
      else if (c >= 'D' && c <= 'F')
        c = '3';
      else if (c >= 'G' && c <= 'I')
        c = '4';
      else if (c >= 'J' && c <= 'L')
        c = '5';
      else if (c >= 'M' && c <= 'O')
        c = '6';
      else if (c >= 'P' && c <= 'S')
        c = '7';
      else if (c >= 'T' && c <= 'V')
        c = '8';
      else if (c >= 'W' && c <= 'Z')
        c = '9';
      
      if (k == 3)
        phoneBook[i][k++] = '-';
        
      phoneBook[i][k++] = c;
      
    }
    phoneBook[i][k] = '\0';

    
    i++;
    n--;
  }
  
  qsort(phoneBook, i, 9, (int (*)(const void *, const void *))strcmp);
  
  
  
  for( i = 0; i < num; i++)
  {
    for (j = i+1; j< num && strcmp(phoneBook[i], phoneBook[j]) == 0 ; j++);
    if(j - i > 1)
    {
      cout << phoneBook[i] << " " << j - i << endl;;
      i = j - 1;
      duplicates = 1;
    }
    
    
  }
  

  
  if (duplicates == 0)
    cout << "No duplicates.\n";
  
  
  return 0;
}
