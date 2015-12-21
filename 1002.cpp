#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>


using namespace std;


int main()
{
  int start = clock(), end;
  int n, k, i= 0, j, num, minIndex, temp;
  char c;
  char phoneBook[1024][32];
  char tempString[32];
  bool duplicates = 1;
  int repetition[1024] = {0};
  
  

  
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
      
      phoneBook[i][k++] = c;
      
    }
   // cout << phoneBook[i] << endl;
    phoneBook[i][k] = '\n';

    i++;
    n--;
  }
  
  for (i = 0; i < num; i ++)
  {
    minIndex = i;
  
    for(j = i; j < num; j++)
    {
      if( strcmp(phoneBook[minIndex], phoneBook[j]) > 0 )
      {
        minIndex = j;
      }
    }
    
    strcpy(tempString, phoneBook[minIndex]);
    
    strcpy(phoneBook[minIndex], phoneBook[i]);
    
    strcpy(phoneBook[i], tempString);
    
  }
  
  for( i = 0; i < num; i++)
  {
    for(j = i; strcmp(phoneBook[i], phoneBook[j]) == 0; j++);
    if (j - i > 0)
    {
      for( k = 0; k < 3; k++)
        cout << phoneBook[i][k];
      cout << '-';
      for ( k = 3; k < 7; k++)
        cout << phoneBook[i][k];
      
      cout << " " << j - i + 1 << endl;
      duplicates = 1;
      
    }
    
  }
  
  
  if (duplicates == 0)
    cout << "No duplicates.\n";
  
  end = clock();
  
  cout << "time: " << (end - start)/CLOCKS_PER_SEC<<endl;

  
  

  return 0;
}
