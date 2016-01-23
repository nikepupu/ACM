#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


int main()
{
  int n;
  short len;
  char num[20];
  char str[20];
  
  cin >> n;
  cin >> num;
  len = strlen(num);
  n--;
  
  while(n--)
  {
    cin >> str;
    while(strncmp(num, str, len) != 0)
    {
      len --;
    }

  }

  cout << len;
  
  

  return 0;
}