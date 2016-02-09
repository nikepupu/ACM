#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


bool check(bool *used)
{
  for (int i = 0; i < 10; i++)
  {
    if (used[i] == 0)
      return false;
  }
  
  return true;
}

int main()
{

  
  long num, temp, temp2, k, initial;
  bool used[10]={0};
  while(cin >> initial)
  {
    
    k = 1;
    while(!check(used))
    {
      num =  k * initial;
      temp = num;
      temp2 = num;
      while(temp)
      {
        temp2 %= 10;
        temp /=10;
        used[temp2] = 1;
        temp2 = temp;
      }
      
      k++;
    }
  
    k--;
    cout <<k << endl;
    memset(used, 0, sizeof(used));
  }
  return 0;
}