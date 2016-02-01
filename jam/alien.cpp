#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <cctype>

using namespace std;

int L,D,N;
char dic[5000][16];
char list[15][26];

char str[1024];

int main()
{
  cin >> L >> D >> N;
  int temp = D, i, j;
  
  int count = 0, t = 1;
  while(temp--)
  {
    cin >> dic[count++];
    //cout << dic[count-1]<<endl;
  }
  
  
  temp = N;
  
  while(temp--)
  {
    cin >> str;
    
    int count = 0;
    memset(list, 0, sizeof(list));
    for (int i = 0; i < strlen(str); i++)
    {
      if (islower(str[i]))
      {
        list[count][str[i] - 'a'] = 1;
        count++;
      }
      else{
        i++;
        while(str[i] != ')')
        {
          list[count][str[i++] - 'a'] = 1;
        }
        count++;
      }
    }
    
    count = 0;
    for (i = 0; i < D; i++)
    {
      for (j = 0; j < L; j++)
      {
        if (list[j][dic[i][j] - 'a'] == 0)break;
      }
      if ( j == L)
        count++;
    }
    
    cout << "Case #" << t++ << ": "<< count<<endl;
  }
  
  return 0;
}
