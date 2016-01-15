#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define REAL 10
using namespace std;

const char *status[3] = {"up", "down", "even"};

int test[12];// 0 real, 1 heavy, -1 light, 10,REAL


int findType(char *str)
{
  for (int i = 0; i < 3; i++)
  {
    if (strcmp(str, status[i]) == 0)
      return i;
  }
  
  return -1;
}


void update(char *p1, char *p2, int type)
{
  int i;
  
  int len = strlen(p1);
  if (type == 2)
  {
    for (i = 0; i < len; i++)
    {
      test[p1[i]-65] = REAL;
      test[p2[i]-65] = REAL;
    }
  }
  
  else if (type == 1)
  {
    for (i = 0; i < len; i++)
    {
      if (test[p1[i]-65] != REAL)
      {
            test[p1[i]-65]-- ;
      }
      
      if (test[p2[i]-65] != REAL)
      {
          test[p2[i]-65]++ ;
      }
    }
  }

  else if (type == 0)
  {
    for (i = 0; i < len; i++)
    {
      if (test[p1[i]-65] != REAL)
      {
        
          test[p1[i]-65]++ ;
        
      }
      
      if (test[p2[i]-65] != REAL)
      {
          test[p2[i]-65]-- ;
      }
    }
  }
  
  
}

int main()
{
  int num, type,max;
  char *p1, *p2, *p3;
  char str[256];
  

  
  cin >> num;
  cin.get();
  while(num--)
  {
    
    memset(test, 0, sizeof(test));

    
    for(int i = 0; i < 3; i++)
    {
      
      cin.getline(str,256);

      p1 = strtok(str, " ");
      p2 = strtok(NULL, " ");
      p3 = strtok(NULL, "");
      
      
      type = findType(p3);
      update(p1, p2, type);
    }

    
    for (int i = 0;i < 12; i++)
      if(test[i]!= REAL)
      {
        max = i;
        break;
      }
    
    
    for (int i = max+1; i < 12; i++)
    {
      if (test[i] == REAL)
        continue;
      if (abs(test[i]) > abs(test[max]) )
        max = i;
      
    }
      
      
    if (test[max] > 0)
      cout << char(max+65)<<" is the counterfeit coin and it is heavy.\n";
    else if (test[max] < 0)
      cout << char(max+65)<<" is the counterfeit coin and it is light.\n";
    
      
    
    
  }
  return 0;

}